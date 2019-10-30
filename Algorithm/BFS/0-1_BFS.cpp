/*
RESOURCES:  https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
            https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
            https://codeforces.com/blog/entry/22276
            */
*************************************************************************************************

/*
Author: Roopam Mishra 
*/
***********************

#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
struct node 
{ 
    ll to, weight; 
}; 
vector<node> adj[10000]; 
void zeroOneBFS(ll src,ll n) 
{ 
    ll distance[n]; 
    for (ll i=0; i<n; i++) 
    distance[i] = LLONG_MAX; 
    deque<ll> q; 
    distance[src] = 0; 
    q.push_back(src); 
    while(!q.empty()) 
    { 
        ll x=q.front(); 
        q.pop_front(); 
        for (ll i=0;i<adj[x].size();i++) 
        { 
            if(distance[adj[x][i].to]>distance[x]+adj[x][i].weight) 
            { 
                distance[adj[x][i].to]=distance[x]+adj[x][i].weight; 
                if (adj[x][i].weight==0) 
                    q.push_front(adj[x][i].to); 
                else
                    q.push_back(adj[x][i].to); 
            } 
        } 
    } 
    for(ll i=0;i<n;i++) 
        cout<<distance[i]<<" "; 
} 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,a,b,w;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    ll src = 0; 
    zeroOneBFS(src,n); 
    return 0; 
}
