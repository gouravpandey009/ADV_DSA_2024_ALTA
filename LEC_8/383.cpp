//brute force

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // Try to find every required character in magazine.
        for (char ch : ransomNote) {
            bool found = false;

            for (int i = 0; i < magazine.size(); i++) {
                
                // Use only an unused matching character.
                if (magazine[i] == ch) {
                    magazine[i] = '#';
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};


//optimal

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {};

        // Count how many times each character is available.
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Use characters required by the ransom note.
        for (char ch : ransomNote) {
            
            // No copy of this character is left.
            if (freq[ch - 'a'] == 0) {
                return false;
            }

            freq[ch - 'a']--;
        }

        return true;
    }
};
