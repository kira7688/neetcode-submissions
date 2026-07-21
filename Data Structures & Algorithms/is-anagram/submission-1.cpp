class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sm(26, 0), tm(26, 0);
        for(char c: s){
            sm[c-97]++;
        }
        for(char c: t){
            tm[c-97]++;
        }
        for(int i=0;i<26;i++){
            if(sm[i]!=tm[i]){
                return false;
            }
        }

        return true;
    }
};