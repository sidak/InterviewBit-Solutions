string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cpy = A;
    string ans="";
    char col;
    while(A>0){
        int dig = A%26;
        A/=26;
        if(dig == 0){
            dig = 26;
            A --;
        }
        col = 'A' + (dig-1);
        ans = col + ans;
        
        // col = 'A' + (A-1)%26;
        // ans = col + ans;
        // ans = (ans-1)/26;
    }
    return ans;
}
