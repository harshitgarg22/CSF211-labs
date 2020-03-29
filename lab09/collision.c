long collision(char **list, long len, long baseNumber, long tableSize){
    long num = 0;
    
    for(long i = 0; i < len; ++i){
        for(long j = i; j < len; ++j){
            if(hashfn(list[i], baseNumber, tableSize) == hashfn(list[j], baseNumber, tableSize)){
                num += 1;
            }
        }
    }

    return num;
}