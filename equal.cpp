struct indices{
    int a, b, c, d;
};
bool compare(indices my, indices other){
    if( my.a == other.a){
        if(my.b == other.b){
            if(my.c == other.c){
                return my.d < other.d;
            }
            else {
                return my.c < other.c;
            }
        }
        else{
            return my.b < other.b;
        }
    }
    else{
        return my.a < other.a;
    }
}
bool validIndices(int a, int b, int c, int d){
    if(a<b && c<d && a<c && b!=c && b!=d) return true;
    else return false;
}
vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int sz = A.size();
    if(sz == 0){
        return ans;
    }
    vector< indices > solns;
    // instead of vector just a single element would be fine 
    unordered_map< int, vector< pair < int, int> > > hmap;
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            int sum = A[i] + A[j];
            if(hmap.find(sum) != hmap.end()){
                
                for(int k = 0; k<hmap[sum].size(); k++){
                    if(validIndices(hmap[sum][k].first, hmap[sum][k].second,i,j)){
                        struct indices soln;
                        soln.c = i;
                        soln.d = j;
                        soln.a = hmap[sum][k].first;
                        soln.b = hmap[sum][k].second;
                        solns.push_back(soln);
                    }
                }
               
            }
            else{
                vector< pair<int, int> > temp;
                hmap[sum] = temp;
                hmap[sum].push_back(make_pair(i,j));
            }
            
        }
    }
    sort(solns.begin(), solns.end(), compare);
    if(solns.size()>0){
        ans.push_back(solns[0].a);
        ans.push_back(solns[0].b);
        ans.push_back(solns[0].c);
        ans.push_back(solns[0].d);
    }
    return ans;
}
