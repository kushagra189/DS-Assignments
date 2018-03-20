#include<stdio.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int parti(int inp[],int low_index,int high_index)
{
	int pivoteee=inp[high_index];
	int j,i=low_index-1;
	for(j=low_index;j<high_index;j++)
	{
		if(inp[j]<=pivoteee)
		{
			i++;
			swap(&inp[i],&inp[j]);
		}
	}
	swap(&inp[i+1],&inp[high_index]);
	return (i+1);
}

void jaldi_kar(int inp[],int low_index,int high_index)
{
	if(low_index<high_index)
	{
		int pile=parti(inp,low_index,high_index);
		jaldi_kar(inp,low_index,pile-1);
		jaldi_kar(inp,pile+1,high_index);
	}
}

int main()
{
	int n,i=0,j;
	char p;
	int a[1000005];
	while(1)
	{
		scanf("%c",&p);
		if(p=='+')
		{
			scanf("%d",&n);
			a[i]=n;
			i++;
		}
		if(p=='-')
		{
			if(i<1)
			{
				printf("-1\n");
			}
			else
			{
				jaldi_kar(a,0,i-1);
				printf("%d\n",a[i-1]);
				i--;
			}
		}
		else if(p=='#')
		{
			break;
		}
	}
	return 0;
}
