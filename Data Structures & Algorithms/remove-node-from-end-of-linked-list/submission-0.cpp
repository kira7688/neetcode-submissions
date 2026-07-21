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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int temp = n+1;
        ListNode *node = head;
        while(temp){
            if(!node){
                return head->next;
            }
            node = node->next;
            temp--;
        }
        ListNode *n_1_th = head;
        while(node){
            node = node->next;
            n_1_th = n_1_th->next;
        }
        
        n_1_th->next = n_1_th->next->next;

        return head;
    }
};