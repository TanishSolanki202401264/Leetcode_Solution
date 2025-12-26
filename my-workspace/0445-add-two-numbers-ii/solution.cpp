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
 ListNode* Reverse(ListNode* curr, ListNode* prev){
       if(curr == NULL){
           return prev;
       }
       ListNode* front = curr->next;
       curr->next = prev;
       return Reverse(front, curr);
   }

   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
       l1 = Reverse(l1, NULL);
       l2 = Reverse(l2, NULL);
       ListNode* curr1 = l1;
       ListNode* curr2 = l2;
       ListNode* head = new ListNode(0);
       ListNode* Tail = head;
       int carry = 0;
       while(curr1 != NULL && curr2 != NULL){
           int sum = curr1->val + curr2->val + carry;
           Tail->next = new ListNode(sum % 10);
           Tail = Tail->next;
           carry = sum / 10;
           curr1 = curr1->next;
           curr2 = curr2->next;
       }
       while(curr1 != NULL){
           int sum = curr1->val + carry;
           Tail->next = new ListNode(sum % 10);
           Tail = Tail->next;
           carry = sum / 10;
           curr1 = curr1->next;
       }
       while(curr2 != NULL){
           int sum = curr2->val + carry;
           Tail->next = new ListNode(sum % 10);
           Tail = Tail->next;
           carry = sum / 10;
           curr2 = curr2->next;
       }
       while(carry > 0){
           Tail->next = new ListNode(carry % 10);
           Tail = Tail->next;
           carry = carry / 10;
       }
        head = Reverse(head->next, NULL);
        
       while(head != NULL && head->val == 0 && head->next != NULL){
           head = head->next;
       }

    
       return head;
    }
};
