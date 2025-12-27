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
    Node* copyRandomList(Node* head) {
        Node*headcopy=new Node(0);
        Node*Tailcopy=headcopy;
        Node*temp=head;
        while(temp!=NULL){
            Tailcopy->next=new Node(temp->val);
            Tailcopy=Tailcopy->next;
            temp=temp->next;
        }
        Tailcopy=headcopy;
        headcopy=headcopy->next;
        delete Tailcopy;
        Tailcopy=headcopy;
        temp=head;
         
         //Random pointer ni space o(1) karava mate
         
         unordered_map<Node*,Node*>m;
         while(temp!=NULL){
             m[temp]=Tailcopy;
             Tailcopy=Tailcopy->next;
             temp=temp->next;
         }
         //random pointer assign to karva padse ne 
        temp=head;
        Tailcopy=headcopy;
        while(temp!=NULL){
            Tailcopy->random=m[temp->random];
            Tailcopy=Tailcopy->next;
            temp=temp->next;
        }
        
        return headcopy;
    }
};
