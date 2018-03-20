#include <stdio.h>
#include <string.h>
#include <math.h>
char input[1000235];
char output[1000235];

//long long int sum[1000235]={0};
long long int count[1000235]={0};
//long long int sum1[1000235]={0};

struct cal_sum
{
	long long int val;
	int index;
}sum[1000235];

void swap(struct cal_sum *a,struct cal_sum *b)
{
	struct cal_sum t=*a;
	*a=*b;
	*b=t;
}

int parti(struct cal_sum arr[],int low,int high)
{
	int pivoteee=arr[high].val;
	int j,i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j].val<=pivoteee)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void jaldi_kar(struct cal_sum arr[],int low,int high)
{
	if(low<high)
	{
		int pile=parti(arr,low,high);
		jaldi_kar(arr,low,pile-1);
		jaldi_kar(arr,pile+1,high);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,p;
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
			sum[i].index=i;
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
		jaldi_kar(sum,0,n-1);

		for(i=0;i<n;i++)
		{

		}
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
			while(1)
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