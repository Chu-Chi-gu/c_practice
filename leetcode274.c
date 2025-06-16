#include <stdio.h>
#include <stdlib.h>
int main(){
    //case1
    int nums[] = {3,0,6,1,5};

    //case2
    //int nums[] = {1,3,1};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = hIndex(nums,numsSize);
    printf("%d",ans);
    return 0;
}
int compare_function(const void *a,const void *b) {
    int *x = (int *) a; 
    int *y = (int *) b;
    return *y - *x; //大到小
}
int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize,sizeof(int),compare_function);
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] <= i) {
            return i;
        }
    }
    return citationsSize;
}