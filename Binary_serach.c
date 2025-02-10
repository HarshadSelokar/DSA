#include <stdio.h>


int bs(int arr[],int l, int h, int key){
    int mid;
    if(l==h){

        if(arr[l]==key){

            return l;
        }
        else{
            return 0;

        }
    }
    else{

        mid=(l+h)/2;
        if(key==arr[mid]){

            return mid;
        }
        if(key<arr[mid]){

            bs(arr, l, mid-1, key);
        }
        else{

            return bs(arr, mid+1, h, key);
        }
    }
    
}


void main(){

 
    int arr[8]={0,1,2,3,4,5,6,7};

    int key, h=8;

    scanf("%d", &key);

    int r;

    r=bs(arr, 0, h, key);

    printf("\n%d", r);

}