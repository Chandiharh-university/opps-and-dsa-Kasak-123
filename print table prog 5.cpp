#include <iostream>
using namespace std;

void printMultiplicationTable(int num, int limit) {
    for (int i = 1; i <= limit; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

int main() {
    int num, limit;
    
    // Input the number for which the table is to be printed
    cout << "Enter the number: ";
    cin >> num;
    
    // Input the limit up to which the table is to be printed
    cout << "Enter the limit: ";
    cin >> limit;
    
    // Print the multiplication table
    printMultiplicationTable(num, limit);
    
    return 0;
}
