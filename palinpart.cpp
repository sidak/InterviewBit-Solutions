bool isPalin(string st){
    int n = st.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(st[i] != st[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void printVec(vector<string> pvec){
    for(int i=0; i<pvec.size(); i++){
        cout<<pvec[i]<<" ";
    }
    cout<<endl;
}
void partitionHelper(string st, int i, string & A, vector<string> & pvec, vector<vector<string>> & ans){
    int n = A.size();
    if(i==n){
        //cout<<"yo bitch"<<endl;
        if(st.size()==0){
            ans.push_back(pvec);
        }
        return;
    }
    
    st.push_back(A[i]);
    //cout<<"i is "<< i<< " and st is "<<st<<endl;
    if(isPalin(st)){
        //cout<<"is palin"<<endl;
        
        pvec.push_back(st);
        //printVec(pvec);
        string tem = st;
        st.clear();
        partitionHelper(st, i+1, A, pvec, ans);
        pvec.pop_back();
        st=tem;
    }
    partitionHelper(st, i+1, A, pvec, ans);
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    /*
    vector< vector<bool> > isPalin;
    for(int l=1; l<=n; l++){
        for(int i=1; i<=(n-l+1); i++){
            int j = i+l-1;
            if(A[i-1]==A[j-1]){
                if((i==j) || ((i!=j) && isPalin[i][j-2])){
                    isPalin[i-1][j-1] = true;
                }
            }
            else isPalin[i-1][j-1] = false;
        }    
    }
    */
    
    vector<vector<string>> ans;
    string st;
    vector<string> pvec;
    partitionHelper(st, 0, A, pvec, ans);
    return ans;
    
}   
