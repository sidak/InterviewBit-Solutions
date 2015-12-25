int Solution::candy(vector<int> &ratings) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> candies;
    if(ratings.empty()){
        return 0;
    }
    int sz = ratings.size();
    for(int i=0; i<sz; i++){
        candies.push_back(1);
    }
    for(int i=1; i<sz; i++){
        if(ratings[i]>ratings[i-1]){
            candies[i] = candies[i-1]+1;
        }
    }
    for(int i=sz-2; i>=0; i--){
        if(ratings[i]>ratings[i+1]){
            candies[i] = max(candies[i], candies[i+1] +1);
        }
    }
    
    int ans =0;
    for(int i=0; i<sz; i++){
        ans+= candies[i];
    }
    return ans;
}
