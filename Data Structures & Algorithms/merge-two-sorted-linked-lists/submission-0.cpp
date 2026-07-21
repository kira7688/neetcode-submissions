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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        else if(!list2){
            return list1;
        }

        ListNode *root = NULL, *next = NULL;
        while(list1 && list2){
            if(list1->val < list2->val){
                if(!root){
                    root = list1;
                    next = list1;
                    list1 = list1->next;
                    continue;
                }
                next->next = list1;
                next = list1;
                list1 = list1->next;
            }
            else{
                if(!root){
                    root = list2;
                    next = list2;
                    list2 = list2->next;
                    continue;
                }
                next->next = list2;
                next = list2;
                list2 = list2->next;
            }
        }
        while(list1){
            next->next = list1;
            next = list1;
            list1 = list1->next;
        }
        while(list2){
            next->next = list2;
            next = list2;
            list2 = list2->next;
        }

        return root;
    }
};