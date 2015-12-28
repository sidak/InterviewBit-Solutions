void combinationSumHelper(vector<int> & candidates, int t, int sum, int idx,
    vector<int> & comb, vector< vector<int> > & ans, unordered_map<int, int> & hmap){
    
    if(sum > t){
        return;
    }
    else if(sum == t){
        ans.push_back(comb);
        return;
    }
    
    if(idx == candidates.size()){
        return;
    }
    
    for(int i=idx; i<candidates.size(); i++){
        comb.push_back(candidates[i]);
        sum+= candidates[i];
        hmap[candidates[i]]--;
        if(hmap[candidates[i]]>0){
            combinationSumHelper(candidates, t, sum, i, comb, ans, hmap);
        }
        else combinationSumHelper(candidates, t, sum, i+1, comb, ans, hmap);
        hmap[candidates[i]]++;
        sum-= candidates[i];
        comb.pop_back();
    }
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> comb;
    vector< vector<int> > ans;
    sort(A.begin(), A.end());
    unordered_map<int, int> hmap;
    vector<int> uniqueCandidates;
    for(int i=0; i<A.size(); i++){
        hmap[A[i]]++;
        if(i==0 || (i>=1 && A[i]!=A[i-1])){
            uniqueCandidates.push_back(A[i]);
        }
    }
    combinationSumHelper(uniqueCandidates, B, 0, 0, comb, ans, hmap);
    return ans;
}
