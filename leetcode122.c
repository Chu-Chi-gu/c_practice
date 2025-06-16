#include <stdio.h>
int main(){
    //case1
    int nums[] = {7,1,5,3,6,4};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = maxProfit(nums, numsSize);
    printf("%d\n",ans);
    return 0;
}
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for(int i = 1; i < pricesSize; i++) {
        if(prices[i-1] < prices[i]) {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}