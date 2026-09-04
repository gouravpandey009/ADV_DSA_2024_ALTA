//brute force
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // Try every possible first index.
        for (int i = 0; i < nums.size(); i++) {
            
            // Compare nums[i] with every element after it.
            for (int j = i + 1; j < nums.size(); j++) {
                
                // Same value and indices are within k distance.
                if (nums[i] == nums[j] && j - i <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};

//optimal 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {

            // If current number exists in the last k elements,
            // we found a valid nearby duplicate.
            if (seen.count(nums[i])) {
                return true;
            }

            // Add the current number to our window.
            seen.insert(nums[i]);

            // Remove the element that is now outside the window.
            if (i >= k) {
                seen.erase(nums[i - k]);
            }
        }

        return false;
    }
};

