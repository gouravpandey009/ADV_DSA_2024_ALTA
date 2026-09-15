class Solution {
public:
    int maxVowels(string s, int k) {

        int count = 0;
        int maxCount = 0;

        // First window ke k characters me vowels count karo
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        maxCount = count;

        // Window ko slide karo
        for (int i = k; i < s.length(); i++) {

            // New character window me add hua
            if (isVowel(s[i])) {
                count++;
            }

            // Window se purana character remove hua
            if (isVowel(s[i - k])) {
                count--;
            }

            // Maximum vowels update karo
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }

    // Check karta hai ki character vowel hai ya nahi
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }
};