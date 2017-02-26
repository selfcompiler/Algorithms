//
// Created by RAHUL KUMAR SINGH on 26/02/17.
/*
 * Find Articulation point in Undirected Graph
 * So time complexity is same as DFS which is O(V+E)
 *
 * */
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
#define UNDEFINED_TIME -1
#define UNDEFINE_PARENT -1
vector<int> graph[GRAPH_SIZE];
bool isAP[GRAPH_SIZE],isVisited[GRAPH_SIZE];
int discoverTime[GRAPH_SIZE];
int low[GRAPH_SIZE];
int parent[GRAPH_SIZE];
int n,m;
void dfsAP(int node){
    static int time=0;
    int childCount=0;
    isVisited[node]=true;
    low[node]=++time;
    discoverTime[node]=time;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(!isVisited[child]){
            childCount++;
            parent[child]=node;
            dfsAP(child);
            low[node]=min(low[node],low[child]);
            if(parent[node]==UNDEFINE_PARENT && childCount>1)  // if it is root node is the dfs tree
                isAP[node]=true;
            if(parent[node]!=UNDEFINE_PARENT && (low[child]>=discoverTime[node]))  // if it is not root in dfs tree
                isAP[node]=true;
        }
        else if(child!=parent[node]){
            low[node]=min(low[node],low[child]);
        }
    }
}
void findAP(int totalNodes){
    /*initialize all the arrays
     * */
    for(int i=1;i<=totalNodes;i++){
        isAP[i]=false;
        isVisited[i]=false;
        parent[i]=UNDEFINE_PARENT;
    }
    for(int i=1;i<=totalNodes;i++)
        if(!isVisited[i])
            dfsAP(i);
    for(int i=1;i<=totalNodes;i++)
        if(isAP[i])
            cout<<i<<" ";
    return;
}
void inScan(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
int main(){
    inScan();
    findAP(n);
    return 0;
}

/*

 input

 5 5
1 2
2 3
1 3
1 4
4 5


o/p
1 4


 */
