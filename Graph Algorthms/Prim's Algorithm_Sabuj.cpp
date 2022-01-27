#include<iostream>
#include<cstdio>
#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int>g[100];
vector<int>cost[110];
int visited[100];
//map<int,int,int>mp;
struct st
{
    int u,v,w;
    st(){ }
    st(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator <(const st &b)const
    {
        if(b.w<w)
        {
            return true;
        }
        else
        return false;
    }
};

void mst(int src)
{
    priority_queue<st>pq;
    memset(visited,0,sizeof(visited));
    visited[src]=1;
    int i,j,u,v,w;
    for(i=0;i<g[src].size();i++)
    {
        u=src;
        v=g[src][i];
        w=cost[src][i];
        //cout<<u<<v<<w<<endl;
        pq.push(st(u,v,w));

    }
    while(!pq.empty())
    {
        st var=pq.top();
        u=var.u;
        v=var.v;
        w=var.w;
        //cout<<u<<v<<endl;
       //pq.pop();
        if(visited[u]==1&&visited[v]==1)
        {
            //cout<<u<<v<<endl;
            pq.pop();
        }
        else
        {
           cout<<u<<" "<<v<<" "<<w<<endl;

            if(visited[u]==1)
            {
                src=v;

            }
            else
            {
                src=u;

            }

            visited[v]=1;
            visited[u]=1;
            for(i=0;i<g[src].size();i++)
            {
                u=src;
                v=g[src][i];
                w=cost[src][i];
                pq.push(st(u,v,w));

            }
        }
    }
}
int main()
{
    //st p[100];
    int n,m,i,j,x,y,z,src;

    st a[1110];
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        //pq.push(st(x,y,z));
        if(i==0)
        src=x;
        a[i].u=x;
        a[i].v=y;
        a[i].w=z;
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);


    }
    /*while(!pq.empty())
    {
       st s=pq.top();
       cout<<s.u<<s.v<<s.w<<endl;
        pq.pop();
    }*/
    cout<<endl;
    mst(src);

}

/* 11
1 5 2
1 2 4
1 4 10
2 4 8
2 3 18
3 4 11
4 5 5
4 7 11
7 6 1
4 8 9
8 6 2
*/
