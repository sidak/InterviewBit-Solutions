int min3(int a, int b, int c){
    return min(a, min(b,c));
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    if(n==0) return 0;
    int m = A[0].size();
    
    vector< vector<int> > dp(n, vector<int>(m, 0));
    dp[n-1][m-1] = min(A[n-1][m-1],0);
    for(int i=(m-2); i>=0; i--){
        dp[n-1][i] = min3(0, A[n-1][i], A[n-1][i] + dp[n-1][i+1]);
    }
    for(int i=(n-2); i>=0; i--){
        dp[i][m-1] = min3(0, A[i][m-1], A[i][m-1] + dp[i+1][m-1]);
    }
    for(int i=(n-2); i>=0; i--){
        for(int j=(m-2); j>=0; j--){
            int bestNeighbor = max(dp[i][j+1], dp[i+1][j]);
            dp[i][j] = min3(0, A[i][j], A[i][j] + bestNeighbor);
        }
    }
    
    
    return ((int) abs(dp[0][0])+1);   
}
