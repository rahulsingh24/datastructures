#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 5005
#define INF 1e17
using namespace std;
typedef long long LL;
LL n,m,p[N],c[N],cnt[N],sum,ans=INF;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>c[i];
		if(p[i]!=1)
			sum+=c[i];
	}
	for(int i=0;i<=n;i++){
		LL need=i+1;
		memset(cnt,0,sizeof cnt);
		priority_queue<pair<LL,LL> > q;
		for(int j=1;j<=n;j++)
			if(p[j]!=1)
				q.push(make_pair(c[j],p[j]));
		LL now=n,use=sum;
		while(now>need&&!q.empty()){
			LL t=q.top().first,id=q.top().second;
			cout<<"t = "<<t<<" id = "<<id<<endl;
			q.pop();
			cout<<"cnt["<<id<<"] = "<<cnt[id]<<" i = "<<i<<endl;
			if(cnt[id]==i)
				continue;
			cnt[id]++;
			now--;
			use-=t;
		}
		cout<<"use = "<<use<<endl;
		ans=min(ans,use);
	}
	cout<<ans<<endl;
	return 0;
}
