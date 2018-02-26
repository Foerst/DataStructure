int hammingWeight(uint32_t n) {
    int sum=0;
    while(n){
        int s=n%2;
        if(1==s) sum++;
        n/=2;
    }
    return sum;
}
