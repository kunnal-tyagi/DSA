int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;     // go right (increasing slope)
        else
            high = mid;        // go left (decreasing slope)
    }
    return low;  // low == high == peak index
}
