#include <iostream>

using namespace std;


/** Check if an integer is a palindrome.
    @param x The integer to check.
    @return True if x is a palindrome, false otherwise.
 */
bool is_palindrome(int x) {
    if(x < 0 || ((x != 0) && (x % 10 == 0))) {
        return false;
    } else {
        int check = 0;
        while(x > check) {
            check = check * 10 + (x % 10);
            x /= 10;
        }
        return (((x == check) || (x == check / 10)) ? true : false);
    }
}

int main() {
    int x;

    cout << "Enter an integer: ";
    cin >> x;

    if (is_palindrome(x)) {
        cout << x << " is a palindrome number." << endl;
    } else {
        cout << x << " is NOT a palindrome number." << endl;
    }

    return 0;
}