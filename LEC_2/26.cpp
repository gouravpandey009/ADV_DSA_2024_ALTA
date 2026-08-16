class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // i points to the last unique element
        int i = 0;

        // j scans the array
        for (int j = 1; j < nums.size(); j++) {

            // New unique element found
            if (nums[j] != nums[i]) {

                i++;

                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

