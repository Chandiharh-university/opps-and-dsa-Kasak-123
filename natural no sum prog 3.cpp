#include <iostream>
using namespace std;

// Iterative approach to calculate sum of natural numbers
int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

// Recursive approach to calculate sum of natural numbers
int sumRecursive(int n) {
    if (n == 0) return 0;  // Base case
    return n + sumRecursive(n - 1);
}

int main() {
    int n;
    
    // Input number of natural numbers
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer!" << endl;
        return 1;
    }

    // Calculate sum using iterative approach
    cout << "Sum using iterative approach: " << sumIterative(n) << endl;

    // Calculate sum using recursive approach
    cout << "Sum using recursive approach: " << sumRecursive(n) << endl;

    return 0;
}
