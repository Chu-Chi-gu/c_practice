#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int sumUp(int index) {
    if(index == 0) return 0;
    return (index*(1+index))/2;
}
int max(int val1, int val2) {
    if( val1 > val2 ) {
        return val1;
    }
    return val2;
}
int candy(int* ratings, int ratingsSize) {
    //每個小孩至少一個
    //更高比例的小孩會拿得比鄰居(左右)多
    if( ratingsSize == 1 ) return 1;

    //解法1 雙向掃描
    /*int* count = malloc(ratingsSize * sizeof(int));
    for(int i = 0; i < ratingsSize; i++) {
        count[i] = 1;
    }

    for(int i = 1; i < ratingsSize; i++) {
        if( ratings[i] > ratings[i-1] ) {
            count[i] = count[i-1] + 1;
        }
    }
    for(int i = ratingsSize-2; i >= 0; i--) {
        if( ratings[i] > ratings[i+1] ) {
            if(count[i] < count[i+1]+1) {
                count[i] = count[i+1]+1;
            }
            
        }
    }
    int total = 0;
    for(int i = 0; i < ratingsSize; i++) {
        total += count[i];
    }
    return total; */

    //解法2
    //有四種狀況 1. 上升段接準平坦段
    //          2. 上升段接下降段
    //          3. 下降段接準平坦段
    //          4. 下降段接上升段
    int total = 0, previousState = 0, nowState = 0, ups = 0, downs = 0;
    for(int i = 1; i != ratingsSize; i++) {
        nowState = ( ratings[i-1] < ratings[i] )? 1: ((ratings[i-1] == ratings[i])? 0: -1);
        if( (previousState > 0 && !nowState) || (previousState < 0 && nowState >= 0) ) {
            total += sumUp(ups) + sumUp(downs) + max(ups,downs);
            ups = downs = 0;
        }
        (nowState == 1)? ++ups: ((nowState == -1)? ++downs: ++total);
        previousState = nowState;
    }
    return (total += sumUp(ups) + sumUp(downs) + max(ups,downs) + 1);
}
int main() {
    //case1 
    int ratings[] = {2,5,7,7};  //2 1 2 = 5  

    //case2 
    //int ratings[] = {1,2,2}; //1 2 1 = 4

    //case3
    //int  ratings[] = {1,2,3}; // 1 2 3 = 6 

    //case4 
    //int  ratings[] = {1,3,2,2,1}; // 1 2 1 2 1 = 7  

    //case5 
    //int  ratings[] = {1,3,4,5,4,3}; 
    int ratingsSize = sizeof(ratings)/sizeof(int);
    int ans = candy(ratings,ratingsSize);
    printf("ans=%d",ans);
    return 0;
}