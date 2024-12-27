#include <stdio.h>

int main(void){
    int arr[] = {5,3,1,7,2,6,4};
    int no_of_swaps = 0;
    for(int i=2; i<=7; i++){
        int j = i-1;
        while(arr[j]<arr[j-1] && j>0){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j=j-1;
            no_of_swaps++;
        }
    }
    printf("No of swaps: %d\n",no_of_swaps);
    for(int i=0;i<7;i++)
        printf("%d\n",arr[i]);
}
