#include<bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp) {
    int n = prices.size();
    if (ind >= n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy == 1) {
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, dp), 
                                  0 + f(ind + 1, 1, prices, dp));
    } else {
        return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, dp), 
                                  0 + f(ind + 1, 0, prices, dp));
    }
}

int stockProfit(vector<int> &prices) {   
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, dp);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};  
    cout << "Maximum Stock Profit: " << stockProfit(prices) << endl;
    return 0;
}
