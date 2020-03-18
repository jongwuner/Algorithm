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
    bool hasCycle(ListNode *head) {
         set<ListNode*> SET;
         ListNode* nowNode = head;
         while (nowNode != NULL) {
             SET.insert(nowNode);
             nowNode = nowNode->next;
             if (SET.find(nowNode) != SET.end())
                 return true;
         }
         return false;
    }
};