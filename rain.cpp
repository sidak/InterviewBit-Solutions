int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<int> st;
    int n = A.size();
    if(n<=2) return 0;
    int ans =0;
    
    int i =0;
    int leftHt, minHt;
    st.push(A[0]);
    leftHt = A[0];
    minHt = A[0];
    i++;
    // remove the increasing part
    while(i<n && A[i]>=A[i-1]){
        st.pop();
        st.push(A[i]);
        leftHt = A[i];
        minHt = A[i];
        i++;
    }
    
    while(i<n){
        
        
        if(A[i+1]<A[i]){
                
        }
        else{
            
        }
        
        
        i++;
    }
    
    if(i==(n) && !st.empty()){
        int maxHt = max(st.top(), leftHt);
        while(!st.empty()){
            ans += maxHt - st.top();
            st.pop();
        }
    }
    
    return ans;
}
