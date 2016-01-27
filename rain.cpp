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
        
        st.push(A[i]);
        minHt = min(minHt, A[i]);
        
        if(A[i] > minHt){
            if((i<(n-1) && A[i]>A[i+1]) || i==(n-1)){
                // compute trap in this phase uptill now
                int maxHt = min(A[i], leftHt);
                while(!st.empty()){
                    if(st.top()<maxHt) ans += maxHt - st.top();
                    st.pop();
                }
                leftHt = A[i];
                minHt = A[i];
                st.push(A[i]);
            }
        }
        //cout<<"for i : "<<i<<" minHt is "<<minHt<<" & leftHt is "<<leftHt<<" and ans is "<<ans<<endl;
        i++;
    }
    
    
    return ans;
}
