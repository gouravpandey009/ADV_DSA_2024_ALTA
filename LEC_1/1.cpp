class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;

        // Process each element exactly once.
        for (int currentIndex = 0; currentIndex < static_cast<int>(nums.size()); ++currentIndex) {
            int currentValue = nums[currentIndex];

            // If currentValue + complement = target,
            // then complement = target - currentValue.
            int complement = target - currentValue;.
            auto iterator = valueToIndex.find(complement);

            if (iterator != valueToIndex.end()) {
                return {iterator->second, currentIndex};
            }

            valueToIndex[currentValue] = currentIndex;
        }

        return {};
    }
};

//time complexity: O(n), where n is the number of elements in the input vector nums. Each element is processed exactly once, and the unordered_map provides average O(1) time complexity for insertions and lookups.
//space complexity: O(n), where n is the number of elements in the input vector nums. In the worst case, all elements are stored in the unordered_map, which requires additional space proportional to the number of unique elements in nums.
