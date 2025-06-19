#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000
#define HASH_SIZE 10007

typedef struct{
    int idx;
    int value;
    bool used;
}HashNode;

typedef struct 
{
    int* arr;
    int size;
    HashNode* hash;
}RandomizeSet;

unsigned int hashFunc(int val) {
    return abs(val)%HASH_SIZE;
}
int hashFind(HashNode* hash, int val) {
    int h = hashFunc(val);
    while(hash[h].used) {
        if(hash[h].value == val) {
            return h;
        }
        h = (h+1) % MAX_SIZE;
    }
    return h;
}

RandomizeSet* randomizeSetCreate() {
    RandomizeSet* r = malloc(sizeof(RandomizeSet));
    r->arr  = malloc(sizeof(int)*MAX_SIZE);
    r->size = 0;
    r->hash = calloc(HASH_SIZE,sizeof(HashNode));
    return r;
}
bool randomizedSetInsert(RandomizeSet* obj, int val) {
    
    int index = hashFind(obj->hash, val);
    if(obj->hash[index].used && obj->hash[index].value == val) {
        return false;
    }
    obj->arr[obj->size]    = val;
    obj->hash[index].value = val;
    obj->hash[index].idx   = obj->size;
    obj->hash[index].used  = true;
    obj->size++;
    return true;
}
bool randomizeSetRemove(RandomizeSet* obj, int val) {
    int index = hashFind(obj->hash, val);
    if( !(obj->hash[index].used) || obj->hash[index].value != val ) {
        return false;
    }
    
    int idx     = obj->hash[index].idx;
    int lastVal = obj->arr[obj->size - 1];

    obj->arr[idx] = lastVal;

    int lastH = hashFind(obj->hash, lastVal);
    while( obj->hash[lastH].value != lastVal ) {
        lastH = (lastH + 1) % MAX_SIZE;
    }
    obj->hash[lastH].idx = idx;

    obj->hash[index].used = false;
    obj->size--;
    return true;
}
int randomizeSetGetRandom(RandomizeSet* obj) {
    int r = rand() % obj->size;
    return obj->arr[r];
}
void randomizeSetFree(RandomizeSet* obj) {
    free(obj->arr);
    free(obj->hash);
    free(obj);
}
int main(){
    int val_1 = 1;
    RandomizeSet* obj = randomizeSetCreate();
    
    bool param_1 = randomizedSetInsert(obj,3);
    printf("param1=%d\n",param_1);
    bool param_2 = randomizeSetRemove(obj,2);
    printf("param2=%d\n",param_2);
    int  param_3 = randomizeSetGetRandom(obj);
    printf("param3=%d\n",param_3);
    randomizeSetFree(obj);
   
    return 0;
}