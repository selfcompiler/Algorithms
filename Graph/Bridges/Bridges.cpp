//
// Created by RAHUL KUMAR SINGH on 28/02/17.
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
#include <stack>
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
#define UNDEFINE_PARENT -1
vector<int> graph[GRAPH_SIZE];
int n,m;
bool isVisited[GRAPH_SIZE]={false};
int low[GRAPH_SIZE];
int discTime[GRAPH_SIZE];
int parent[GRAPH_SIZE];
vector< pair<int,int> > bridges;
void dfsBridge(int node){
    static int time=0;
    isVisited[node]=true;
    discTime[node]=++time;
    low[node]=time;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(!isVisited[child]){
            parent[child]=node;
            dfsBridge(child);
            low[node]=min(low[node],low[child]);
            if(low[child]>discTime[node]){
                bridges.pb(mp(child,node));
                cout<<child<<" "<<node<<"\n";
            }
        }
        else if(parent[node]!=child){
            low[node]=min(low[node],discTime[child]);
        }
    }
}
void findBridges(int totalNodes){
    for(int i=1;i<=totalNodes;i++){
        isVisited[i]=false;
        parent[i]=UNDEFINE_PARENT;
    }
    for(int i=1;i<=totalNodes;i++){
        if(!isVisited[i])
            dfsBridge(i);
    }
}
void inScan(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return;
}
int main(){
    inScan();
    puts("**output**");
    findBridges(n);
    return 0;
}
/*
 * 

 input
 5 5
2 1
1 3
3 2
1 4
4 5
**output**
5 4
4 1
 
 * */
