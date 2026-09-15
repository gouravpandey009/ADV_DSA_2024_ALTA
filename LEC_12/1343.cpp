class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int sum = 0;
        int count = 0;

        // First window ka sum
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        // Check first window
        if (sum >= k * threshold) {
            count++;
        }

        // Slide the window
        for (int i = k; i < arr.size(); i++) {

            // New element add karo
            sum += arr[i];

            // Window ke bahar wala element remove karo
            sum -= arr[i - k];

            // Check current window
            if (sum >= k * threshold) {
                count++;
            }
        }

        return count;
    }
};