class Solution {
public:
    int numDecodings(string s) {
        int m = s.size();
        if(m==1){
            if(s[0]=='0'){
                return 0;
            } 
            return 1;
        }

        vector<int> code;
        for(int i=0;i<m;i++){
            code.push_back(s[i]-48);
        }

        vector<int> dp(m, 0);
        if(code[0]==0){
            return 0;
        }
        dp[0] = 1;
        
        if(code[1]==0){
            if(code[0]==1 || code[0]==2){
                dp[1] = 1;
            }
            else{
                return 0;
            }
        }
        else if(code[0]==1){
            dp[1] = 2;
        }
        else if(code[0]==2){
            if(code[1]<=6){
                dp[1] = 2;
            }
            else{
                dp[1] = 1;
            }
        }
        else{
            dp[1] = 1;
        }
        for(int i=2;i<m;i++){
            if(code[i]==0){
                if(code[i-1]==1 || code[i-1]==2){
                    dp[i] = dp[i-2];
                }
                else{
                    return 0;
                }
            }
            else if(code[i-1]==1){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else if(code[i-1]==2){
                if(code[i]<=6){
                    dp[i] = dp[i-1] + dp[i-2];
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
            else{
                dp[i] = dp[i-1];
            }
        }

        return dp[m-1];
    }
};