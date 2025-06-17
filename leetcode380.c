#include <stdlib.h>
struct s1 {
    int a;
    char b;
    short c;
};
struct s2 {
    char a;
    short b;
    int c; //123
};
int main(){
    //測試
    //test分支測試
    //test分支測試2
    printf("s1 size is %d and s2 is %d" , sizeof(struct  s1),sizeof(struct s2));  
}