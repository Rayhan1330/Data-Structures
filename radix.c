#include <stdio.h>

int main(void){
    int arr[] = {90,69,43,21,10};
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<5-j-1;k++){
                if(i==0){
                    if(arr[k+1]%10<arr[k]%10){
                        int temp = arr[k];
                        arr[k] = arr[k+1];
                        arr[k+1] = temp;
                    }
                }
                else if(i==1){
                    if(arr[k+1]/10<arr[k]/10){
                        int temp = arr[k];
                        arr[k] = arr[k+1];
                        arr[k+1] = temp;
                    }
                }
            }
        }
    }
    for(int i =0;i<5;i++)
        printf("%d\n",arr[i]);
}
