int reverse(int x) {
        int flag=x>0?1:-1,res=0;
        x=x>0?x:-x;
        int max = ~ (1 << 31);
        while(x>0){
            if(res*10.0+x%10>max)return 0;
            res = res*10+x%10;
            x/=10;
        }
        return res*flag;
    }
