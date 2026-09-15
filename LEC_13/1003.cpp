class Solution {
public:
    bool isValid(string s) {

        string st;

        for (char c : s) {

            st += c;

            // Last 3 characters are "abc".
            if (st.size() >= 3 &&
                st.substr(st.size() - 3) == "abc") {

                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
        }

        return st.empty();
    }
};