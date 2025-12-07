#include <stdio.h>
#include <stdlib.h>

int *data;
int n=0;
int limit;

void display(){
	int i;
	if(n==0){
		printf("\n[Empty Array]\n");
		return;
	}
	printf("\nData: ");
	for(i=0;i<n;i++){
		printf("| %d ",data[i]);
	}
	printf("|\n");
	printf("Pos : ");
	for(i=0;i<n;i++){
		printf("  %d  ",i);
	}
	printf("\n");
}

void add(){
	int v,loc,i;
	if(n>=limit){
		printf("Full!\n");
		return;
	}
	printf("Value: ");
	scanf("%d",&v);
	printf("Location (0-%d): ",n);
	scanf("%d",&loc);

	if(loc<0 || loc>n){
		printf("Invalid location.\n");
		return;
	}

	for(i=n;i>loc;i--){
		data[i]=data[i-1];
	}
	data[loc]=v;
	n++;
	printf("Added successfully.\n");
}

void remove_element(){
	int loc,i;
	if(n==0){
		printf("Empty!\n");
		return;
	}
	printf("Delete location (0-%d): ",n-1);
	scanf("%d",&loc);

	if(loc<0 || loc>=n){
		printf("Invalid.\n");
		return;
	}

	for(i=loc;i<n-1;i++){
		data[i]=data[i+1];
	}
	n--;
	printf("Removed successfully.\n");
}

void rotate_right(){
	int last,i;
	if(n<2){
		printf("Need more data to rotate.\n");
		return;
	}
	last=data[n-1];
	
	for(i=n-1;i>0;i--){
		data[i]=data[i-1];
	}
	data[0]=last;
	printf("Rotated right!\n");
}

void find_stats(){
	int i,max,min,sum=0;
	if(n==0){
		printf("No data for stats.\n");
		return;
	}
	max=data[0];
	min=data[0];
	
	for(i=0;i<n;i++){
		if(data[i]>max) max=data[i];
		if(data[i]<min) min=data[i];
		sum+=data[i];
	}
	printf("\n--- Stats ---\n");
	printf("Highest: %d\n",max);
	printf("Lowest : %d\n",min);
	printf("Total  : %d\n",sum);
}

int main(){
	int opt;
	
	printf("Set Array Limit: ");
	scanf("%d",&limit);
	data=(int*)malloc(limit*sizeof(int));

	do{
		printf("\n1.Add 2.Remove 3.Display 4.Rotate 5.Stats 6.Exit\n");
		printf("Select: ");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: add(); break;
			case 2: remove_element(); break;
			case 3: display(); break;
			case 4: rotate_right(); break;
			case 5: find_stats(); break;
			case 6: printf("Bye.\n"); break;
			default: printf("Bad option.\n");
		}
	}while(opt!=6);
	
	return 0;
}
