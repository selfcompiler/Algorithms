//
// Created by RAHUL KUMAR SINGH on 25/02/17.
//  All Pairs Shortest Path problem
// Time complexity : : O(V^3)
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
vector<ll> allPairDistance[GRAPH_SIZE];

void FloydWarshall(){
    for(int i=1;i<=n;i++)
        allPairDistance[i].resize(n+2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j)
                allPairDistance[i][j]=0;
            else if(edge_cost.find(mp(min(u,v),max(u,v)))!=edge_cost.end()){
                allPairDistance[i][j]=edge_cost[mp(min(u,v),max(u,v))];
                allPairDistance[j][i]=allPairDistance[i][j];
            }
            else{
                allPairDistance[i][j]=inf;
                allPairDistance[j][i]=inf;
            }
        }

    for(int k=1;k<=n;k++){
        for(int v=1;v<=n;v++){
            for(int u=1;u<=n;u++){
                if(allPairDistance[v][k]+allPairDistance[k][u]< allPairDistance[v][u]){
                    allPairDistance[v][u]=allPairDistancep[v][k]+allPairDistance[k][u];
                }
            }
        }
    }
}
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

int main(){
    inScan();
    FloydWarshall();
    return 0;
}
