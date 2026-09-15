class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int freq1[26] = {};
        int freq2[26] = {};

        // Count characters of s1.
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int k = s1.size();

        // Create a window of size k in s2.
        for (int i = 0; i < s2.size(); i++) {

            // Add current character.
            freq2[s2[i] - 'a']++;

            // Keep window size equal to k.
            if (i >= k) {
                freq2[s2[i - k] - 'a']--;
            }

            // Check the window after it becomes size k.
            if (i >= k - 1) {

                bool same = true;

                for (int j = 0; j < 26; j++) {
                    if (freq1[j] != freq2[j]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    return true;
            }
        }

        return false;
    }
};