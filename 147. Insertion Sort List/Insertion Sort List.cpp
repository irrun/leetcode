/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        
        ListNode *cur=newhead, *tail=head, *second=tail->next;
        while(second) {
            
            while(cur!=tail && cur->next->val<=second->val) {
                cur=cur->next;
            }
            if(cur==tail) {
                tail=tail->next;
            }else {
                tail->next=second->next;
                second->next=cur->next;
                cur->next=second;
            }
            second=tail->next;
            cur=newhead;
        }
        return newhead->next;
    }
};