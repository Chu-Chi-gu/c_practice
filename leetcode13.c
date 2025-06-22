#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mapValue(char s) {
    switch (s)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}
int romanToInt(char* s) {
    int total = 0, curr = 0, next = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        curr = mapValue(s[i]);
        next = mapValue(s[i+1]);
        if(curr < next ) {
            total += (next - curr);
            i = i + 1;
        }else{
            total += curr;
        }
    }
    return total;
}
int main() {
    char* test = "LVIII";
    int ans = romanToInt(test);
    printf(",ans = %d", ans);
    return 0;
}