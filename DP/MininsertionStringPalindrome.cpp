#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;
class Solution {
public:
        int lcs(string str1,string str2){
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s){
         string t=s;
         reverse(t.begin(), t.end()); // Reverse the string
         return lcs(t,s);
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};
int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string: ";
    cin >> s; // Input string

    int result = solution.minInsertions(s); // Get the result
    cout << "Minimum insertions needed to make the string a palindrome: " << result << endl; // Output result
    
    return 0; // Indicate successful completion
}

