//bruteforce approach:

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Different length strings can never be isomorphic.
        if (s.size() != t.size()) {
            return false;
        }

        // We will store mappings manually.
        vector<pair<char, char>> mapping;

        for (int i = 0; i < s.size(); i++) {

            char a = s[i];
            char b = t[i];

            bool found = false;

            // Search whether 'a' already has a mapping.
            for (int j = 0; j < mapping.size(); j++) {

                if (mapping[j].first == a) {

                    found = true;

                    // Same character must always map
                    // to the same character.
                    if (mapping[j].second != b) {
                        return false;
                    }
                }

                // Another character cannot already map to b.
                if (mapping[j].second == b &&
                    mapping[j].first != a) {
                    return false;
                }
            }

            // If this is a new mapping, store it.
            if (!found) {
                mapping.push_back({a, b});
            }
        }

        return true;
    }
};

//time complexity: O(n^2), where n is the length of the input strings s and t. For each character in the strings, we may need to search through the mapping vector, which can grow up to size n in the worst case.
//space complexity: O(n), where n is the length of the input strings s and t. In the worst case, we may need to store a mapping for each character in the strings, which requires additional space proportional to the number of unique characters in s and t.



//optimal solution: hashing
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Both strings must have the same length.
        if (s.size() != t.size()) {
            return false;
        }

        // sToT[a] tells us which character 'a' maps to in t.
        vector<int> sToT(256, -1);

        // tToS[b] tells us which character 'b' maps back to in s.
        vector<int> tToS(256, -1);

        for (int i = 0; i < s.size(); i++) {

            int a = s[i];
            int b = t[i];

            // If 'a' already has a mapping,
            // it must be the same as the current character 'b'.
            if (sToT[a] != -1 && sToT[a] != b) {
                return false;
            }

            // If 'b' already belongs to another character,
            // the mapping is not one-to-one.
            if (tToS[b] != -1 && tToS[b] != a) {
                return false;
            }

            // Store the mapping in both directions.
            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};

//time complexity: O(n), where n is the length of the input strings s and t. We iterate through each character of the strings once, performing constant-time operations for each character.
//space complexity: O(1), since the size of the mapping arrays sToT and

