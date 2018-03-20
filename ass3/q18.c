#include <stdio.h>
//		int input[100023]={0};
int maintain[1000023]={0};
int stack[1000023]={0};		
int count[1000023]={0};

void push(int arr[],int *i, int ele)
{
	arr[*i]=ele;
	(*i)++;
}

void pop(int arr[],int *i)
{
	arr[*i]=0;
	(*i)--;
	if((*i)<1)
		(*i)=0;
}

int top(int arr[],int j)
{
	return arr[j-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int i,j=0,l=0;
		int input;
		int sum=0;
		int max=0;
		for(i=0;i<n;i++)
		{
			count[i]=0;
			scanf("%d",&input);
			if(input>0)
			{
				push(stack,&j,input);
				push(maintain,&l,i);
			}
			else
			{
				int temp=top(stack,j);

				if(temp+input==0)
				{
					pop(stack,&j);
					count[i]=1;
					count[top(maintain,l)]=1;
					pop(maintain,&l);
				}
				else
				{
					while(j!=0)
					{
						pop(stack,&j);
					}
					while(l!=0)
					{
						pop(maintain,&l);
					}
				}
			}
		}
		//for(i=0;i<n;i++)
		//{
		//	printf("%d ",count[i]);
		//}
		//printf("\n");
		for(i=0;i<n;i++)
		{
			if(count[i]==1)
				sum++;
			else	
			{
				if(sum>max)
					max=sum;
				sum=0;
			}
		}
		if(max>sum)
			printf("%d\n",max);
		else
			printf("%d\n",sum);
	}
	return 0;
}
