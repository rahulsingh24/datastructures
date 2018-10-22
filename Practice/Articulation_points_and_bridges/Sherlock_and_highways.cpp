    #include <bits/stdc++.h>
    #define MAXV 100000
    using namespace std;
     
    typedef struct pair<int,int> II;
     
    bool visited[MAXV+10],dfsvisited[MAXV+10];
    int disc[MAXV+10],low[MAXV+10];
    int cc=1;
    set<II> s;
    vector<int> a[MAXV+10];
    multiset<int> maxpath[MAXV+10];
     
    void tarjan(int u,int p)
    {
        visited[u]=1;
        disc[u]=low[u]=cc++;
        for(auto v:a[u])
        {
            if(!visited[v])
            {
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    s.insert(II(u,v));
                    maxpath[u].insert((*maxpath[v].rbegin())+1);
                }
                else
                {
                    for(auto it:maxpath[v])
                    {
                        maxpath[u].insert(it);
                    }
                }
                while(maxpath[u].size()>2)
                {
                    maxpath[u].erase(maxpath[u].begin());
                }
            }
            else if(v!=p)
            {
                low[u]=min(low[u],disc[v]);
            }
        }
    }
     
     
     
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            maxpath[i].insert(0);
        }
        tarjan(1,0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
     
            if(maxpath[i].size()==2)
            {
                ans=max(ans,(*maxpath[i].begin())+(*maxpath[i].rbegin()));
                //printf("%d %d",(*maxpath[i].begin()),(*maxpath[i].rbegin()));
            }
            else if(maxpath[i].size()==1)
            {
                ans=max(ans,*maxpath[i].begin());
                //printf("%d",*maxpath[i].begin());
            }
            //printf("\n");
        }
        printf("%d %d",(int)s.size(),ans);
        return 0;
    }