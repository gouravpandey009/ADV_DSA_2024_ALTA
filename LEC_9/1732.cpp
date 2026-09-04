class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        // We start at altitude 0
        int currentAltitude = 0;

        // Initially, highest altitude is also 0
        int maxAltitude = 0;

        // Process every altitude change
        for (int change : gain) {

            // Update current altitude
            currentAltitude += change;

            // Update maximum altitude if needed
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};

