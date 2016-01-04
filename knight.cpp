bool valid(int x, int y, int n , int m ){
    if(x>=0 && x<n && y>=0 && y<m)return true;
    else return false;
}
int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int xcord[] = {2,1,-1,-2};
    int ycord[] = {1,2,2,1};
    
    vector< vector<int> > board(N, vector<int>(M, -1) );
    queue< pair<int,int> >  q;
    
    q.push(make_pair(x1-1,y1-1));
    board[x1-1][y1-1] ++;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==(x2-1) && y == (y2-1) ){
            return board[x][y];
        }
        
        for(int i=0; i<4; i++){
            int xnew = x + xcord[i];
            int ynew = y + ycord[i];
            if(valid(xnew, ynew, N, M) && board[xnew][ynew]==-1){
                board[xnew][ynew] = board[x][y] + 1;
                q.push(make_pair(xnew, ynew));
            }
            
            ynew = y - ycord[i];
            if(valid(xnew, ynew, N, M) && board[xnew][ynew]==-1){
                board[xnew][ynew] = board[x][y] + 1;
                q.push(make_pair(xnew, ynew));
            }
        }
        
    }
    return -1;
}
