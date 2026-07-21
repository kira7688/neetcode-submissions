/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compareNodes{
        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
            return lhs->val > rhs->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        priority_queue<ListNode*, vector<ListNode*>, compareNodes> min_pq;
        for(auto list: lists){
            if(list)
                min_pq.push(list);
        }

        ListNode *root = NULL, *last = NULL, *next = NULL;
        while(!min_pq.empty()){
            next = min_pq.top();
            min_pq.pop();
            if(!root){
                root = next;
                last = next;
                if(next->next)
                    min_pq.push(next->next);
                continue;
            }
            last->next = next;
            last = next;
            if(next->next)
                min_pq.push(next->next);
        }

        return root;
    }
};