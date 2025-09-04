#include <iostream>
#include <climits> 

using namespace std;

class Solution {
public:
    int reverse(int num) {
        int result = 0; // Initialize result to store the reversed number
        
        // Process each last digit of the number
        while (num) {
            int digit = num % 10; // Extract the last digit
            num /= 10; // Remove the last digit from the number

            // Check for overflow/underflow before updating result
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) { // 7 is the last digit of INT_MAX
                return 0; 
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) { // -8 is the last digit of INT_MIN
                return 0; 
            }

            result = result * 10 + digit; // Update result with the new digit
        }

        return result; 
    }
};

int main() {
    int num_1 = 123, num_2 = -123, num_3 = 120;
    Solution solution;

    cout << num_1 << " reversed is " << solution.reverse(num_1) << endl;
    cout << num_2 << " reversed is " << solution.reverse(num_2) << endl;
    cout << num_3 << " reversed is " << solution.reverse(num_3) << endl;
    
    system("pause");
    return 0;
}