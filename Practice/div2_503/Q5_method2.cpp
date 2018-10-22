#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define setv(x,a) memset(x,a,sizeof(x))


int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	vector<int> adj[n];
	// setv(adj,false);

	int x,y;
	for(int i=0;i<m;i++) {
		scanf("%d %d",&x,&y);
		--x,--y;
		adj[x].push_back(y);
	}

	bool visited[n];
	setv(visited,false);

	for(int i=0;i<n;i++) {
		if(visited[i]==false) {
			for(int j=0;j<adj[i].size();j++) {
				if(adj[i][j]>i) visited[adj[i][j]]=true;
			}
		}
	}

	vector<int> ans;
	for(int i=n-1;i>=0;i--) {
		if(visited[i]==false) {
			ans.push_back(i);
			for(int j=0;j<adj[i].size();j++) {
				visited[adj[i][j]]=true;
			}
		}
	}
	int dhanraj=ans.size();
	printf("%d\n", dhanraj);
	for(int i=0;i<ans.size();i++) printf("%d ", ans[i]+1);
}