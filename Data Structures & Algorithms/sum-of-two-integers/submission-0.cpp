class Solution {
public:

    int getSum(int a, int b){
        int ans = 0;
        int val = 0, carry = 0;
        int la, lb;

        for(int i=0;i<32;i++){
            la = a & 1;
            lb = b & 1;
            if(a && b){
                if(la && lb){
                    if(carry){
                        val = 1;
                    }
                    else{
                        val = 0;
                    }
                    carry = 1;
                }
                else if(la || lb){
                    if(carry){
                        val = 0;
                        carry = 1;
                    }
                    else{
                        val = 1;
                        carry = 0;
                    }
                }
                else{
                    if(carry){
                        val = 1;
                        carry = 0;
                    }
                    else{
                        val = 0;
                        carry = 0;
                    }
                }
            }
            else if(a){
                if(la){
                    if(carry){
                        val = 0;
                        carry = 1;
                    }
                    else{
                        val = 1;
                        carry = 0;
                    }
                }
                else{
                    if(carry){
                        val = 1;
                        carry = 0;
                    }
                    else{
                        val = 0;
                        carry = 0;
                    }
                }
            }
            else{
                if(lb){
                    if(carry){
                        val = 0;
                        carry = 1;
                    }
                    else{
                        val = 1;
                        carry = 0;
                    }
                }
                else{
                    if(carry){
                        val = 1;
                        carry = 0;
                    }
                    else{
                        val = 0;
                        carry = 0;
                    }
                }
            }
            a = a >> 1;
            b = b >> 1;

            ans = (val << i) | ans;
        }

        return ans;
    }
};