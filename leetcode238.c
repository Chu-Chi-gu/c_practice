#include <stdio.h>
int main(){
    //case1
    int nums[] = {1,2,3,4};

    //case2
    //int nums[] = {-1,1,0,-3,3};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = productExceptSelf(nums,numsSize,0);
    printf("%d",ans);
    return 0;
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
}