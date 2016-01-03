int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sz = A.size();
    if(sz==0) return -1;
    else if (sz<3) return A[0];
    
    vector< pair<int, int>  > elements;
    
    for(int i =0; i<sz; i++){
        
        if(elements.size() == 0){
            elements.push_back(make_pair(A[i], 1));
        }
        else if(elements.size()==1){
            if(A[i]==elements[0].first){
                elements[0].second ++;
            }
            else{
                elements.push_back(make_pair(A[i], 1));
            }
        }
        else{
            bool isDiff = true;
            for(int j =0; j<2; j++){
                if(A[i] == elements[j].first){
                    isDiff = false;
                    elements[j].second++;
                }
            }
            if(isDiff){
                vector< pair<int, int> > new_elements;
                for(int j=0; j<2; j++){
                    elements[j].second--;
                    if(elements[j].second!=0){
                        new_elements.push_back(elements[j]);
                    }
                }
                elements = new_elements;
            }
        }
        
    }
    for(int i=0; i<elements.size(); i++){
        
        int val = elements[i].first;
        int ct =0;
        for(int j=0; j<sz; j++){
            if(A[j]==val)ct++;
        }
        if(ct>(sz/3)){
            return val;
        }
    }    
    return -1;
}

