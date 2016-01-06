int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool isNeg = false;
    if(A<0) {
        isNeg = true;
        A = A*(-1);
    }
    
    int rev = 0;
    while(A>0){
        int dig = A%10;
        int old_rev = rev;
        rev = rev*10 + dig;
        if(rev<0 && old_rev>0){
            if(!(isNeg && rev==INT_MIN)) return 0;
        }
        A/=10;
    }
    
    if(isNeg){
        if(rev==INT_MIN) return rev;
        else return (-1)*rev;
    }
    
    return rev;
    
    
}
