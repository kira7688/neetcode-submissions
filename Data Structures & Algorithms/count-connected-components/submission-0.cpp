class Solution {
public:
    int find(vector<int>& path, int i){
        while(path[i]!=i){
            i = path[i];
        }

        return path[i];
    }
    void union_func(vector<int>& path, int i, int root){
        int temp;
        while(path[i]!=i){
            temp = i;
            i = path[i];
            path[temp] = root;
        }

        path[i] = root;

        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> path;
        for(int i=0;i<n;i++){
            path.push_back(i);
        }

        int root;
        for(vector<int> edge: edges){
            root = find(path, edge[0]);
            union_func(path, edge[1], root);
        }
        int counter = 0;
        for(int i=0;i<n;i++){
            if(path[i]==i){
                counter++;
            }
        }

        return counter;
    }
};
