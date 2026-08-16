class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            // Calculate the sum of the current pair.
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return {left + 1, right + 1};
            }

            if (currentSum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};