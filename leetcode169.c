#include <stdio.h>
int main(){
    int nums[] = {3,2,2};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = majorityElement(nums, numsSize);
    printf("\n");
    printf("%d",ans);
    return 0;
}
int majorityElement(int* nums, int numsSize) {
    int index = nums[0];
    int cnt   = 1;
    for(int i = 1; i < numsSize; i++) {
        if( nums[i] != index ) {
            cnt--;
            if(cnt == 0) {
                index = nums[i];
                cnt++;
            }
        }else{
            cnt++;
        }
    }
    return index;
}