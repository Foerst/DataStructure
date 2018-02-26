int getSum(int a, int b) {
//    简而言之就是用异或算不带进位的和，用与并左移1位来算进位，然后把两者加起来即可
    while(b){
        int carry = a & b;  //与 进位
        a = a ^ b;   //异或和
        b = carry << 1;  //左移1位
    }  
    return a;  
}


int getSum(int a, int b) {
    if(b == 0){
        return a;
    }
    int num1 = a ^ b;
    int num2 = (a & b)<<1;
    return getSum(num1, num2);
}