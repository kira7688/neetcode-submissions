class Solution {
public:
    char isValid(char c){
        if((c>=97 && c<=122) || (c>=48 && c<=57)){
            return c;
        }
        else if(c>=65 && c<=90){
            return char(c+32);
        }

        return '.';
    }
    bool isPalindrome(string s) {
        int m = s.size();
        int l = 0, r = m-1;
        char cl, cr;
        while(l<=r){
            cl = isValid(s[l]);
            if(cl=='.'){
                l++;
                continue;
            }
            
            cr = isValid(s[r]);
            if(cr=='.'){
                r--;
                continue;
            }
            if(cl!=cr){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};