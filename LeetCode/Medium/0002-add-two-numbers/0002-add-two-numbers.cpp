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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* tempPtr = answer;
        int tmp = 0;

        while(l1 != NULL || l2 != NULL || tmp != 0){
            int sum = 0;
            int l1_val = 0;
            int l2_val = 0;

            if(l1 != NULL){
                l1_val = l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                l2_val = l2->val;
                l2 = l2->next;
            }

            sum = l1_val + l2_val + tmp;
            tmp = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            tempPtr->next = node;
            tempPtr = tempPtr->next;
        }




        return answer->next;
    }
};