void bfs(int i, int j, vector<string> &A){
	if(i>0 && A[i-1][j]=='X'){
		A[i-1][j]='Y';
		bfs(i-1,j,A);
	}
	
	if(i<(A.size()-1) && A[i+1][j]=='X'){
		A[i+1][j]='Y';
		bfs(i+1,j,A);
	}
	
	if(j>0 && A[i][j-1]=='X'){
		A[i][j-1]='Y';
		bfs(i,j-1,A);
	}
	
	if(j<(A[0].size()-1) && A[i][j+1]=='X'){
		A[i][j+1]='Y';
		bfs(i,j+1,A);
	}
	
}
int Solution::black(vector<string> &A) {
    if(A.size()==0) return 0;
    
    int n = A.size();
    int m = A[0].size();
    
    int ct=0;
    
    for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(A[i][j]=='X'){
				A[i][j]='Y';
				bfs(i,j, A);
				ct++;
			}
		}
	}
	return ct;
}
