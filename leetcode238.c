#include <stdlib.h>
#include <stdio.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* output  = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    output[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        output[i] = nums[i-1] * output[i-1];  //output[i]表前i-1個前綴乘積
    }
    
    int right = 1;
    for(int i = numsSize-1; i >= 0; i--) {
        output[i] *= right;
        right *= nums[i];
    }

    return output;
}
int main(){
    //case1
    int nums[] = {1,2,3,4};

    //case2
    //int nums[] = {-1,1,0,-3,3};
    int numsSize = sizeof(nums)/sizeof(int);
    int returnSize;
    int* ans = productExceptSelf(nums,numsSize,&returnSize);
    int ansSize = sizeof(ans)/sizeof(int);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ",ans[i]);
    }
    free(ans);
    return 0;
}