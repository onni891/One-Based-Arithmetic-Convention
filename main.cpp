#include <iostream>
#include <cstdio>
#include <cstring>

// Define a type alias for long long to make the code more readable
#define ll long long

using namespace std;

ll n;          // Input number
ll f[18];     // Array to store "one-numbers" (1, 11, 111, etc.)

// Recursive function to calculate the minimum number of ones
int cal(ll x) {
    int res, i = 16;

    // Base case: for small numbers, calculate directly
    if (x <= 11) {
        return min(x, 2 + 11 - x); // Either x ones, or cost of 11 plus the difference
    }

    // Find the largest "one-number" less than or equal to x
    while (f[i - 1] > x) {
        i--;
    }

    // Calculate the cost using the current "one-number" and the remainder
    res = ((x / f[i - 1]) * (i - 1)) + cal(x % f[i - 1]);

    // Check if subtracting from the next larger "one-number" is better
    if (x < f[i] - x) {
        return res; // If not, return the current result
    }

    return min(res, i + cal(f[i] - x)); // Otherwise, compare and return the minimum
}

int main() {
    // Initialize the "one-numbers" array
    f[1] = 1;
    for (int i = 2; i <= 16; i++) {
        f[i] = 10 * f[i - 1] + 1;
    }

    // Prompt for input
    cout << "Enter Input: "; // Changed this line

    // Read the input
    scanf("%I64d", &n);  // or cin >> n;

    // Echo the input (optional, but good practice)
    cout << "Input: " << n << endl; // Added this line

    // Calculate and print the result
    cout << "Output: " << cal(n) << endl; // Changed this line

    return 0;
}
