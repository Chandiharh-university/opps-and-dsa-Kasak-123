#include <iostream>
#include <string>
#include <algorithm>  // For std::reverse
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    string cleanedStr = str;
    
    // Remove non-alphanumeric characters and convert to lowercase
    cleanedStr.erase(remove_if(cleanedStr.begin(), cleanedStr.end(),
        [](char c) { return !isalnum(c); }), cleanedStr.end());
    
    transform(cleanedStr.begin(), cleanedStr.end(), cleanedStr.begin(), ::tolower);

    // Check if the cleaned string is equal to its reverse
    string reversedStr = cleanedStr;
    reverse(reversedStr.begin(), reversedStr.end());
    
    return cleanedStr == reversedStr;
}

int main() {
    string str;
    
    // Input the string
    cout << "Enter a string: ";
    getline(cin, str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
