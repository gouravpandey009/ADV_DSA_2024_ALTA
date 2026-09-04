//brute force

class Solution {
public:

    bool linearSearch(vector<int>& nums, int target) {

        for (int num : nums) {

            if (num == target) {
                return true;
            }
        }

        return false;
    }

    int longestConsecutive(vector<int>& nums) {

        int longest = 0;

        for (int num : nums) {

            int current = num;
            int count = 1;

            // Check current + 1, current + 2...
            while (linearSearch(nums, current + 1)) {

                current++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};


//optimal - hashset

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Step 1: Put all numbers in set
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        // Step 2: Check every number
        for (int num : st) {

            // Start sequence only if num-1 does not exist
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int count = 1;

                // Continue consecutive sequence
                while (st.find(current + 1) != st.end()) {

                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};