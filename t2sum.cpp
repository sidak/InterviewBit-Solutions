/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> leftStack, rightStack;
    TreeNode * currL = A;
    TreeNode * currR = A;
    
    while(!leftStack.empty() || !rightStack.empty() || currL!=NULL || currR!=NULL){
        if(currL!=NULL || currR!=NULL){
            if(currL!=NULL){
                leftStack.push(currL);
                currL = currL->left;
            }
            else{
                rightStack.push(currR);
                currR = currR->right;
            }
        }
        else{
            int valL = leftStack.top()->val;
            int valR = rightStack.top()->val;
            
            if(valL == valR) break;
            if( (valL + valR) == B ){
                return 1;
            }
            else if ( (valL + valR) < B){
                currL = leftStack.top();
                leftStack.pop();
                currL = currL ->right;
            }
            else{
                currR = rightStack.top();
                rightStack.pop();
                currR = currR->left;
            }
        }
    }
    return 0;
}
