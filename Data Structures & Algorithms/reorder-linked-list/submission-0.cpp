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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast){
            fast = fast->next;
            
            if(fast){
                fast = fast->next;
            }
            else{
                break;
            }
            slow = slow->next;
        }

        ListNode *node = slow, *prev = NULL, *next;
        while(node){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        ListNode *nodeRev = prev, *nextRev;
        node = head;
        while(1){
            if(node==nodeRev){
                break;
            }
            next = node->next;
            node->next = nodeRev;
            node = next;

            nextRev = nodeRev->next;
            if(!nextRev){
                break;
            }
            nodeRev->next = node;
            nodeRev = nextRev;
        }
        
        return;
    }
};