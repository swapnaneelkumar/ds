#include<Stdio.h>

int main(){
	int i, N;
	
	printf("enter the nummber of elemets: ");
	scanf("%d",&N);
	
	
	int arr[N];
	printf("enter %d integers:\n",N);
	for(i =0; i<N; i++){
		printf("Element %d\n :",i+1);
		scanf("%d",&arr[i]);
		
		
	}
	
	
	printf("you  entered:\n");
	for(i=0;i<N;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	
	return 0;
}
