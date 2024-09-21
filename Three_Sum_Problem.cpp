#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int left = i + 1, right = nums.size() - 1; left < right;) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[++left]);
                while (left < right && nums[right] == nums[--right]);
            } else (sum < 0 ? left++ : right--);
        }
    }
    return result;
}

int main() {
    vector<int> nums;
    int n, item;
    cout << "Enter number of elements: ";
    cin >> n;
    while (n--) {
        cin >> item;
        nums.push_back(item);
    }

    for (const auto& triplet : threeSum(nums))
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";

    return 0;
}
