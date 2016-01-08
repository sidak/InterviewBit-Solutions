int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string str;
    if(A.size()==0) return 1;
    
    int sz = A.size();
    for(int i=0; i<sz; i++){
        char c = A[i];
        if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')){
            if(c>='A' && c<='Z'){
                c = ((char)(c + 32));
            }
            str.push_back(c);
        }
    }
    
    int i=0, j = str.size()-1;
    
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
