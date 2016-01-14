double intlog(double base, double x) {
    return (log(x) / log(base));
}
bool Solution::isPower(int A) {
    int rt = (int)(sqrt(A));
    for(int i=2; i<=rt; i++){
        double lg = intlog(A, i);
        if(fmod(lg, 1)==0) return true;
    }
    
    return false;
}
