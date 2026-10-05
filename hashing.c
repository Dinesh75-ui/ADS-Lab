#include<stdio.h>

#define SIZE 10

int table[SIZE];

void init(){
    for (int i = 0; i < SIZE; i++){
        table[i] = -1;
    }    
}

int hashFunc(int key){
    return key%SIZE;
}

void insert(int key){
    int index = hashFunc(key);
    while(table[index] != -1){
        index = (index + 1)%SIZE;
    }
    table[index] = key;
}

void delete(int key){
    int index = hashFunc(key);
    while (table[index] != -1){
        if (table[index] == key){
            table[index] = -1;
            printf("Value deleted\n");
            return;
        }
        index = (index + 1)%SIZE;
    }
    printf("Value not found to delete\n");
}


int search(int key){
    int index = hashFunc(key);
    int start = index;
    while(table[index] != -1){
        if(table[index] == key){
            return index;
        }
        index = (index + 1)%SIZE;

        if(index == start){
            break;
        }
    }
    return -1;
}

void update(int oldKey, int newKey)
{
    int index = search(oldKey);

    if(index != -1)
    {
        table[index] = newKey;
        printf("Value updated\n");
    }else{
        printf("Value to be updated not found\n");
    }
}

void display(){
    printf("Elements in hash table: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ",table[i]);
    }
    printf("\n");
}

int main(){
    init();
    int n = 5;
    int a[] = {5, 10, 11 ,21 ,32};
    for (int i = 0; i < n; i++){
        insert(a[i]);
    }
    display();
    update(10,20);

    if(search(11)){
        printf("Key Value found\n");
    }else{
        printf("Value not found\n");
    }
    display();
    delete(20);
    display();

}