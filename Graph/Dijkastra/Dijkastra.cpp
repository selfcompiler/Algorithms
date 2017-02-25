//
// Created by RAHUL KUMAR SINGH on 25/02/17.
// Time Complexity : \Theta ((|E|+|V|)\log |V|)
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

// map<string, vector<int> >
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
};
void inScan(){
    int x,y,cost;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>cost;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edge_cost[mp(min(x,y),max(x,y))]=cost;
    }
}

/*
 SAMPLE INPUT

9 28
1 2 4
1 8 8
2 1 4
2 3 8
2 8 11
3 2 8
3 4 7
3 6 4
3 9 2
4 3 7
4 5 9
4 6 14
5 4 9
5 6 10
6 3 4
6 4 14
6 5 10
6 7 2
7 6 2
7 8 1
7 9 6
8 1 8
8 2 11
8 7 1
8 9 7
9 3 2
9 7 6
9 8 7

 */
int main(){
    inScan();
    dijKastra(1,n);
    for(int i=1;i<=n;i++)
        cout<<least_distance[i]<<" \n";
    return 0;
}
