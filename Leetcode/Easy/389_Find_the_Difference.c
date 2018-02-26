char findTheDifference(char* s, char* t) {
    if(s==NULL||t==NULL) return '\0';
    char ret=0;
    for(int i=0;i<strlen(t);i++){
        char c=t[i];
        ret^=c;//异或
    }
    for(int i=0;i<strlen(s);i++){
        char c=s[i];
        ret^=c;
    }
    return ret;
}
