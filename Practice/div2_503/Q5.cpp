#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1000000007
#define INFLL 1000000000000000011LL
#define pb(x) push_back(x)
#define mp make_pair
#define fi first
#define se second
#define vi vector
#define gtl(x) getline(cin, (x))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define setv(x,a) memset(x,a,sizeof(x))
#define ull unsigned long long int 

int main() {
	int n,m;
	cin>>n>>m;

	vector<vector<int> > v(n);
	int x,y;
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		--x,--y;
		v[x].pb(y);
	}

	if(n==1){
		cout<<1<<endl;
		cout<<1<<endl;
		return 0;
	}

	vector<int> ans;
	bool visited[n];
	int dist[n];
	int i=0;
	for(;i<n;i++) {
	    for(int j=0;j<n;j++) visited[j]=0;
	    for(int j=0;j<n;j++) dist[j]=0;

	    ans.clear();

	    queue<int> q;
	    q.push(i);
	    int t,x=i;
	    int count=0;
	    while(!q.empty()) {
	        t = q.front();
	        q.pop();
	        visited[t]=true;
	        if(dist[t]<=2)
	        count++;
	        if(dist[t]==2) {
	        	ans.pb(t);
	        }
	        if(dist[x]<dist[t]) {
	            x = t;
	        }
	        for(int j=0;j<v[t].size();j++) {
	            if(visited[v[t][j]]==false) {
	                q.push(v[t][j]);
	                visited[v[t][j]]=true;
	                dist[v[t][j]]+= dist[t]+1;
	            }
	        }
	    }
	    
	    if(dist[x]<=2 && count==n) {
	    	ans.pb(i);
	    	break;
	    }
	}

	int root = ans[ans.size()-1];

	for(i=0;i<ans.size();) {
		if(ans[i]!=root) {
			int uu=-1;
			for(int j=0;j<v[ans[i]].size();j++) {
				if(v[ans[i]][j]==root) {
					uu = ans[i];
					break;
				}
			}
			if(uu!=-1)
			ans.erase(ans.begin()+i);
			else i++;
		} else i++;
	}

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]+1<<" ";
	}

}

