//
// Created by RAHUL KUMAR SINGH on 25/02/17.
// This code will work for Directed graph
// Time complexity : O(V2log V + VE).
// it can handle negative weight edges 
//

#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using  namespace std;
typedef int64_t ll;
typedef long long ULL;
#define S(x) scanf("%d",&x)
#define string2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)

template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }
template <class T> void outSet(set<T> &myset){
    puts("Set Print");
    for(typename set<T>::iterator it=myset.begin();it!=myset.end();it++){
        cout<<*it<<" ";
    }
    puts("\nEnd Set Print");
}
const double eps = 1e-8;
const double pi = acos(-1.0);
const ll inf = 1e14 + 1;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;

#define GRAPH_SIZE 1005
vector<int> graph[GRAPH_SIZE];
vector<ll> allPairDistance[GRAPH_SIZE];
map < pair <int,int> ,int > edge_cost;
int n,m,k;
vector<ll> least_distance;
vector<int> previous_node;
class Compare
{
public:
    bool operator() (int &idx1,int &idx2)
    {
        return least_distance[idx1]>least_distance[idx2];
    }
};

bool BellmanFord(int src,int totalNodes){
    least_distance.resize(totalNodes+3);
    for(int i=1;i<=n;i++)
        least_distance[i]=inf;
    least_distance[src]=0;
    for(int i=1;i<n;i++){
        puts("voila");
        for(map < pair <int,int> ,int >::iterator it=edge_cost.begin();it!=edge_cost.end();it++){
            int u=it->first.first;
            int v=it->first.second;
            ll cost=it->second;
            if(least_distance[u]!=inf && (least_distance[u]+cost < least_distance[v])){
                least_distance[v]=least_distance[u]+cost;
            }

        }
    }

    for(map < pair <int,int> ,int >::iterator it=edge_cost.begin();it!=edge_cost.end();it++){
        int u=it->first.first;
        int v=it->first.second;
        ll cost=it->second;
        if(least_distance[u]!=inf && (least_distance[u]+cost < least_distance[v])){
            puts("Negative cycle Exist");
            return false;
        }
    }
    return true;
}

void dijKastra(int source,int totalNodes){
    /* 1 based indexing */
    previous_node.clear();
    least_distance.clear();
    least_distance.resize(totalNodes+1);
    previous_node.resize(totalNodes+1);
    std::priority_queue<int,vector<int>,Compare> Q;
    for(int i=1;i<=n;i++)
    {
        least_distance[i]=inf,previous_node[i]=-1;
        Q.push(i);
    }
    least_distance[source]=0;
    while(!Q.empty()){
        int node_with_minimum_distance=Q.top();
        Q.pop();
        for(int i=0;i<graph[node_with_minimum_distance].size();i++){
            int neighbour_node=graph[node_with_minimum_distance][i];
            ll temp_distance=least_distance[node_with_minimum_distance]+edge_cost[mp(min(node_with_minimum_distance,neighbour_node),max(node_with_minimum_distance,neighbour_node))];
            if(temp_distance < least_distance[neighbour_node]){
                least_distance[neighbour_node]=temp_distance;
                previous_node[neighbour_node]=node_with_minimum_distance;
            }
        }
    }
    return;
};

void executeJohnSonAlgorithm(){
    for(int i=1;i<=n;i++)
    {
            graph[x].push_back(i);
            edge_cost[mp(n+1,i)]=0;
    }
    if(!BellmanFord(n+1,n+1)){
        puts("Negative Cycle Exists");
        exit(0);
    }
    //removing extra added edges
    for(int i=1;i<=n;i++){
        edge_cost.erase(mp(n+1,i));
    }
    // recompute edge weight again
    for(map < pair <int,int> ,int >::iterator it=edge_cost.begin();it!=edge_cost.end();it++){
        int u=it->first.first;
        int v=it->first.second;
        int cost=it->second;
        edge_cost[mp(u,v)]=edge_cost[mp(u,v)]+least_distance[u]-least_distance[v];
    }
    for(int i=1;i<=n;i++){
        dijKastra(i,n);
        for(int j=1;j<=n;j++){
            allPairDistance[i][j]=least_distance[j];
        }
    }
    return;
}
void inScan(){
    int x,y,cost;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>cost;
        graph[x].push_back(y);
        edge_cost[mp(x,y)]=cost;
    }
    return;
}


int main(){
    inScan();
    executeJohnSonAlgorithm();
    return 0;
}
