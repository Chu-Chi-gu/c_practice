#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    //解法1
    /*if( strsSize == 0 ) return "";
    int index = 0;
    int min = __INT_MAX__;
    for(int i = 1; i < strsSize; i++) {
        for(int j = 0; strs[i][j] != '\0'; j++) {
            if( strs[0][j] == strs[i][j] && index <= min ) {
                index++;
            }else{
                break;
            }
        }
        min   = index;
        index = 0;
    }
    if( min == __INT_MAX__) return strs[0];
    char* result = (char*)malloc((min + 1) * sizeof(char));
    strncpy(result, strs[0], min);
    result[min] = '\0';
    return result;*/

    //解法2
    if( strsSize == 0) return "";
    char* result = (char*)malloc(sizeof(char) * strlen(strs[0]));
    strcpy(result, strs[0]);
    for(int i = 0; result[i] != '\0'; i++) {
        for(int j = 1; j < strsSize; j++) {
            if( strs[j][i] == '\0' || strs[j][i] != result[i]) {
                result[i] = '\0';
                return result;
            }
        }
    }
    return result;
}
int main() {
    //case1
    char* strs [] = { "flower","flow","flight" };
    //case2
    //char* strs[] = { "doga","rocecar","car" };
    char* ans = longestCommonPrefix(strs, 3);
    printf("%s,", ans);
    free(ans);
    return 0;
}