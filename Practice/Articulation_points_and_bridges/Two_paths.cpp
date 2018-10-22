/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

set<pair<int,int> > s;
int tim=0;


void dfs(vector<pair<int,int> > g[], bool visited[], int i, int parent[], int low[], int disc[]) {
    visited[i]=true;
    low[i]=disc[i]=tim++;
    for(int j=0;j<g[i].size();j++) {
        if(visited[g[i][j].first]==false) {
            parent[g[i][j].first]=i;
            dfs(g,visited,g[i][j].first,parent,low,disc);
            low[i] = min(low[i],low[g[i][j].first]);
            if(low[g[i][j].first]>disc[i]) {
                if(g[i][j].second==0) {
                    // s.insert(mp(min(i,g[i][j].first),max(i,g[i][j].first)));
                    s.insert(mp(i,g[i][j].first));
                }
            }
        } else if(parent[i]!=g[i][j].first) {
            low[i] = min(low[i],disc[g[i][j].first]);
        }
    }
}


int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int> > g[n+1];
    
    int a,b,c,d,t;
    for(int i=0;i<m;i++) {
        cin>>a>>b>>t;
       g[a].pb(mp(b,t));
       g[b].pb(mp(a,t));
    }
    
    int parent[n+1];
    memset(parent,1,sizeof(parent));
    int low[n+1],disc[n+1];
    memset(low,0,sizeof(low));
    memset(disc,0,sizeof(disc));
    
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    
    for(int i=1;i<=n;i++) {
        if(visited[i]==false) {
            dfs(g,visited,i,parent,low,disc);
        }
    }
    
    int siz = s.size();
    while(q--) {
        cin>>a>>b>>c>>d;
        int check=0;
        for(auto i : s.begin()) {
            if((disc[a]<disc[i.first] && disc[b]>disc[i.first]) || (disc[b]<disc[i.first] && disc[a]>disc[i.first])) {
                if((disc[c]<disc[i.first] && disc[d]>disc[i.first]) || (disc[d]<disc[i.first] && disc[c]>disc[i.first])) {
                    check=1;
                    break;
                }
            }
        }
        
        if(check) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
        
    }
}
