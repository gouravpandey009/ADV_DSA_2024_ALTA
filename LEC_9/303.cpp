//brute force

class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        // Add every element in the requested range.
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }

        return sum;
    }
};


//optimal - prefix sum

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);

        // prefix[i + 1] stores the sum from index 0 to i.
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // Remove the sum before 'left' from the sum till 'right'.
        return prefix[right + 1] - prefix[left];
    }
};


