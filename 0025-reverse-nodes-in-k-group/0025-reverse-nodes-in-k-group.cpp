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

//  three functions 1.to reverse the list 2.to find the kth node 3rd to reverse kth node
class Solution {

    // reverse
    ListNode* reverselinkedlist(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* front = curr->next;
            curr->next=prev;
            prev=curr;
            curr= front;
        }
        return prev;
    };

    // findkthnode
    ListNode* findkthnode(ListNode*temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
           
        }
        return temp;
    };

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while(temp!=NULL){
            // finding kth node
            ListNode* kthnode =  findkthnode(temp,k);

            // if k nodes are less like nodes are less than k
            if(kthnode==NULL){
                if(prevlast){
                    prevlast ->next = temp;
                   
                }
                 break;
            }
            // saving nextnode
            ListNode* nextnode = kthnode->next;
            // making nextnode null to sepeare the list
            kthnode->next = NULL;
             reverselinkedlist(temp);
             if(temp==head){
                head = kthnode;
             }
             else{
                prevlast->next = kthnode;
             }
             prevlast = temp;
             temp=nextnode;
        }
        return head;
        }
    
};