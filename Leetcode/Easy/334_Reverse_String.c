char* reverseString(char* s) {
    if(!s) return NULL;
    for(int i=0,j=strlen(s)-1;i<j;i++,j--){
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
    return s;
}
