class Solution {
public:
    int countSubstrings(string s) {
        unordered_set<int> odd, even, oddt, event;

        int m = s.size();

        int count = 0;
        for(int i=0;i<m;i++){
            odd.insert(i);
            count++;
            if(i<m-1){
                if(s[i]==s[i+1]){
                    even.insert(i);
                    count++;
                }
            }
        }

        for(int d=3;d<=m;d++){
            if(d%2==1){
                oddt.clear();
                for(int i: odd){
                    if(i>0 && i<m-d+2){
                        if(s[i-1]==s[i+d-2]){
                            oddt.insert(i-1);
                            count++;
                        }
                    }
                }

                odd = oddt;
            }
            else{
                event.clear();

                for(int i: even){
                    if(i>0 && i<m-d+2){
                        if(s[i-1]==s[i+d-2]){
                            event.insert(i-1);
                            count++;
                        }
                    }
                }

                even = event;
            }
        }

        return count;
    }
};