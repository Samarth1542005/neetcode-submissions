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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode *prev = NULL , *temp = head;
        while(temp!=NULL)
        {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* findkthNode(ListNode *head , int k)
    {
        k--;
        while(head != NULL && k>0)
        {
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prevNode = NULL;
        while(temp!=NULL)
        {
            ListNode *kthNode = findkthNode(temp,k);
            if(kthNode == NULL)
            {
                if(prevNode)
                {
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);

            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
