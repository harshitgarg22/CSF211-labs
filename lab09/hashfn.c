long hashfn(char *s, long baseNumber, long tableSize){
    long sum = 0;
    char c;
    int i;
    for(c = s[0], i = 0; c != '\0'; ++i, c = s[i]){
        sum += c;
    }

    return ((sum % baseNumber) % tableSize);
}