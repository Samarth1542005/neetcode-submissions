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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode *head = new ListNode();
        ListNode *ans = head;
        ListNode *temp1 = list1 , *temp2 = list2;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->val <= temp2->val)
            {
                head->next = temp1;
                head = head->next;
                temp1 = temp1 ->next;
            }
            else
            {
                head->next = temp2;
                head = head->next;
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL)
        {
            head->next = temp1;
            temp1 = temp1->next;
            head = head->next;
        }
        while(temp2 != NULL)
        {
            head->next = temp2;
            temp2 = temp2->next;
            head = head->next;
        }
        return ans->next;
    }
};
