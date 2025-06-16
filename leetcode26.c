#include <stdio.h>
int main(){
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = removeDuplicates(nums,numsSize);
    for(int i = 0; i < numsSize; i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("%d",ans);
    return 0;
}
int removeDuplicates(int* nums, int numsSize) {
    int j = 1;
    for(int i = 1; i < numsSize; i++) {
        if( nums[i] != nums[i-1] ){
            nums[j++] = nums[i];
        }
    }
    return j;
}