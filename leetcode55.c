#include <stdbool.h>
#include <stdio.h>
int main(){
    int nums[] = {2,3,1,1,4};
    int numsSize = sizeof(nums)/sizeof(int);
    bool canJump(int* nums, int numsSize);
    bool ans = canJump(nums,numsSize);
    
    printf("%d",ans);
    return 0;
}
bool canJump(int* nums, int numsSize) {
    if( numsSize == 1 ) return true;
    int reachable = 0;
    for(int i = 0; i < numsSize; i++) {
        if( i > reachable ){return false;}
        if( (i + nums[i] ) > reachable) {
            reachable = i + nums[i];
        }
    }
    return true;
}