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
    ListNode*merge(ListNode*head1,ListNode*head2){
        ListNode*head=new ListNode(0);
        ListNode*Tail=head;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                Tail->next=head1;
                head1=head1->next;
                Tail=Tail->next;
                Tail->next=NULL;
            }
            else{
                Tail->next=head2;
                head2=head2->next;
                Tail=Tail->next;
                Tail->next=NULL;    
            }
        }
            if(head1!=NULL){
                Tail->next=head1;
            }
            else{
                Tail->next=head2;
            }
            return head->next;
        
    }
  void mergesort(vector<ListNode*>&lists,int start,int end){
         if(start>=end){
            return;
         }
         int mid=start+(end-start)/2;
         mergesort(lists,start,mid);
         mergesort(lists,mid+1,end);
         lists[start]=merge(lists[start],lists[mid+1]);
  }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
       mergesort(lists,0,lists.size()-1);
         return lists[0];
    }
};
