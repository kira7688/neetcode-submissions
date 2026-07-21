class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        if(m==0){
            return true;
        }
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for(vector<int> p: prerequisites){
            adjList[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ind, counter = 0;
        while(!q.empty()){
            ind = q.front();
            q.pop();

            counter++;

            for(int i: adjList[ind]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        if(counter!=numCourses){
            return false;
        }

        return true;
    }
};