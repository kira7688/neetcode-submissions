class Solution {
public:
    void helper(vector<vector<int>>& adjMat, vector<bool>& visited, int curr, int last, int& n, bool& isTree){
        visited[curr] = true;
        for(int i=0;i<n;i++){
            if(adjMat[curr][i]){
                if(visited[i]){
                    if(i!=last){
                        isTree = false;
                        return;
                    }
                }
                else{
                    helper(adjMat, visited, i, curr, n, isTree);
                    if(!isTree){
                        return;
                    }
                }
            }
        }

        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMat(n, vector<int>(n, 0));
        for(auto edge: edges){
            adjMat[edge[0]][edge[1]] = 1;
            adjMat[edge[1]][edge[0]] = 1;
        }

        vector<bool> visited(n, false);

        bool isTree = true;
        
        helper(adjMat, visited, 0, -1, n, isTree);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                isTree = false;
                break;
            }
        }

        return isTree;

    }
};
