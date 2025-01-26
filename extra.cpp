#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int solution(std::string &S, std::string &T) {
    int n = S.length();
    std::vector<int> differences(n);

    // Calculate initial differences
    for (int i = 0; i < n; ++i) {
        differences[i] = abs(S[i] - T[i]);
    }
    int totalDifference = 0;
    for (int diff : differences) {
        totalDifference += diff;
    }
    if (totalDifference == 0) {
        return 0;  // No swaps needed if there's no difference
    }
    int swapCount = 0;
    // Sort differences in descending order to prioritize larger differences
    std::sort(differences.rbegin(), differences.rend());
    // Perform swaps until the difference is minimized
    for (int diff : differences) {
        if (totalDifference <= 0) break;
        totalDifference -= 2 * diff;  // Each swap reduces this difference
        swapCount++;
    }
    return swapCount;
}

int main() {
    std::string S, T;
    std::cin >> S;
    std::cin >> T;

    int result = solution(S, T);
    std::cout << result << std::endl;

    return 0;
}