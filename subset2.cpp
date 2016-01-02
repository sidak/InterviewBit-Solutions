 
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > ans;

    if(A.size()==0){
        vector<int> noneEle;
        ans.push_back(noneEle);
        return ans;
    }
    
    int sz = A.size();
    sort(A.begin(), A.end());
    set< vector<int> > ans_set;
    for(int i=0; i<(1<<sz); i++){
        vector<int> comb;
        for(int j=0; j<sz; j++){
            if(i&(1<<j)){
                comb.push_back(A[j]);
            }
        }
        ans_set.insert(comb);
    }
    
    for(auto it=ans_set.begin(); it!=ans_set.end(); it++){
        ans.push_back(*it);
    }
    return ans;
}
