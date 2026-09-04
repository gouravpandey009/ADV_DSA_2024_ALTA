//brute force

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        // Choose every possible starting index.
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Extend the subarray one element at a time.
            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

//optimal

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int sum = 0;
        int ans = 0;

        // Empty prefix has sum 0 and occurs once.
        freq[0] = 1;

        for (int num : nums) {
            // Current prefix sum.
            sum += num;

            // Previous prefix sum needed to make a subarray sum of k.
            if (freq.count(sum - k)) {
                ans += freq[sum - k];
            }

            // Store the current prefix sum for future subarrays.
            freq[sum]++;
        }

        return ans;
    }
};

