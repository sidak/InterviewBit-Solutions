/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL) return A;
    
    if(A->next == NULL) return A;
    
    ListNode* head = A;
    ListNode* curr = A;
    
   if((curr->next)->val != curr->val){
       head->next = deleteDuplicates(curr->next);
   }
   else{
       int duplicateVal = curr->val;
       
       while(curr!=NULL && curr->val == duplicateVal){
           ListNode* temp = curr;
           curr=curr->next;
           delete temp;
       }
       if(curr==NULL){
           head = NULL;
       }
       else{
           head = deleteDuplicates(curr);
       }
       
   }
   return head;
}
