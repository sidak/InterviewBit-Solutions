vector<int> Solution::prevSmaller(vector<int> &A) {
    stack< int> st;
    vector<int> ans;
    int szA = A.size();
    if(szA==0) return ans;
    
    for(int i=0; i<szA; i++){
        
        while(st.size()>0 && st.top() >= A[i]){
            st.pop();
        }
        
        if(st.size()==0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        
        st.push(A[i]);
        
    }
    return ans;
}
