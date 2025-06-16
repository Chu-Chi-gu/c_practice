#include <stdio.h>
int main(){
    //case1
    int nums[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};

    //case2
    //int nums[] = {2,3,1,1,4};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = jump(nums,numsSize);
    printf("%d",ans);
    return 0;
}
int jump(int* nums, int numsSize) {
    if( numsSize == 1  ) return 0;
    int reachable = 0;
    int index     = 0; //每次最遠位置
    int cnt       = 0;
    for(int i = 0; i < numsSize-1; i++) {
        if( i + nums[i] >=  reachable ) {
            reachable = i + nums[i];
        }
        if( i == index ) {
            index = reachable;
            cnt++; 
        }
    }
    return cnt;
}