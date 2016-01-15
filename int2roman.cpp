
string Solution::intToRoman(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string hmap[4000];
    
    hmap[1]="I";
    hmap[2] = "II";
    hmap[3] = "III";
    hmap[4] = "IV";
    hmap[5] = "V";
    hmap[6] = "VI";
    hmap[7] = "VII";
    hmap[8] = "VIII";
    hmap[9] = "IX";
    hmap[10] = "X";
    
    for(int i=11; i<=39 && i<=A; i++){
        hmap[i] = ""+ hmap[10] + hmap[i-10];
    }
    hmap[40] = "XL";
    for(int i=41; i<=49 && i<=A; i++){
        hmap[i] = ""+ hmap[40] + hmap[i-40];
    }
    hmap[50] = "L";
    for(int i=51; i<=89 && i<=A; i++){
        hmap[i] = ""+ hmap[50] + hmap[i-50];
    }
    hmap[90] = "XC";
    for(int i=91; i<=99 && i<=A; i++){
        hmap[i] = ""+ hmap[90] + hmap[i-90];
    }
    hmap[100] = "C";
    for(int i=101; i<= 399 && i<=A; i++){
        hmap[i] = ""+ hmap[100]+hmap[i-100];
    }
    hmap[400] = "CD";
    for(int i= 401; i<=499 && i<=A ; i++){
        hmap[i] = ""+ hmap[400] + hmap[i-400];
    }
    hmap[500] = "D";
    for(int i=501; i<=899 && i<=A ; i++){
        hmap[i] = ""+ hmap[500] + hmap[i-500];
    }
    hmap[900] = "CM";
    for(int i=901; i<=999 && i<=A; i++){
        hmap[i] = ""+ hmap[900] + hmap[i-900];
    }
    hmap[1000] = "M";
    for(int i=1001; i<=3999 && i<=A; i++){
        hmap[i] = ""+ hmap[1000] + hmap[i-1000];
    }
    
    return hmap[A];
}

