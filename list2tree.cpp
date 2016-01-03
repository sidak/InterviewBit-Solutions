/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* listToBSTHelper(ListNode*A, int sz){
    if(A==NULL || sz ==0){
        return NULL;
    }
    ListNode*curr=A;
    int steps;
    steps = sz/2;
    int leftSize = steps;
    while(steps>0){
        curr=curr->next;
        steps--;
    }
    TreeNode* rt = new TreeNode(curr->val);
    rt->left = listToBSTHelper(A, leftSize);
    rt->right = listToBSTHelper(curr->next, (sz-1 - leftSize));

    return rt;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode * tree;
    if(A==NULL)return tree;
    int sz =0;
    ListNode* curr = A;
    
    while(curr){
        sz++;
        curr=curr->next;
    }
    
    tree = listToBSTHelper(A,sz);

    return tree;
}

