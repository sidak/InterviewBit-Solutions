/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL || A->next==NULL) return NULL;
    else {
        ListNode* slow=A, * fast=A;
        
        while(slow!=NULL && fast !=NULL){
            slow=slow->next;
            if(fast->next==NULL) return NULL;
            else fast= (fast->next)->next;
            if(slow==fast) break;
        }
        if(slow==NULL || fast==NULL)return NULL;
        //cout<<"hello "<<slow->val<<" "<<fast->val<<endl;
        int sz =1;
        ListNode * cSlow=slow->next;
        while(cSlow!=slow){
            cSlow=cSlow->next;
            sz++;
        }
        //cout<<"sz is "<<sz<<endl;
        ListNode * kth =A;
        for(int i=1; i<=sz; i++){
            kth=kth->next;
        }
        //cout<<"jerhfde"<<endl;
        ListNode*hd = A;
        while(hd!=kth){
            hd=hd->next;
            kth=kth->next;
        }
        //cout<<kth->val<<" rkwe"<<endl;
        return hd;
    }
}
