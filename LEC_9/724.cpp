//brute force

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int leftSum = 0;
            int rightSum = 0;

            // Calculate left sum
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Calculate right sum
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};


//optimal

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        // Step 1: Calculate total sum
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Keep track of left sum
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Calculate right sum
            int rightSum = totalSum - leftSum - nums[i];

            // Check pivot condition
            if (leftSum == rightSum) {
                return i;
            }

            // Add current element for next iteration
            leftSum += nums[i];
        }

        return -1;
    }
};

