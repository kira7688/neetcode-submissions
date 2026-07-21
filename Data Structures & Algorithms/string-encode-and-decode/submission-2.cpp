class Solution {
public:

    string encode(vector<string>& strs) {
        int m = strs.size(), n;

        string s = "";
        for(int i=0;i<m;i++){
            n = strs[i].size();
            for(int j=0;j<n;j++){
                s += to_string(int(strs[i][j]));
                if(j!=n-1){
                    s += ',';
                }
            }
            
            s += ':';
        }

        //cout << s << endl;

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        string str = "", temp = "";
        for(char c: s){
            if(c==':'){
                if(temp.size()){
                    str = str + char(stoi(temp));
                }
                ans.push_back(str);
                str = "";
                temp = "";
            }
            else if(c==','){
                str = str + char(stoi(temp));
                temp = "";
            }
            else{
                temp += c;
            }
        }

        return ans;
    }
};
