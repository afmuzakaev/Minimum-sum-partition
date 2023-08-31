#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMinSubsetDifference(vector<int>& arr) {
    int n = arr.size();
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }
    
    // Step 2: Initialize DP array
    vector<vector<bool>> dp(n + 1, vector<bool>(total_sum / 2 + 1, false));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    
    // Step 3: Fill DP array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= total_sum / 2; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    // Step 4: Find the closest sum to half of total_sum
    int min_diff = INT_MAX;
    for (int j = total_sum / 2; j >= 0; --j) {
        if (dp[n][j]) {
            min_diff = total_sum - 2 * j;
            break;
        }
    }
    
    return min_diff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    int result = findMinSubsetDifference(arr);
    cout << result << endl;  // Output: 1
    
    return 0;
}
