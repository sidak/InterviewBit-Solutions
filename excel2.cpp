string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cpy = A;
    string ans="";
    char col;
    while(A>0){
        if(A<=26){
            col = 'A' + (A-1);
            ans = col + ans;
            break;
        }
        
        int dig = A%26;
        int num = A/26;
        if(dig == 0){
            num --;
        }
        
        A -= 26*num;
        col = 'A' + (num-1);
        ans = col + ans;
    }
    return ans;
}
