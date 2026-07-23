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
    ListNode* reverseList(ListNode *head){
        // cout << head->val;
        ListNode *next = head->next;
        if(!next){
            return head;
        }

        ListNode *reversed = reverseList(next);
        next->next = head;
        head->next = nullptr;

        return reversed;
    }
    void joinList(ListNode *l1, ListNode *l2){
        ListNode *l1Next = l1->next, *l2Next = l2->next;

        l1->next = l2;
        l2->next = l1Next;
        if(l2Next){
            joinList(l1Next, l2Next);
        }

        return;

    }
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            if(!fast){
                break;
            }
            slow = slow->next;
        }
        // cout << slow->val << endl;
        ListNode *secHalf = slow->next;
        slow->next = nullptr;
        
        if(secHalf){
            secHalf = reverseList(secHalf);

            joinList(head, secHalf);
        }
        
    }
};
