#include <stdlib.h>
#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    //如果無法繞一圈，return -1
    //條件為 current_gas + gas[index] - cost[index] >= 0 才能往前走

    //方法1遍例
    /*int index = 0;
    int current_gas = 0;
    while(index < gasSize) {
        current_gas = 0;
        for(int i = index; ;) {
            current_gas = current_gas + gas[i] - cost[i];
            if( current_gas < 0 ) {
                break;
            }
            i = (i+1) % gasSize;
            if( i == index) {
                return index;
            }
        }
        index++;
    }
    return -1;*/

    //方法2
    //int gas[] = {5,1,2,3,4};
    //int cost[] = {4,4,1,5,1};
    int total = 0, current_gas = 0, index = 0;
    for(int i = 0; i < gasSize; i++) {
        int gain = gas[i] - cost[i];
        
        total += gain;
        current_gas += gain;
       
        if(current_gas < 0) {
            index = i + 1;
            current_gas = 0;
        }
    }
    return (total < 0)? -1:index;
}
int main() {
    //case1
    //int gas[] = {1,2,3,4,5};
    //int cost[] = {3,4,5,1,2};

    //case2
    //int gas[] = {2,3,4};
    //int cost[] = {3,4,3};

    //case3
    int gas[] = {5,1,2,3,4};
    int cost[] = {4,4,1,5,1};

    int gasSize = sizeof(gas) / sizeof(int);
    int costSize = sizeof(cost) / sizeof(int);
    int ans = canCompleteCircuit(gas,gasSize,cost,costSize);
    printf("ans=%d",ans);
    return 0;
}