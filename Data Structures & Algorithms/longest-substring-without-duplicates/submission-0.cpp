class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = s.size();
        unordered_map<char,int> ind;
        int start = 0, len, maxlen = 0;
        for(int i=0;i<m;i++){
            if(ind.count(s[i])){
                start = max(start, ind[s[i]]+1);
            }
            ind[s[i]] = i;
            len = i-start+1;
            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};