class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Har number kitni baar aaya,
        // uski frequency store karenge.
        unordered_map<int, int> frequency;

        for (int number : arr) {

            // Current number ki frequency 1 se increase karo
            frequency[number]++;
        }
        
        // Ye set already seen frequencies store karega.
        unordered_set<int> seenFrequencies;

        // Frequency map ke andar jaakar
        // har frequency check karenge.
        for (auto& pair : frequency) {

            // pair.second = current number ki frequency
            int currentFrequency = pair.second;

            // Agar ye frequency pehle hi mil chuki hai,
            // toh frequencies unique nahi hain.
            if (seenFrequencies.count(currentFrequency)) {
                return false;
            }

            // Frequency ko set mein store kar do.
            seenFrequencies.insert(currentFrequency);
        }

        // Agar koi duplicate frequency nahi mili,
        // toh answer true hai.
        return true;
    }
};