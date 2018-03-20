#include<stdio.h>
void push(int array[], int *i, int n)
{
	array[*i]=n;
	(*i)++;
	return;
}

void pop(int array[],int *i)
{
	(*i)--;
	if((*i)<1)
		(*i)=0;
	return;
}

int top(int array[], int j)
{
	return array[j-1];
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int query;
		scanf("%d",&query);
		int p,q,i=0,j=0;
		long long int sum=0;
		int time[100012]={0};
		int time2[100012]={0};
		int min=1999999999;
		int minus_one = -1;
		while(query--)
		{
			scanf("%d",&p);
			if(p==1)
			{
				scanf("%d",&q);
				push(time,&i,q);
				sum+=q;
				if(q<=min)
				{
					min=q;
					push(time2,&j,min);

				}
			}
			else if(p==2)
			{
				sum=sum-top(time,i);
				if(top(time,i)==top(time2,j))
				{
					pop(time2,&j);
					min=top(time2,j);
				}
				pop(time,&i);
			}
			if(sum<=0)
			{
				printf("%d 0\n", minus_one);
				min=1999999999;
			}
			else
			{
				printf("%d %lld",top(time2,j),sum);
				printf("\n");
			}
		}
	}
	return 0;
}
