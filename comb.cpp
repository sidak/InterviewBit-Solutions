void combinationSumHelper(vector<int> & A, int B, int sum, int idx, 
    vector<int>& comb, set< vector<int> >& ans){
    
    if(idx == A.size()){
        return;
    }
    else{
        
        if((sum + A[idx]) <= B){
            comb.push_back(A[idx]);
            if((sum + A[idx]) == B){
                ans.insert(comb);
            }
            else{
                combinationSumHelper(A, B, sum + A[idx], idx, comb, ans);
                combinationSumHelper(A, B, sum + A[idx], idx + 1, comb, ans);
                
            }
            
            comb.pop_back();
        }
        else{
            return;
        }
        combinationSumHelper(A, B, sum, idx+1, comb, ans);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > ans;
    set< vector<int> > setAns;
    vector<int> comb;
    if(A.size() == 0){
        return ans;
    }
    else{
        sort(A.begin(), A.end());
        vector<int> uniqueCandidates;
        for(int i=0; i<A.size(); i++){
            if(i==0 || A[i]!=A[i-1]){
                uniqueCandidates.push_back(A[i]);
            }
        }
        combinationSumHelper(uniqueCandidates, B, 0, 0, comb, setAns);
        for(auto it= setAns.begin(); it!=setAns.end(); it++){
            ans.push_back(*it);
        }
    }
    return ans;
}
