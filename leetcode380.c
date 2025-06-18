#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"
struct hash {
    int key;
    int value;
    UT_hash_handle hh;
};
typedef struct 
{
    /* data */
    int* arr;
    int size;
    struct hash* hashTable;
}RandomizeSet;

RandomizeSet* randomizeSetCreate() {
    RandomizeSet* r = malloc(sizeof(RandomizeSet));
    r->arr  = malloc(sizeof(int)*5000);
    r->size = 0;
    r->hashTable = NULL;
    return r;
}
bool randomizedSetInsert(RandomizeSet* obj, int val) {
    struct hash *h;
    HASH_FIND_INT(obj->hashTable, &val, h);

    if(!h) {
        h = malloc(sizeof(struct hash));
        h->key = val;
        obj->arr[obj->size] = val;
        h->value = obj->size;
        obj->size++;
        HASH_ADD_INT(obj->hashTable, key, h);
        return true;
    }
    return false;
}
bool randomizeSetRemove(RandomizeSet* obj, int val) {
    struct hash *h1, *h2;
    HASH_FIND_INT(obj->hashTable, &val, h1);
    
    if(h1) {
        obj->arr[h1->value] = obj->arr[obj->size-1];
        HASH_FIND_INT(obj->hashTable, &obj->arr[obj->size-1],h2);
        h2->value = h1->value;
        obj->size--;
        HASH_DEL(obj->hashTable,h1);
        return true;
    }
    return false;
}
int randomizeSetGetRandom(RandomizeSet* obj) {
    return obj->arr[rand()%obj->size];
}
void randomizeSetFree(RandomizeSet* obj) {
    free(obj->arr);
    free(obj);
}
int main(){
    int val_1 = 1;
    RandomizeSet* obj = randomizeSetCreate();
    bool param_1 = randomizedSetInsert(obj,val_1);
    bool param_2 = randomizeSetRemove(obj,val_1);
    int  param_3 = randomizeSetGetRandom(obj);
    randomizeSetFree(obj);
   
    return 0;
}