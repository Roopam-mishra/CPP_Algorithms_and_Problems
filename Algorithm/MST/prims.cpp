#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 100000000
typedef pair<ll,ll> PII;
bool marked[MAX];
vector <PII> adj[MAX];
ll prim(ll x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    ll y;
    ll minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
        continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
            Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}
int main()
{
    ll nodes, edges, x, y;
    ll weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
