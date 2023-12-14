// C PROGRAM TO IMPLEMENT FRACTIONAL KNAPSACK PROBLEM.
#include<stdio.h>
#include<stdlib.h>

struct object{
	float p;
	float w;
	float piwi;
}o[50];

int main(){
	int i,j,k,c,n;
	float profit=0,f=0;
	struct object val;
	printf("Enter no of objects: ");
	scanf("%d",&n);
	printf("Enter capacity of knapsack: ");
	scanf("%d",&c);
	printf("-: Enter details :-\n");

	for(i=0;i<n;i++)
        o[i].piwi=-1;

	for(i=0;i<n;i++){
		printf("Enter profit of object %d: ",i+1);
		scanf("%f",&o[i].p);
		printf("Enter its weight: ");
		scanf("%f",&o[i].w);
		o[i].piwi=(o[i].p)/(o[i].w);
		for(j=0;j<n-1;j++){
			val=o[j+1];
			k=j+1;
			while(k>0 && o[k-1].piwi<val.piwi){
				o[k]=o[k-1];
				k--;
			}
			o[k]=val;
		}
	}
	for(i=0;i<n;i++){
        if(c>0){
            if(o[i].w<c){
                profit=profit+o[i].p;
                c=c-o[i].w;
            } else{
                f=c/o[i].w;
                profit=profit+f*(o[i].p);
                c=0;
            }
        }
        else 
            break;
    }
	printf("=================================\n");
	printf("Maximum Profit is : %.2f", profit);
}