vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> cntMap;
    
    vector<int> ans;
    
    int sz = A.size();
    if(B>sz){
        return ans;
    }
    
    for(int i=0; i<B; i++){
        cntMap[A[i]]++;
    }
    ans.push_back(cntMap.size());
    int i = B;
    while(i<sz){
        cntMap[A[i]]++;
        if(cntMap[A[i-B]] == 1){
            cntMap.erase(A[i-B]);
        }
        else cntMap[A[i-B]]--;
        ans.push_back(cntMap.size());
        i++;
    }
    return ans;
}
