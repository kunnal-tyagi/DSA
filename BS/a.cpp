#include <iostream>
#include <vector>
using namespace std;

//lC-154 
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high])
            high = mid;
        else if (nums[mid] > nums[high])
            low = mid + 1;
            
// When nums[mid] == nums[high], both halves might contain the minimum,
// so we reduce the search space by one safely
        else
            high--; // handle duplicates
    }
    return nums[low];
}

int main() {
    vector<int> nums = {10, 2, 10, 10, 10};
    int n = findMin(nums);
    cout << n << endl; // Expected output: 2
    return 0;
}
