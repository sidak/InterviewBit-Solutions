int Solution::fibsum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> num;
    num.push(1);
    num.push(1);
    while(num.top()<A){
        int first = num.top();
        num.pop();
        int second = num.top();
        num.push(first);
        
        int third = first + second;
        if(third<=A){
            num.push(third);
        }
        else{
            break;
        }
        
    }
    
    int ans =0;
    while(A>0 && !num.empty()){
        while(A>=num.top()){
            A-= num.top();
            ans++;
        }
        num.pop();
    }
    return ans;
}
