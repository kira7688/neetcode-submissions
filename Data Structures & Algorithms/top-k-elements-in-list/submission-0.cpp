class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num: nums){
            if(map.count(num)){
                map[num]++;
            }
            else{
                map[num] = 1;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>> max_pq;
        for(auto it: map){
            max_pq.push({it.second, it.first});
        }
        vector<int> res;
        pair<int,int> top;
        for(int i=0;i<k;i++){
            top = max_pq.top();
            res.push_back(top.second);
            max_pq.pop();
        }

        return res;

    }
};