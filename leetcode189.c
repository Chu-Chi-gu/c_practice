#include <stdio.h>
int main(){
    //case1
    int nums[] = {1,2,3,4,5,6};
    int numsSize = sizeof(nums)/sizeof(int);
    int k = 3;

    //case2
    //int nums[] = {-1,-100,3,99};
    //int numsSize = sizeof(nums)/sizeof(int);
    //int k = 2;
    rotate(nums, numsSize, k);
    printf("\n");
    for(int i = 0 ; i < numsSize; i++) {
        printf("%d ",nums[i]);
    }
    return 0;
}
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if( k == 0 ) return;
    if( numsSize == 1) return;

    //最佳解
    int ta[numsSize], j = k;
    for(int i = 0;i < numsSize - k ; i++) ta[j++] = nums[i];
    for(int i = numsSize-k, j = 0; i < numsSize; i++) ta[j++] = nums[i];
    for(int i = 0; i < numsSize; i++) nums[i] = ta[i];

    //O(1)
    /*int start = 0;
    int temp;
    int temp2 = nums[0];
    int index  = 0;
    for(int i = 0; i < numsSize; i++) {
        index = (index+k) % numsSize;
        temp = nums[index]; 
        nums[index] = temp2;
        temp2 = temp;
        if(index == start) {
            start++;
            index = start;
            temp2 = nums[index];
        }
    }*/

    //time out
    /*int step = 0;
    int temp,temp2,index;
    while( step < k ) {
        temp,temp2 = nums[0];
        for(int i = 0; i < numsSize; i++) {
            index = (i+1) % numsSize;
            temp = nums[index]; 
            nums[index] = temp2;
            temp2 = temp;
        }
        step++;
    }*/
}