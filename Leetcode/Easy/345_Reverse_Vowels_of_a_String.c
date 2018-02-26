
bool isVowels(char a){
    return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
}

char* reverseVowels(char* s) {
    if(!s) return NULL;
    int i=0,j=(int)strlen(s)-1;
    while(i<j){
        char l=s[i];
        char r=s[j];
        if(!isVowels(l)) i++;
        if(!isVowels(r)) j--;
        if(isVowels(l)&&isVowels(r)&&l==r) {
            i++;
            j--;
        }
        if(isVowels(l)&&isVowels(r)&&l!=r){
            *(s+i)=r;
            *(s+j)=l;
            i++;
            j--;
        }
    }
    return s;
}
