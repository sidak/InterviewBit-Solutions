/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A->next ==NULL) return A;
    
    ListNode* curr = A->next;
    ListNode* prev_curr = A;
    
    
    while(curr!=NULL){
        ListNode* start = A;
        ListNode * prev_start = NULL;
        while(start!=curr){
            if(start->val<=curr->val){
                prev_start = start;
                start= start->next;
            }
            else{
                if(prev_start==NULL){
                    prev_curr ->next= curr->next;
                    curr->next = start;
                    A= curr;
                }
                else{
                    prev_curr ->next= curr->next;
                    prev_start->next=curr;
                    curr->next = start;
                }
                
            }
            
            break;
        }
        
        if(prev_curr->next== curr){
            prev_curr = curr;
            curr=curr->next;
        }
        else{
            curr = prev_curr->next;
        }
        
        
    }
    return A;
}
