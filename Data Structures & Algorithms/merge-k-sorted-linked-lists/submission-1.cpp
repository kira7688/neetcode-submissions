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
    ListNode* mergeLists(ListNode *l1, ListNode*l2){
        ListNode *head, *next;
        if(l1 && l2){
            if(l1->val<=l2->val){
                head = l1;
                l1 = l1->next;
            }
            else{
                head = l2;
                l2 = l2->next;
            }
        }
        else if(l1){
            return l1;
        }
        else{
            return l2;
        }
        next = head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                next->next = l1;
                next = l1;
                l1 = l1->next;
            }
            else{
                next->next = l2;
                next = l2;
                l2 = l2->next; 
            }
        }
        if(l1){
            next->next = l1;
        }
        else{
            next->next = l2;
        }

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l=0, int r=10000) {
        if(l>r){
            return nullptr;
        }
        int m = lists.size();
        if(r==10000){
            r = m-1;
        }
        int len = r-l+1;
        int mid = (r+l)/2;
        if(len==0){
            return nullptr;
        }
        else if(len==1){
            return lists[l];
        }
        else if(len==2){
            return mergeLists(lists[l], lists[l+1]);
        }
        else{
            return mergeLists(mergeKLists(lists, l, mid), mergeKLists(lists, mid+1, r));
        }
        
    }
};
