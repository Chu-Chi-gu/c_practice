#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* intToRoman(int num) {
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L" ,"XL", "X", "IX", "V", "IV", "I"};

    char* ans = malloc(sizeof(int) * 20 );
    ans[0] = '\0';
    for(int i = 0; i < 13 && num > 0; i++) {
        while( num >= value[i] ) {
            strncat(ans,symbol[i],2);
            num -= value[i];
        }
    }
    return ans;
}
int main() {
    int num = 3749;
    char* ans = intToRoman(num);
    printf("integer=%d, ans=%s",num,ans);
    free(ans);
    return 0;
}