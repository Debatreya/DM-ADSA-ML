#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A, std::vector<int>& B) {
    int n = A.size();
    if (n == 0) return 0;

    std::vector<int> dp_top(n, 0), dp_bottom(n, 0);

    // Initialize the starting points
    dp_top[0] = A[0];
    dp_bottom[0] = A[0] + B[0];

    // Fill the dp arrays
    for (int i = 1; i < n; ++i) {
        dp_top[i] = std::max(dp_top[i - 1], dp_bottom[i - 1]) + A[i];
        dp_bottom[i] = std::max(dp_top[i], dp_bottom[i - 1]) + B[i];
    }

    // The answer will be the maximum value in dp_bottom[n-1]
    return dp_bottom[n - 1];
}

int main() {
    // Test case 1
    std::vector<int> A1 = {3, 4, 6};
    std::vector<int> B1 = {6, 5, 4};
    std::cout << "Test case 1 result: " << solution(A1, B1) << std::endl; // Expected: 5

    // Test case 2
    std::vector<int> A2 = {1, 2, 1, 1, 1, 4};
    std::vector<int> B2 = {1, 1, 1, 3, 1, 1};
    std::cout << "Test case 2 result: " << solution(A2, B2) << std::endl; // Expected: 2

    // Test case 3
    std::vector<int> A3 = {-5, -1, -3};
    std::vector<int> B3 = {-5, 5, -2};
    std::cout << "Test case 3 result: " << solution(A3, B3) << std::endl; // Expected: -1

    return 0;
}