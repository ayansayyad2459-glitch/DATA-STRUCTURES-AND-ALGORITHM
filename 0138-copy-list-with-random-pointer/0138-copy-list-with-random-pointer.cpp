/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopyinbetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node*copy = new Node(temp->val);
            copy->next= temp->next;
            temp->next = copy;
            temp=temp->next->next;
        }
    }

    void connectrandompointers(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
               
            }
             else{
                    copy->random= nullptr;
                }
                temp= temp->next->next;
               
        }
    }

    Node* deepcopyList(Node* head){
        Node* temp = head;
        Node*  dummynode = new Node(-1);
        Node* res = dummynode;
        while(temp!=NULL){
        res->next = temp->next;
        res=res->next;
        // making free connections and disconnecting and going back to initial stage of LL
        temp->next= temp->next->next;
        temp = temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL)
        return NULL;
        insertcopyinbetween(head);
        connectrandompointers(head);
        return deepcopyList(head);
    }
};