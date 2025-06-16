#include <stdio.h>
int main(){
    //case1
    //int nums[] = {3,2,2,3};
    //int val = 3;

    //case1
    //int nums[] = {4,5};
    //int val = 4;

    //case3 
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = removeElement(nums,numsSize,val);
    printf("%d", ans);
    return 0;
}
int removeElement(int* nums, int numsSize, int val) {
    //two point
    /*if( numsSize == 0) return 0;
    int i = 0;
    int j = numsSize - 1;
    while( i < j ) {
        if( nums[i] == val ) {
            if( nums[j] == val ) {
                j--;
            }else{
                nums[i++] = nums[j--];
            }
        }else{
            i++;
        }
    }
    if( i == j) {
        if(nums[i] != val) {
            i++;
        }
    }
    return i;*/

    //較簡單的寫法
    int j = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[j++] = nums[0];
        }
    }
    return j;
}