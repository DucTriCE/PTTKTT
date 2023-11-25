#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << endl;
    }
}

void generatePermutations(vector<int>& nums, int start, vector<bool>& used) {
    if (start == nums.size()) {
        output(nums);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            generatePermutations(nums, start + 1, used);
            used[i] = false;
        }
    }
}

int main() {
	freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    string n;
    cin >> n;

    vector<int> nums;
    for (char digit : n) {
        nums.push_back(digit - '0');
    }

    sort(nums.begin(), nums.end(), greater<int>());
    vector<bool> used(nums.size(), false);

    generatePermutations(nums, 0, used);

    return 0;
}