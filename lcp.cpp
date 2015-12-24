string findLcp(string a, string b){
    string ans;
    if(a.empty() || b.empty()){
        return ans;
    }
    int sz_a = a.size();
    int sz_b = b.size();
    
    int i =0;
    
    while(i<a.size() && i<b.size()){
        if(a[i]==b[i]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            break;
        }
    }
    return ans;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans;
    if(A.empty()){
        return ans;
    }
    ans = A[0];
    if(A.size() == 1){
        return ans;
    }
    
    for(int i=1; i<A.size(); i++){
        ans = findLcp(ans, A[i]);
        if(ans.empty()) break;
    }
    return ans;
}

