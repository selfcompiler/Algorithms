
//
// Created by RAHUL KUMAR SINGH on 25/02/17.
// Topologocal Sort for DAG (Directed Acyclic Graph )
// For Cyclic Graph topological order is not defined
// complexity Time Complexity: The above algorithm is simply DFS with an extra stack. So time complexity is same as DFS which is O(V+E).
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
vector<int> graph[GRAPH_SIZE];
int n,m;
bool isVisited[GRAPH_SIZE]={false};
stack<int> topologicalOrder;
void dfs(int node){
    isVisited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(!isVisited[child])
            dfs(child);
    }
    topologicalOrder.push(node);
}

void getTopologicalSort(int totalNodes){
    for(int i=1;i<=totalNodes;i++){
        isVisited[i]=false;
    }
    for(int i=1;i<=totalNodes;i++)
        if(!isVisited[i])
            dfs(i);
    while(topologicalOrder.size()){
        cout<<topologicalOrder.top()<<" ";
        topologicalOrder.pop();
    }
    puts("\n");
    return;
}
void inScan(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    return;
}
int main(){
    inScan();
    getTopologicalSort(n);
    return 0;
}
