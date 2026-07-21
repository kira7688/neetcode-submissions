class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;

        vector<vector<string>> res;

        int i = 0;

        for(string str: strs){
            // vector<int> chars(26, 0);
            // for(char c: str){
            //     chars[c-97] += 1;
            // }
            // string s;
            // for(int i=0;i<26;i++){
            //     s += to_string(chars[i]);
            //     s += char(97+i);
            // }
            string s = str;
            sort(s.begin(), s.end());
            if(map.count(s)){
                res[map[s]].push_back(str);
            }
            else{
                map[s] = i;
                res.push_back({str});
                i++;
            }
        }

        return res;
    }
};