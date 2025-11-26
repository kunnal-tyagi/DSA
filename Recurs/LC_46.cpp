#include <iostream>
#include <vector>
using namespace std;

void compute(vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums, vector<int>& freq) {
    if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
            freq[i] = 1;
            ds.push_back(nums[i]);
            compute(ans, ds, nums, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);

    compute(ans, ds, nums, freq);

    // print result
    for (auto& v : ans) {
        for (auto& x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
