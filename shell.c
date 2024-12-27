#include <stdio.h>

int main(void){
    int arr[] = {14,33,42,10,35,19,27,44};
    int incr = 4;
    while(incr>0){
        for(int i = incr ; i<=8 ; i++){
            int j = i - incr;
            while(arr[j]>arr[j+incr] && j>=0){
                int temp = arr[j];
                arr[j] = arr[j+incr];
                arr[j+incr] = temp;
                j = j-incr;
            }
        }
        incr = incr/2;
        for(int i=0;i<8;i++)
            printf("%d,",arr[i]);
        printf("\n");
    }
}
