//哈希表实现
//


#include <stdio.h>
#include <stdlib.h>

typedef int datatType ;
#define HashSize 13
#define NULLKEY -32768

/*Hash Table*/
typedef struct
{
    int elem[HashSize] ;
    int count ;
}HashTable;
/*InitHashTable*/
int InitHashTable(HashTable *&H)
{
    
    H = (HashTable *)malloc(sizeof(HashTable)) ;
    H->count = HashSize ;
    int i ;
    //H->elem = (int *)malloc(HashSize*sizeof(int)) ;
    for(i = 0; i < HashSize; i ++)
        H->elem[i] = NULLKEY ;
    
    return 1 ;
}

/*Hashing_Mod*/
int Hashing_Mod(datatType key)
{
    return key%HashSize ;
}

/*HashInsert*/
void HashInsert(HashTable *H, datatType key)
{
    int addr = Hashing_Mod(key) ;
    while (H->elem[addr] != NULLKEY)
    {
        addr = (addr + 1)% HashSize ;
    }
    H->elem[addr] = key ;
}

/*SearchHashTable*/
int SearchHashTable(HashTable *H, datatType key, int *addr)
{
    *addr = Hashing_Mod(key) ;
    
    while(H->elem[*addr] != key)
    {
        *addr = (*addr + 1)% HashSize ;
        if (H->elem[*addr] == NULLKEY || *addr == Hashing_Mod(key))
        {
            return 0 ;
        }
    }
    return 1 ;
}
//==================Auxiliary Code=================
/*PrintArray*/
void PrintArray(datatType *A, int n)
{
    int i ;
    for (i = 0; i < n; i ++)
    {
        printf("%d\t",A[i]) ;
    }
    printf("\n") ;
}

int main()
{
    //===================hashing================
    HashTable *H ;
    InitHashTable(H) ;
    int key[] = {12,67,56,16,25,37,22,29,15,47,48,34} ;
    for(int i = 0; i < HashSize - 1; i ++)
    {
        HashInsert(H,key[i]) ;
    }
    PrintArray(H->elem,HashSize) ;
    int *addr = (int *)malloc(sizeof(int)) ;
    int ans = SearchHashTable(H,47,addr) ;
    if (0 == ans)
    {
        printf("No Match !\n") ;
    }
    else
    {
        printf("Key is hashed at: %d\n",*addr) ;
    }
    return 0 ;
}
