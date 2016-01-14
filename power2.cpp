double intlog(double base, double x) {
    return (log(x) / log(base));
}
bool Solution::isPower(int A) {
    
    if(A==1) return true;
    
    int rt = (int)(floor(sqrt(A)));
    for(int i=2; i<=rt; i++){
        double lg = intlog(i, A);
        if(abs(fmod(lg, 1.0) - 0) < 0.000000001) return true;
    }
    
    return false;
}
