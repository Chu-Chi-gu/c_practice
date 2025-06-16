#include <stdio.h>
int main(){
    //case1
    int nums[] = {7,6,4,3,1};
    int numsSize = sizeof(nums)/sizeof(int);
    int ans = maxProfit(nums, numsSize);
    printf("%d\n",ans);
    return 0;
}
int maxProfit(int* prices, int pricesSize) {
   int low_price = prices[0];
   int profit = 0;
   for(int i = 1; i < pricesSize; i++) {
        if( low_price > prices[i] ) {
            low_price = prices[i];
        }else{
            if( profit < (prices[i]-low_price)){
                profit = prices[i]-low_price;
            }
        }
   } 
   return profit;
}