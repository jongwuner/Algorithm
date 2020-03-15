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
    int total = 0;
    int idx = 0;
    ListNode* prev;
    ListNode* now;
    ListNode* next;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        now = head;
        while(now != NULL){
            now = now->next;
            idx++;
        }
        total = idx;
        idx = 0;
        now = head;
        while(idx < total - n){
            prev = now;
            now = now->next;
            idx++;
        }
        if(n != total)
            prev->next = now->next;
        else
            head = now->next;
        return head;
    }
};