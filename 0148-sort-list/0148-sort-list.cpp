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

    // Find middle of linked list
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right){

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(left != NULL && right != NULL){

            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if(left != NULL)
            tail->next = left;

        if(right != NULL)
            tail->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if(head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* middle = findMiddle(head);

        // Split list into two halves
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }
};