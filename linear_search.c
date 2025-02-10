#include <stdio.h>

int ls(int arr[], int key, int n){

    for(int i=0; i<n; i++){

        if(arr[i]==key){

            return i;

        }
    }
}


void main(){


    int arr[8]={2,5,9,7,8,4,6,0};

    int key;

    scanf("%d", &key);

    int r;

    r=ls(arr, key, 8);

    printf("\n%d", r);

}