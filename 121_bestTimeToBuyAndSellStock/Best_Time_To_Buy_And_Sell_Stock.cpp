#include "Vector.h"

#include <climits>

using namespace std;

class Solution {
public:

    /** Calculate the maximum profit from stock prices.
     * @param prices: A vector of stock prices
     * @return int The maximum profit that can be achieved
     */
    int maxProfit(Vector<int>& prices) {
        int min_price = INT_MAX; // Tracks the lowest price
        int max_profit = 0; // Tracks the maximum profit
        
        // Iterate through the prices:
        for (size_t i = 0; i < prices.size(); ++i) {
            // If price smaller than min_price, update min_price
            if (prices.at(i) < min_price) {
                min_price = prices.at(i);
            } else if (prices.at(i) - min_price > max_profit) { // If current profit is higher
                max_profit = prices.at(i) - min_price; // Update max_profit 
            }
        }
        return max_profit;
    } // Time Complexity: O(n)
};

int main() {
    Solution solution;

    Vector<int> prices_1 = {7, 1, 5, 3, 6, 4};
    Vector<int> prices_2 = {7, 6, 4, 3, 1};
    Vector<int> prices_3 = {2, 4, 1};
    Vector<int> prices_4 = {3, 3, 5, 0, 0, 3, 1, 4};
    Vector<int> prices_5 = {1, 2};


    int max_profit_1 = solution.maxProfit(prices_1);
    int max_profit_2 = solution.maxProfit(prices_2);
    int max_profit_3 = solution.maxProfit(prices_3);
    int max_profit_4 = solution.maxProfit(prices_4);
    int max_profit_5 = solution.maxProfit(prices_5);

    cout << "Max Profit 1: " << max_profit_1 << endl;
    cout << "Max Profit 2: " << max_profit_2 << endl;
    cout << "Max Profit 3: " << max_profit_3 << endl;
    cout << "Max Profit 4: " << max_profit_4 << endl;
    cout << "Max Profit 5: " << max_profit_5 << endl;

    system("pause");
    return 0;
}

