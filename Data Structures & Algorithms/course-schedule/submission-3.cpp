struct Node{
    vector<int> child;
    int prereq;
    Node(){
        child = {};
        prereq = 0;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){
            return true;
        }

        unordered_map<int, Node> g;
        for(auto p: prerequisites){
            if(!g.count(p[0])){
                g[p[0]] = Node();
            }
            if(!g.count(p[1])){
                g[p[1]] = Node();
            }
            g[p[1]].child.push_back(p[0]);
            g[p[0]].prereq += 1;
        }
        queue<int> q;
        for(auto &p: g){
            if(g[p.first].prereq==0){
                q.push(p.first);
            }
        }
        if(q.empty()){
            return false;
        }
        
        int top;
        while(!q.empty()){
            top = q.front();
            q.pop();
            for(int i: g[top].child){
                g[i].prereq -= 1;
                if(g[i].prereq==0){
                    q.push(i);
                }
                else if(g[i].prereq<0){
                    return false;
                }
            }
        }

        for(auto &p: g){
            if(g[p.first].prereq!=0){
                return false;
            }
        }

        return true;
    }
};
