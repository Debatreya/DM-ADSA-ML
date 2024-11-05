#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp algorithm for pattern matching
void rabinKarp(string text, string pattern, int q) {
    int d = 256; // Number of characters in the input alphabet
    int n = text.length();
    int m = pattern.length();
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of the pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            // If the hash values and characters match
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Convert negative value of t to positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    string text, pattern;
    int q;

    // Taking user input
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    cout << "Enter the prime number (q): ";
    cin >> q;

    // Rabin-Karp algorithm
    rabinKarp(text, pattern, q);

    return 0;
}

// Test case:
// Enter the text: AABAACAADAABAABA
// Enter the pattern to search: AABA
// Enter the prime number (q): 101