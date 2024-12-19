#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

// Class that encapsulates string reversal logic
class StringReverser {
private:
    string str;

public:
    // Constructor to initialize string
    StringReverser(const string &input) : str(input) {}

    // Method to reverse the string using manual pointer arithmetic
    void reversePointerArithmetic() {
        char* start = &str[0];
        char* end = &str[str.length() - 1];

        while (start < end) {
            swap(*start, *end);
            ++start;
            --end;
        }
    }

    // Method to reverse the string using multithreading (splitting the work)
    void reverseMultithreaded() {
        int n = str.length();
        if (n <= 1) return;

        // Create two threads for reversing the string in parallel
        thread t1(&StringReverser::reversePart, this, 0, n / 2 - 1);
        thread t2(&StringReverser::reversePart, this, n / 2, n - 1);

        // Wait for threads to finish
        t1.join();
        t2.join();
    }

    // Helper method to reverse part of the string using pointers
    void reversePart(int start, int end) {
        char* left = &str[start];
        char* right = &str[end];

        while (left < right) {
            swap(*left, *right);
            ++left;
            --right;
        }
    }

    // Method to reverse the string using C++ Standard Library reverse
    void reverseWithSTL() {
        reverse(str.begin(), str.end());
    }

    // Method to display the string
    void display() const {
        cout << "Reversed String: " << str << endl;
    }
};

int main() {
    string input;

    // User input for the string
    cout << "Enter a string to reverse: ";
    getline(cin, input);

    // Create a StringReverser object
    StringReverser reverser(input);

    // Display the original string
    cout << "Original String: " << input << endl;

    // Reverse using pointer arithmetic
    StringReverser pointerReverser(input);
    pointerReverser.reversePointerArithmetic();
    pointerReverser.display();

    // Reverse using multithreading
    StringReverser multiReverser(input);
    multiReverser.reverseMultithreaded();
    multiReverser.display();

    // Reverse using STL reverse
    StringReverser stlReverser(input);
    stlReverser.reverseWithSTL();
    stlReverser.display();

    return 0;
}
