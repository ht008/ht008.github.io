#include <cstdio>
#include <iostream>
#include <vector>
#include <algothm>
int maxm=2100000;
int n,m,ans;
int nowm[maxm];
vector <int> v[maxm];
inline bool comp(int x,int y)
{
	return nowm[x]<nowm[y];
}
void dfs(int now)
{
	for(int i=0;i<v[now].size();i++) dfs(v[now][i]);
    std::sort(v[now].begin(),v[now].end(),comp);
    for(int i=0;i<v[now].size();i++)
    {
    	int tmp=v[now][i];
    	if(nowm[tmp]+nowm[now]-1<=m) nowm[now]=nowm[now]+now[tmp]-1,ans++;
        else return;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",nowm[i]);
    for(int i=1;i<=n;i++)
    {
    	int sonnum;
    	scanf("%d",&sonnum);
    	nowm[i]+=sonnum;
    	for(int j=1,x;j<=sonnum;j++)
         scanf("%d",&x),v[i].push_back(x);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
