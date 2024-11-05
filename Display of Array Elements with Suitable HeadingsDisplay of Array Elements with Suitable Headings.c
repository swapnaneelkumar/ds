#include<stdio.h>

 int main(){
 	int i =0;
 	int arr[] = {10,23,45,78,34};
 	int length = sizeof(arr)/sizeof(arr[0]);
 	
 	
    printf("%-10s%-10\n","Index","value");
    printf("-----------------\n");
    
   for(i=0;i<length;i++){
   	printf("%-10d%-10d\n",i,arr[i]);
   }
 }
