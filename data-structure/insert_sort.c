#include <stdio.h>
#define SIZE 6
int main() {
    int i, j, tmp;
    int data[SIZE] = {5,7,1,4,3,2};
    for (i = 1; i < SIZE; i++) {
        tmp = data[i];
        for (j = i-1; j >= 0 && data[j] > tmp; j--) {
            data[j+1] = data[j];
        }
        data[j+1] = tmp;
    }
    
    for(int k=0;k<SIZE;k++)
        printf("%d ", data[k]);
}