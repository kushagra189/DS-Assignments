#include<stdio.h>
#include<stdlib.h>
long long int a[1000005]={0};
long long int b[1000005]={0};
long long int c[1000005]={0};
void push(long long int array[], long long int *i, long long int n)
{
	array[*i]=n;
	(*i)++;
	return;
}

void pop(long long int array[],long long int *i)
{
	(*i)--;
	if((*i)<1)
		(*i)=0;
	return;
}

int top(long long int array[], long long int j)
{
	return array[j-1];
}

void swap(long long int *a,long long int *b)
{
	long long int t=*a;
	*a=*b;
	*b=t;
}

int parti(long long int array[],long long int low,long long int high)
{
	long long int pivoteee=array[high];
	long long int j,i=low-1;
	for(j=low;j<high;j++)
	{
		if(array[j]<=pivoteee)
		{
			i++;
			swap(&array[i],&array[j]);
		}
	}
	swap(&array[i+1],&array[high]);
	return (i+1);
}

void quick(long long int array[],long long int low,long long int high)
{
	if(low<high)
	{
		long long int pile=parti(array,low,high);
		quick(array,low,pile-1);
		quick(array,pile+1,high);
	}
}
/*
   1
   6
   96624
   107397
   99983
   108634
   105921
   95587
 */

int main()
{
	long long int l,t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		j=0;
		push(b,&j,a[0]);
		long long int k,p=0;
		for(k=1;k<n;k++)
		{
			if(a[k]>=top(b,j))
			{
				//printf("%lld %lld\n",a[k],top(b,j));
				//c=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
				c[p]=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
				//c=func(a[k],top(b,j));
				//if(c>max)
				//{
				//	max=c;
				//}
				p++;
				//printf("this is %lld\n",c);
				push(b,&j,a[k]);
			}
			else
			{
				while(a[k]<top(b,j))
				{
					//printf("%lld %lld\n",a[k],top(b,j));
					//c=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
					c[p]=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
					//c=func(a[k],top(b,j));
					//if(c>max)
					//{
					//	max=c;
					//}
					//printf("this is %lld\n",c);
					p++;
					pop(b,&j);
				}
				if(top(b,j)!=0)
				{
					//printf("%lld %lld\n",a[k],top(b,j));
					//c=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
					c[p]=(((top(b,j) | a[k])*(top(b,j) | a[k]))-((top(b,j) & a[k])*(top(b,j) & a[k])));
					//c=func(a[k],top(b,j));
					//if(c>max)
					//{
					//	max=c;
					//}
					//printf("this is %lld\n",c);
					p++;
				}
				push(b,&j,a[k]);
			}
		}
		quick(c,0,p-1);
		printf("%lld\n",c[p-1]);
	}
	return 0;
}
