void subsetHelper(int i, vector<int> & subset, vector<vector<int>> & ans, vector<int> & A){
    if(i==A.size()){
        ans.push_back(subset);
        return;
    }
    subsetHelper(i+1, subset, ans, A);
    subset.push_back(A[i]);
    subsetHelper(i+1, subset, ans, A);
    subset.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > ans;
    vector<int> subset;
    sort(A.begin(), A.end());
    subsetHelper(0, subset, ans, A);
    sort(ans.begin(), ans.end());
    return ans;
}
