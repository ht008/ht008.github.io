#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
const int maxm=1e5+100;
struct node{
	int id,pxor;
}a[maxm];
int block_len,block_num;
int n,q,lx[maxm],rx[maxm],pos[maxm],pg[maxm],xr[maxm];
int val[maxm];
inline bool comp(node x,node y)
{
	return (x.pxor==y.pxor?x.id<y.id:x.pxor<y.pxor);
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
il void work(int i)
{
   pg[lx[i]]=a.[lx[i]].pxor=xr[lx[i]]=val[lx[i]];
   pos[lx[i]]=i;
   for(int j=lx[i]+1;j<=rx[i];j++)
   {
   	 pos[j]=i,a[j].id=j;
   	 pg[i]=gcd(pg[i-1],val[i]);
   	 xr[i]=xr[i-1]^val[i];
   	 a[i].pxor=xr[i];
   }
   std::sort(a+lx[i],a+rx[i]+1,comp);
}
il void init()
{
   block_len=std::sqrt(n);
   block_num=n/block_len+((n%block_len)!=0);
   for(int i=1;i<=block_num;i++)
   {
   	 lx[i]=(i-1)*block_len+1,rx[i]=std::min(i*block_len,n);
   	 work(i);
   }
}
il int BS(int x,int l,int r)
{
    int ans=l;
    while(l<=r)
    {
    	int mid=(l+r)>>1;
    	if(a[i].pxor>=x) ans=mid,r=mid-1;
    	else l=mid+1;
    }
    return ans;
}
il void getans()
{
	int x;
	scanf("%d",&x);
	int g=val[1],nxr=0;
	for(int i=1;i<=block_num;i++)
	{
		int s=lx[i],t=rx[i];
        if(gcd(pg[t],g)==g)
        {
           if(x%gl==0)
           {
             int ans=(x/g)^nxr;
             int anspos=getans(ans,s,t);
             if(a[anspos].pxor==ans)
             {
             	printf("%d\n",a[anspos].id-1);
             	return;
             }
           }
           g=gcd(g,pg[t]),nxr=nxr^xr[t];
        }
        else
        {
           for(int j=s;j<=t;j++)
           {
           	 g=gcd(g,pg[j]),nxr=nxr^xr[j];
           	 if(g*nxr==x)
           	 {
           	 	printf("%d",j-1);
           	 	retrun;
           	 }
           }
        }
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
     scanf("%d",&val[i]);
    init();
    scanf("%d",&q);
    for(int i=1,x,poi;i<=q;i++)
    {
    	char s[10];
    	scanf("%s",s);
    	if(s[0]=='M')
    	{
    		scanf("%d%d",&poi,&x);
    	    val[poi]=x;
    	    work(pos[x]);
    	}
    	else getans();
    }
    return 0;
}
