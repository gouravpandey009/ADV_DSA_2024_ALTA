//brute force approach

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = -1e9;

        // Try every possible window.
        for (int i = 0; i <= nums.size() - k; i++) {
            int sum = 0;

            // Calculate the sum of k elements.
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }

            double average = (double)sum / k;

            maxAverage = max(maxAverage, average);
        }

        return maxAverage;
    }
};

//optimal approach

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        // Find sum of the first k elements.
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window through the array.
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];  // Remove old element.
            sum += nums[i];      // Add new element.

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};

