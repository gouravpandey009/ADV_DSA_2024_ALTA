//brute force

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        // Choose every starting index.
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            int ones = 0;

            // Extend the subarray.
            for (int j = i; j < n; j++) {

                if (nums[j] == 0) {
                    zeros++;
                } else {
                    ones++;
                }

                // If both counts are equal,
                // update the maximum length.
                if (zeros == ones) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};


//optimal

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;

        int sum = 0;
        int maxLen = 0;

        // Prefix sum 0 exists before the array starts.
        firstIndex[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            // Treat 0 as -1 and 1 as +1.
            if (nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }

            // Same prefix sum found before.
            if (firstIndex.count(sum)) {

                int length = i - firstIndex[sum];

                maxLen = max(maxLen, length);

            } else {

                // Store only the FIRST occurrence.
                firstIndex[sum] = i;
            }
        }

        return maxLen;
    }
};