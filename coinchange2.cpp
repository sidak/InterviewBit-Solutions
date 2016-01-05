int Solution::coinchange2(vector<int> &A, int B) {
    
    int k = A.size();
    if(k==0) return 0;
    
    int MOD = 1000007;

    vector<int> count(B+1, 0);
    count[0] = 1;
    
    for(int i=0; i<k; i++){
        for(int j=A[i]; j<=B; j++){
            count[j] = (count[j] + count[j-A[i]])%MOD; 
        }
    }
    return count[B];
    
    
}
