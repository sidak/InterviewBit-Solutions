/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A==NULL){
        return 1;
    }
    else if (A->next ==NULL){
        return 1;
    }
    else{
        int sz =0;
        ListNode * curr = A;
        while(curr!=NULL){
            curr= curr->next;
            sz++;
        }
        ListNode* prev = NULL;
        curr = A;
        for(int i=0; i<sz/2; i++){
            prev = curr;
            curr=curr->next;
        }
        ListNode* rhead=NULL;
        ListNode* nextNd;
        while(curr!=NULL){
            nextNd = curr-> next;
            curr->next = prev;
            prev = curr;
            curr=nextNd;
        }
        rhead = prev;
        ListNode * lhead = A;
        
        while(lhead!=rhead && !((lhead->next == rhead) && (rhead->next == lhead)) ){
            if(lhead->val != rhead->val) return 0;
            lhead= lhead->next;
            rhead= rhead->next;
        }
        
        if((lhead->next == rhead) && (rhead->next == lhead)){
            if(lhead->val != rhead->val) return 0;
        }
        return 1;
        
        
    }
}
