#include<stdio.h>
#include<string.h>

int main(){
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    int i,j;

    int n = strlen(text);
    int m = strlen(pattern);

    for (i = 0; i < n - m; i++){
        for (j = 0; j < m; j++){
            if(text[i + j] != pattern[j]){
                break;
            }
        }
        if(j == m){
            printf("Pattern found at position %d\n", i+1);
            return 0;
        }
        
    }
    printf("Pattern not found\n");

    return 0;
       
}