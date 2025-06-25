#include <stdlib.h>
#include <stdio.h>
int lengthOfLastWord(char* s) {
    int count   = 0;
    int isBlank = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if( s[i] == ' ') {
            isBlank = 1;
            continue;
        }
        if(isBlank == 1) {
            isBlank = 0;
            count = 0;
        }
        count++;
    }   
    return count;
}
int main() {
    char* s = "this is world ";
    int ans = lengthOfLastWord(s);
    printf("ans = %d;", ans);
    return 0;
}