#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0
    int i = 1;

    // Loop calculates lps[i] for i = 1 to pattern.size() - 1
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            // If mismatch after length matches
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Print the lps array
    cout << "LPS array: ";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
}

// KMP pattern matching
void KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // lps[] -> It will hold the longest prefix suffix values for pattern
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    cout<<"KMPSearch: "<<endl;

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {

    string text, pattern;

    // Taking input of text and pattern from the user
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // KMP search
    KMPSearch(text, pattern);

    // Printing the index and character of the text for better understanding
    cout<<"Character and corresponding index of the text: "<<endl;
    for(int i=0; i<text.size(); i++){
        cout<<text[i]<<" "<<i<<endl;
    }
    cout<<endl;

    return 0;
}

// Testcase:
// bacbababaabcbababacaabcbababacababacababaca
// ababaca