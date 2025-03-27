#include <iostream>
#include <vector>
#include <limits.h> // for INT_MIN and INT_MAX
#include <algorithm> // for max and min functions

using namespace std;

/** Finds the Median of Two Sorted Vectors.
    @param vec1 First sorted vector.
    @param vec2 Second sorted vector.
    @return The median of the two sorted vectors.
 */
double findMedianSortedArrays(vector<int>& vec1, vector<int>& vec2) {
    if (vec1.size() > vec2.size()) {
        return findMedianSortedArrays(vec2, vec1);
    }

    int m = vec1.size();
    int n = vec2.size();
    int low = 0, high = m;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;

        int first_left = (i == 0) ? INT_MIN : vec1[i - 1];
        int first_right = (i == m) ? INT_MAX : vec1[i];
        int second_left = (j == 0) ? INT_MIN : vec2[j - 1];
        int second_right = (j == n) ? INT_MAX : vec2[j];

        if (first_left <= second_right && second_left <= first_right) {
            if ((m + n) % 2 == 0) {
                return (max(first_left, second_left) + min(first_right, second_right)) / 2.0;
            } else {
                return max(first_left, second_left);
            }
        } else if (first_left > second_right) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0; // Should not reach here if inputs are valid
} // Complexity O(log(min(m, n))) for binary search, O(1) for finding median

int main() {
    int m, n, val;
    vector<int> vec1, vec2;

    cout << "Enter number of elements in first sorted array: ";
    cin >> m;
    cout << "Enter elements (sorted in non-decreasing order): ";
    for (int i = 0; i < m; ++i) {
        cin >> val;
        vec1.push_back(val);
    }

    cout << "Enter number of elements in second sorted array: ";
    cin >> n;
    cout << "Enter elements (sorted in non-decreasing order): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        vec2.push_back(val);
    }

    double median = findMedianSortedArrays(vec1, vec2);
    cout << "Median: " << median << endl;

    return 0;
}
