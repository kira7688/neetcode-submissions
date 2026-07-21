class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int last_but_one = 1, last = 2;

        for(int i=3;i<=n;i++){
            last = last + last_but_one;
            last_but_one = last - last_but_one;
        }

        return last;
    }
};