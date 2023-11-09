#include <iostream>
using namespace std; // Added to fix "cout" and "cin" errors
// Function to calculate and print the Fibonacci series up to n using a non-recursive approach
void fibonacciNonRecursiveSeries(int n) {
    int prev = 0, curr = 1;
    cout << "Fibonacci series up to " << n << " (non-recursive): ";
    for (int i = 0; i <= n; ++i) {
        cout << prev << " ";
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    cout << endl;
}
// Function to calculate the nth Fibonacci number using a recursive approach
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    // Recursive call with time complexity O(2^n)
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
// Function to print the Fibonacci series up to n using a recursive approach
void fibonacciRecursiveSeries(int n) {
    cout << "Fibonacci series up to " << n << " (recursive): ";
    for (int i = 0; i <= n; ++i) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    // Calculate and display the Fibonacci series up to n using the non-recursive approach
    fibonacciNonRecursiveSeries(n);
    cout << "Time complexity for the non-recursive approach: O(n)" << endl;
    cout << "Space complexity for the non-recursive approach: O(1)" << endl;
    // Calculate and display the Fibonacci series up to n using the recursive approach
    fibonacciRecursiveSeries(n);
    cout << "Time complexity for the recursive approach: O(2^n)" << endl;
    cout << "Space complexity for the recursive approach: O(n)" << endl;    
    return 0;
}

