class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int m = s.size();

        int maxRepeating = min(1+k, m);
        
        vector<int> gaps;
        int prev;
        int l, r, gap;
        for(int c=0;c<26;c++){
            
            gaps.clear();
            prev = -1;
            for(int i=0;i<m;i++){
                if(s[i]==char(c+65)){
                    gaps.push_back(i-prev-1);
                    prev = i;
                }
            }
            if(gaps.empty()){
                continue;
            }
            l = 0, r = 0;
            gap = gaps[0];
            while(r<gaps.size()){
                if(gap<=k){
                    if(l==0){
                        maxRepeating = max(maxRepeating, min((r-l+1)+k, m));
                    }
                    else{
                        maxRepeating = max(maxRepeating, min((r-l+2)+k, m));
                    }
                    
                    r++;
                    if(r==gaps.size()){
                        break;
                    }
                    gap += gaps[r];
                }
                else{
                    gap -= gaps[l];
                    l++;
                    if(l>r){
                        r = l;
                        if(r==gaps.size()){
                            break;
                        }
                        gap += gaps[r];
                    }
                }
            }
            
        }

        return maxRepeating;
    }
};