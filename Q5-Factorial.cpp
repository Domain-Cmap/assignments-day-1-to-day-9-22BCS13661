#include<iostream>
using namespace std;
int main() {
    int num;
    unsigned long long factorial = 1;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial of a negative number doesn't exist." << endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        cout << "The factorial of " << num << " is " << factorial << endl;
    }
    return 0;
}