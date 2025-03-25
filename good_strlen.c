int my_strlen(const char* s){
        const char* s2;
        for(s2=s;*s;s++)
                ;
        return s2-s;
}
