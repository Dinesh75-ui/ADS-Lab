#include<stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition( int a[], int low, int high){
    int pivot = high;
    int i = low - 1;
    int j = low;
    while (j < high){
        if(a[j] < a[pivot]){
            i++;
            swap(&a[i],&a[j]);
        }
        j++;
    }
    swap(&a[i+1], &a[pivot]);

    return i + 1;
}

void quickSort(int a[], int low, int high){
    if (low < high){
        int pivotIndex = partition(a,low,high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex+1, high);

    }
}

int main(){
    int n;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n);
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    
}