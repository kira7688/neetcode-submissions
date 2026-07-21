class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char ch;
        unordered_map<char,char> hashMap = {{'}','{'}, {')','('}, {']','['}};
        for(char c: s){
            if(hashMap.count(c)){
                if(st.empty()){
                    return false;
                }
                ch = st.top();
                st.pop();

                if(ch!=hashMap[c]){
                    return false;
                }
            }
            else{
                st.push(c);
            }
        }
        if(!st.empty()){
            return false;
        }

        return true;
    }
};