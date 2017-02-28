//
// Created by RAHUL KUMAR SINGH on 28/02/17.
//Time Complexity: The above algorithm calls DFS, fins reverse of the graph and again calls DFS. DFS takes O(V+E)
// 2 dfs , dfs1 populate stack dfs2 visit the reverse graph
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
vector<int> reverseGraph[GRAPH_SIZE];
int n,m;
bool isVisited[GRAPH_SIZE]={false};
stack<int> SCCStack;
vector< vector<int> > SCC;

void dfs1(int node){
    isVisited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(!isVisited[child]){
            dfs1(child);
        }
    }
    SCCStack.push(node);
}
void dfs2(int node,vector<int> &scc){
    isVisited[node]=true;
    for(int i=0;i<reverseGraph[node].size();i++){
        int child=reverseGraph[node][i];
        if(!isVisited[child]){
            dfs2(child,scc);
        }
    }
    scc.push_back(node);
}
void getSCC(int totalNodes){
    for(int i=1;i<=totalNodes;i++){
        if(!isVisited[i])
            dfs1(i);
    }
    for(int i=1;i<=totalNodes;i++){
        isVisited[i]=false;
    }
    while(SCCStack.size()){
        int top=SCCStack.top();
        if(!isVisited[top]){
            vector<int> scc;
            dfs2(top,scc);
            SCC.push_back(scc);
        }
        SCCStack.pop();
    }
}
void inScan(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        reverseGraph[y].push_back(x);
    }
    return;
}
int main(){
    inScan();
    getSCC(n);
    cout<<SCC.size()<<"\n";
    for(int i=0;i<SCC.size();i++){
        cout<<"Comp "<<i+1<<"\n";
        for(int j=0;j<SCC[i].size();j++){
            cout<<SCC[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}

/*
 Sample Input :

5 5
2 1
1 3
3 2
1 4
4 5

 O/P

 3
Comp 1
3 2 1
Comp 2
4
Comp 3
5

 * */
