#include <stdio.h>
#include <stdlib.h>
typedef struct node1
{
  int start;
  int end;
  int wt;
}store;

typedef struct node
{
  int init;
  int index;
  long long int result;
  int wmax;
}details;

store edge[200005];
details p[100005];

int cmp(const void *p, const void *q)
{
    return (((store *)p)->wt - ((store *)q)->wt);
};

int cmp1(const void *p, const void *q)
{
    return (((details *)p)->wmax - ((details *)q)->wmax);
};

int cmp2(const void *p, const void *q)
{
    return (((details *)p)->index - ((details *)q)->index);
};

long long int final[100005]={0};
int size[100005]={0};
int b[100005]={0};

int find(int i)
{
	while(b[i]!=i)
	{
    b[i]=b[b[i]];
		i=b[i];
	}
	return i;
}

void unite_array(int i,int j,int wt)
{
	if(size[i]<size[j])
	{
		b[i]=b[j];
    size[j]+=size[i];
    final[j]+=final[i]+wt;
	}
	else
	{
		b[j]=b[i];
    size[i]+=size[j];
    final[i]+=final[j]+wt;
	}
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    int i;

    for(i=0;i<n;i++)
    {
      size[i+1]=1;
      final[i+1]=0;
      b[i+1]=1;
      p[i].init=0;
      p[i].result=0;
      p[i].wmax=0;
    }

    for(i=0;i<m;i++)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      edge[i].start=a;
      edge[i].end=b;
      edge[i].wt=c;
    }
    qsort(edge, m, sizeof(edge[0]),cmp);
    for(i=0;i<q;i++)
    {
      scanf("%d%d",&p[i].init,&p[i].wmax);
      p[i].index=i;
    }
    qsort(p, q, sizeof(p[0]), cmp1);
    int j,k;
    for(i=0;i<q;i++)
    {
      for(j=k;j<m;j++)
      {
        if(edge[j].wt>p[i].wmax)
        {
          break;
        }
        int x=find(edge[j].start);
        int y=find(edge[j].end);
        if(x!=y)
        {
          unite_array(x,y,edge[j].wt);
        }
        else
        {
          final[x]+=edge[j].wt;
        }
      }
      int temp=final[find(p[i].init)];
      p[i].result=temp;
      k=j;
    }
    qsort(p, q, sizeof(p[0]), cmp2);

    for(i=0;i<q;i++)
    {
      printf("%lld\n",p[i].result);
    }
  }
  return 0;
}
