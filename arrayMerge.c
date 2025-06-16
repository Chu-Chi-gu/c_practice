#include <stdio.h>
int main(){
    //case1
    //int nums1 [] = {1,2,3,0,0,0};
    //int m = 3;
    //int nums2 [] = {2,5,6};
    //int n = 3;

    //case2
    //int nums1 [] = {1};
    //int m = 1;
    //int nums2 [] = {};
    //int n = 0;

    //case3
    int nums1 [] = {0};
    int m = 0;
    int nums2 [] = {1};
    int n = 1; 
    int nums1Size = sizeof(nums1)/sizeof(int);
    int nums2Size = sizeof(nums2)/sizeof(int);
    
    merge(nums1,nums1Size,3,nums2,nums2Size,3);
    for(int i = 0; i < nums1Size; i++) {
        printf("%d\n", nums1[i]);
    }
    return 0;
}
void merge(int* nums1, int nums1Size, int m, int* nums2,int nums2Size,int n){
    while(m != 0 && n != 0) {
        if( *(nums1 + m - 1) <= *(nums2 + n - 1) ) {
            *(nums1 + nums1Size - 1) = *(nums2 + n - 1);
            n--;
        }else{
            *(nums1 + nums1Size - 1) = *(nums1 + m - 1);
            m--;
        }
        nums1Size--;
    }
    while( n != 0) {
        *(nums1 + nums1Size - 1) = *(nums2 + n - 1);
        n--;
        nums1Size--;
    }
}