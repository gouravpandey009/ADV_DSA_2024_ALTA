//brute force 

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // Choose starting index
        for (int i = 0; i < n; i++) {

            int sum = 0;

            // Extend subarray
            for (int j = i; j < n; j++) {

                sum += nums[j];

                // Length must be at least 2
                if (j - i + 1 >= 2 && sum % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};


//optimal - prefix sum + remainder

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // remainder -> first index where it appeared
        unordered_map<int, int> mp;

        // Sum = 0 before array starts
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Add current number
            sum += nums[i];

            // Calculate remainder
            int remainder = sum % k;

            // Have we seen this remainder before?
            if (mp.find(remainder) != mp.end()) {

                int previousIndex = mp[remainder];

                // Subarray length must be at least 2
                if (i - previousIndex >= 2) {
                    return true;
                }
            }
            else {

                // Store only the FIRST occurrence
                mp[remainder] = i;
            }
        }

        return false;
    }
};
