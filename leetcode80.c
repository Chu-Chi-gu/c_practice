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
    //解法1
    /*int index = 0;
    int count = 0;
    for(int i = 1; i < numsSize; i++) {
        if( nums[i] != nums[index] ) {
            nums[++index] = nums[i];
            count = 0;
        }else{
            count++;
            if( count < 2 ) {
                nums[++index] = nums[i];
            }
        }
    }
    return index;*/
    
    //解法2
    if(numsSize <= 2){
        return numsSize;
    }
    int index = 2;
    for(int i=2; i < numsSize; i++){
        if(nums[i]!=nums[index-2]){
            nums[index++]=nums[i];
        }
    }
    return index;
}