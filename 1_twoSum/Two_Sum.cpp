#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           
            vector<int> result;
            // Step 1: Create a map to store numbers and their indices.
            unordered_map<int, int> map;
            // Step 2: During iteration over the numbers, the complement is calculated for each number.
            for (size_t i = 0; i < nums.size(); i++) {
                int current = nums.at(i); // current + complement = target
                int complement = target - nums[i]; // Find the complement
                // Step 3: It checks if the complement exists in the map. If so, the indices are returned.
                if (map.count(complement)) {
                    result.push_back(map.at(complement));
                    result.push_back(i);
                    return result;
                }
                // Step 4: Otherwise, the current number and its index are added to the map.
                map[current] = i;
            }
            // Step 5: If no pair sums up to the target, return an empty vector.
            return result;   
        }
};

int main() {
    size_t size;
    int target;
    vector<int> nums;

    cout << "Enter number of elements in nums: ";
    cin >> size;

    cout << "Enter " << size << " integers for nums: ";
    for (size_t i = 0; i < size; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << "Enter the target: ";
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}