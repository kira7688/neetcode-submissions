class Solution {
public:
    bool checkSub(unordered_map<char,int>& chars, unordered_map<char,int>& chart){
        for(auto it: chart){
            if(chars[it.first] < it.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        if(n>m){
            return "";
        }

        unordered_map<char,int> chart;
        for(char c: t){
            if(chart.count(c)){
                chart[c] += 1;
            }
            else{
                chart[c] = 1;
            }
        }

        int low = -1, high = 0;

        unordered_map<char,int> chars;
        char c;

        int minStart = -1;
        int minLen = INT_MAX;

        bool check = false;

        while(high<m || check){

            if(check){
                c = s[low];
                if(chart.count(c)){
                    chars[c] -= 1;
                    if(!chars[c]){
                        chars.erase(c);
                    }
                }
                
                low++;
                while(!chart.count(s[low]) && low<high){
                    low++;
                }
            }
            else{
                c = s[high];
                if(chart.count(c)){
                    if(low == -1){
                        low = high;
                    }
                    if(chars.count(c)){
                        chars[c] += 1;
                    }
                    else{
                        chars[c] = 1;
                    }
                }

                high++;
            }

            if(chars.size()==chart.size()){
                if(checkSub(chars, chart)){
                    if(high-low < minLen){
                        //minStr = s.substr(low, high-low);
                        minStart = low;
                        minLen = high-low;
                    }
                    check = true;
                }
                else{
                    check = false;
                }
            }
            else{
                check = false;
            }
        }

        string minStr = "";
        if(minStart!=-1){
            minStr = s.substr(minStart, minLen);
        }

        return minStr;
    }
};