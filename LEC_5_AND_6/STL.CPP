#include <bits/stdc++.h>
using namespace std;

int main() {

    // Vector stores all marks
    vector<int> marks = {
        50, 80, 70, 80, 90, 50, 100
    };

    // --------------------------------
    // 1. Print all marks
    // --------------------------------

    cout << "Marks: ";

    for(int x : marks) {
        cout << x << " ";
    }

    cout << endl;


    // --------------------------------
    // 2. Sort marks
    // --------------------------------

    sort(marks.begin(), marks.end());

    cout << "Sorted: ";

    for(int x : marks) {
        cout << x << " ";
    }

    cout << endl;


    // --------------------------------
    // 3. Find maximum
    // --------------------------------

    int maximum = *max_element(
        marks.begin(),
        marks.end()
    );

    cout << "Maximum: "
         << maximum << endl;


    // --------------------------------
    // 4. Frequency using HashMap
    // --------------------------------

    unordered_map<int, int> freq;

    for(int x : marks) {

        // Increase frequency of x
        freq[x]++;
    }

    cout << "Frequencies:\n";

    for(auto &[mark, count] : freq) {

        cout << mark
             << " -> "
             << count
             << endl;
    }


    // --------------------------------
    // 5. Search an element
    // --------------------------------

    if(find(marks.begin(),
            marks.end(),
            70) != marks.end()) {

        cout << "70 exists\n";
    }


    // --------------------------------
    // 6. Unique marks using set
    // --------------------------------

    set<int> uniqueMarks(
        marks.begin(),
        marks.end()
    );

    cout << "Unique marks: ";

    for(int x : uniqueMarks) {

        cout << x << " ";
    }

    cout << endl;


    return 0;
}