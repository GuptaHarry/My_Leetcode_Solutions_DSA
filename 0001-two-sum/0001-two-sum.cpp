#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of pairs (value, index)
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});
        }

        // Sort the vector based on the value
        sort(numWithIndex.begin(), numWithIndex.end());

        // Two-pointer approach
        int start = 0, end = numWithIndex.size() - 1;
        while (start < end) {
            int sum = numWithIndex[start].first + numWithIndex[end].first;
            if (sum == target) {
                // Return the original indices of the two numbers
                return {numWithIndex[start].second, numWithIndex[end].second};
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        // Return an empty vector if no solution is found (shouldn't happen as per constraints)
        return {};
    }
};