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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* newNode = new ListNode((p->val + q->val) % 10);
        ListNode* head = newNode;

        int c = (p->val + q->val) / 10;
        
        while (p != NULL || q != NULL || c) {
            
            p = p->next;
            q = q->next;
            if (p == NULL && q == NULL && c == 0) break;
            if (p == NULL) p = new ListNode(0);
            if (q == NULL) q = new ListNode(0);

            ListNode* nextNode = new ListNode((p->val + q->val + c) % 10);
            c = (p->val + q->val + c) / 10;
            newNode->next = nextNode;
            newNode = nextNode;
        }
        return head;
    }
};