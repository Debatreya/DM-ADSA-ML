#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to create the LPS (Longest Prefix Suffix) array
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
}

// Function that performs KMP pattern matching
void KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

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

    // Take input of text and pattern from the user
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Perform KMP search
    KMPSearch(text, pattern);

    return 0;
}