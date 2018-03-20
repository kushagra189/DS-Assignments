#include <stdio.h>
#include <string.h>
#include <math.h>
char input[1000235];
char output[1000235];

//long long int sum[1000235]={0};

//long long int sum1[1000235]={0};

struct cal_sum
{
	long long int val;
	int index;
};

void mergesort(struct cal_sum array[],int low,int mid,int high)
{
	int n1=mid-low+1;
	int n2=high-mid;
	int i,j,k;
	struct cal_sum Left[n1],Right[n2];
	for(i=0;i<n1;i++)
	{
		Left[i]=array[low+i];
	}
	for(j=0;j<n2;j++)
	{
		Right[j]=array[j+mid+1];
	}
	i=0;j=0;k=low;
	while(i<n1 && j<n2)
	{
		if(Left[i].val<=Right[j].val)
		{
			array[k]=Left[i];
			i++;
		}
		else
		{
			array[k]=Right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		array[k]=Left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		array[k]=Right[j];
		j++;
		k++;
	}
}

void merge(struct cal_sum array[],int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		merge(array,low,mid);
		merge(array,mid+1,high);
		mergesort(array,low,mid,high);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int count[1000235]={0};
		int n;
		scanf("%d",&n);
		struct cal_sum sum[n];
		int i,p;
		for(i=0;i<n;i++)
		{
			sum[i].val=0;
			sum[i].index=i;
		}
		long long int powers[62];
		for(i=0;i<62;i++)
		{
			powers[i]=pow(2,61-i);
		}
		for(i=0;i<n;i++)
		{
			int naya[123]={0};
			int uni[62]={0};
			scanf("%s",input);
			int k,j;
			int len=strlen(input);
			for(j=0;j<len;j++)
			{
				naya[input[j]]=input[j];
			}
			k=0;
			for(j=0;j<123;j++)
			{
				if(naya[j]!=0)
				{
					output[k]=naya[j];
					k++;
				}
			}
			for(j=0;j<k;j++)
			{
				if(output[j]>='0' && output[j]<='9')
					uni[output[j]-'0']=1;
				if(output[j]>='A' && output[j]<='Z')
					uni[output[j]-'A'+10]=1;
				if(output[j]>='a' && output[j]<='z')
					uni[output[j]-'a'+36]=1;
			}
			int c=0;
			//sum[i].index=i;
			while(c<62)
			{
				sum[i].val+=uni[c]*powers[c];
				c++;
			}
			//uni[62]={0};
			//for(j=0;j<62;j++)
			//	printf("%d",uni[j]);
			//printf("%lld\n",sum[i].val);
			//sum1[i]=sum[i];
		}
		merge(sum,0,n-1);

		for(i=0;i<n;i++)
		{
			//count[i]=0;
			//for(p=0;p<n;p++)
			//{
			//	if(sum1[i]==sum[p])
			//		count[i]++;
				//else
				//	break;
			//}
			//printf("%d lol\n",i);
			p=i;
			int occur=1;
			while(i<n)
			{
				if(sum[i].val==sum[i+1].val)
				{
					occur++;
			//		printf("%d\n",occur);
					i++;
				}
				else
				{
					i++;
					break;
				}
			}
			//printf("%d\n",occur);
			while(p!=i)
			{
			//	printf("%d yes\n",p);
				count[sum[p].index]=occur;
				p++;
			}
			i--;
		}
		for(i=0;i<n;i++)
			printf("%lld ",count[i]);
		printf("\n");
	}
	return 0;
}
