#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Function to recursively find min and max
void findMinMax(const vector<int>& arr, int left, int right, int& minVal,
                int& maxVal) {
    // Base case: only one element
    if (left == right) {
        minVal = maxVal = arr[left];
        return;
    }
    // Base case: two elements
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            minVal = arr[left];
            maxVal = arr[right];
        } else {
            minVal = arr[right];
            maxVal = arr[left];
        }
        return;
    }

    // Divide the array into two halves
    int mid = left + (right - left) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    findMinMax(arr, left, mid, leftMin, leftMax);
    findMinMax(arr, mid + 1, right, rightMin, rightMax);

    // Combine results
    minVal = (leftMin < rightMin) ? leftMin : rightMin;
    maxVal = (leftMax > rightMax) ? leftMax : rightMax;
}

// Wrapper function
vector<int> getMinMax(const vector<int>& arr) {
    if (arr.size() == 0) {
        throw invalid_argument("Array is empty");
    }
    int minVal, maxVal;
    findMinMax(arr, 0, arr.size() - 1, minVal, maxVal);
    vector<int> result;
    result.push_back(minVal);
    result.push_back(maxVal);
    return result;
}

int main() {
    vector<vector<int> > tests;
    int test1[] = {3, 1, 5, 2, 9, -1, 7};
    int test2[] = {42};
    int test3[] = {100, -50};

    tests.push_back(vector<int>(test1, test1 + sizeof(test1) / sizeof(int)));
    tests.push_back(vector<int>(test2, test2 + sizeof(test2) / sizeof(int)));
    tests.push_back(vector<int>(test3, test3 + sizeof(test3) / sizeof(int)));

    for (size_t i = 0; i < tests.size(); ++i) {
        vector<int> result = getMinMax(tests[i]);
        cout << "Test " << (i + 1) << ": Min = " << result[0]
             << ", Max = " << result[1] << endl;
    }

    return 0;
}
