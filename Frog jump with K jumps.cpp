//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int f(int i,vector<int>& height,int k,vector<int> &dp){
    if(i==0){
        return 0;
    }
    if (dp[i] != -1) {
            return dp[i];
        }
    int min_cost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) { // Check to ensure we do not go out of bounds
                int cost = f(i - j, height, k, dp) + abs(height[i] - height[i - j]);
                min_cost = min(min_cost, cost);
            }
        }
    return dp[i] = min_cost;
  }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,-1);
        return f(n - 1, height, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends