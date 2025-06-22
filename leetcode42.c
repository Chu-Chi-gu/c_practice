#include <stdlib.h>
#include <stdio.h>
int product(int val1, int val2) {
    return val1*val2;
}
int min(int val1, int val2) {
    if( val1 < val2) {
        return val1;
    }
    return val2;
}
int max(int val1, int val2) {
    if(val1 > val2) {
        return val1;
    }
    return val2;
}
int trap(int* height, int heightSize) {
    //heigth表示牆的高度，計算牆與牆之間可以容納多少水。

    //方法1，雙指針
    /*int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    while(left < right) {
        if(height[left] < height[right] ){
            if(height[left] > leftMax) {
                leftMax = height[left];
            }else{
                water += leftMax - height[left];
            }
            left++;
        }else{
            if(height[right] > rightMax) {
                rightMax = height[right];
            }else{
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;*/

    //方法2，動態規劃
    /*int* left = calloc(heightSize, sizeof(int));
    int* right = calloc(heightSize, sizeof(int));
    int water = 0;

    left[0] = height[0];
    for(int i = 1; i < heightSize; i++) {
        left[i] = max(height[i],left[i-1]);
    }
    printf("\n");
    right[heightSize-1] = height[heightSize-1];
    for(int i = heightSize-2; i >= 0; i--) {
        right[i] = max(height[i],right[i+1]);
    }
    for(int i = 0; i < heightSize; i++ ) {
        int minHeight = min(left[i],right[i]);
        water += minHeight - height[i];
    }
    free(left);
    free(right);
    return water;*/

    //狀況分析: 
    //1.持續遞增
    //2.持續遞減
    //3.波動
    int water = 0;
    int left = 0, right = 1;


}

int main() {
    //case1 
    //int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    //case2
    int height[] = {3,2,1};
    int heightSize = sizeof(height) / sizeof(int);
    int ans = trap(height, heightSize);
    printf(",ans = %d",ans);
    return 0;
} 