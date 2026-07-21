class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.size();

        int lps = 1;
        int start = 0;

        vector<vector<bool>> dp(m, vector<bool>(m, false));
        for(int i=0;i<m;i++){
            dp[i][i] = true;
            if(i<m-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1] = true;
                    lps = 2;
                    start = i;
                }
            }
        }
        for(int d=3;d<=m;d++){
            for(int i=0;i<m-d+1;i++){
                if(s[i]==s[i+d-1] && dp[i+1][i+d-2]){
                    dp[i][i+d-1] = true;
                    lps = d;
                    start = i;
                }
            }
        }

        string ans = s.substr(start, lps);

        return ans;
    }
};