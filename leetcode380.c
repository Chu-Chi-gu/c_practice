#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000
#define HASH_SIZE 10007

typedef struct {
    int idx;
    int val;
    bool used;
}HashNode;
typedef struct 
{
    int* arr;
    int size;
    HashNode* hash;
}RandomizeSet;

unsigned int hashFunc(int val) {
    return abs(val) % HASH_SIZE;
}
int hash_find(HashNode* hash, int val) {
    int h = hashFunc(val);
    while( hash[h].used ) {
        if( hash[h].val == val ) {
            return h;
        }
        h = (h+1) % HASH_SIZE;
    }
    return h;
}

RandomizeSet* randomizeSetCreate() {
    RandomizeSet* obj = malloc(sizeof(RandomizeSet));
    obj->arr = malloc(sizeof(int)*MAX_SIZE);
    obj->size = 0;
    obj->hash = calloc(HASH_SIZE, sizeof(HashNode));
    return obj;
}
bool randomizedSetInsert(RandomizeSet* obj, int val) {
    int index = hash_find(obj->hash, val);
    if( obj->hash[index].used == true && obj->hash[index].val == val ) {
        return false;
    }
    obj->hash[index].used = true;
    obj->hash[index].val  = val;
    obj->hash[index].idx  = obj->size;

    obj->arr[obj->size] = val;
    obj->size++;
    return true;
}
bool randomizeSetRemove(RandomizeSet* obj, int val) {
    int index = hash_find(obj->hash, val);
    if( obj->hash[index].used == false || obj->hash[index].val != val ) {
        return false;
    }

    int idx     = obj->hash[index].idx;
    int lastVal = obj->arr[obj->size-1];
    int lastH   = hash_find(obj->hash, lastVal);

    obj->size--;
    obj->arr[idx] = lastVal;
    obj->hash[lastH].idx = idx;
    obj->hash[index].used = false;
    return true;
}
int randomizeSetGetRandom(RandomizeSet* obj) {
   int index = rand() % obj->size;
   return obj->arr[index];
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
    bool param_2 = randomizeSetRemove(obj,3);
    printf("param2=%d\n",param_2);
    int  param_3 = randomizeSetGetRandom(obj);
    printf("param3=%d\n",param_3);
    randomizeSetFree(obj);
   
    return 0;
}