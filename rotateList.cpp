/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(B==0) return A;
    
    int sz = 0;
    ListNode * curr = A;
    while(curr!=NULL){
        sz++;
        curr=curr->next;
    }
    
    
    
    int k = B%sz;
    
    if(k==0) return A;
    curr = A;
    ListNode* prev = NULL, *rhead = A;
    int ct =0;
    while(ct<k){
        curr=curr->next;
        ct++;
    }
    while(curr!=NULL){
        prev = rhead;
        rhead = rhead ->next;
        curr=curr->next;
    }
    prev -> next = NULL;
    
    curr = rhead;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next = A;
    return rhead;
}
