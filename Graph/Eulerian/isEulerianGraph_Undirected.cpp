//
// Created by RAHUL KUMAR SINGH on 01/03/17.
// Points to be Noted :
// This will work only for undirected graph
// Condition for Euler Cycle = if odd degree count is Zero
// Condition for Euler Path  = if odd degree count is = 2
// odd degree vertex count 1 is not possible in undirected graph 
// Condition for not Eulerian = either graph with positive degree is not connected or odd_degree count >=3
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
int degree[GRAPH_SIZE]={0};
int n,m;
bool isVisited[GRAPH_SIZE]={false};
void dfs(int node){
    isVisited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(!isVisited[child]){
            dfs(child);
        }
    }
}
bool isGraphConnected(int totalNodes){
    dfs(1);
    for(int i=1;i<=totalNodes;i++)
        if(!isVisited[i] && degree[i]>0)
            return false;
    return true;
}

void checkEulerStatus(int totalNodes){
    if(!isGraphConnected(totalNodes)){
        puts("Graph is not connected ,all vertex which have non-zero degree is not connected");
        exit(0);
    }
    int oddCount=0;
    for(int i=1;i<=totalNodes;i++){
        if(degree[i]%2)
            oddCount++;
    }
    if(oddCount>=3)
        oddCount=3;
    switch(oddCount){
        case 0:
            puts("Graph has Euler Cycle");
            break;
        case 2:
            puts("Graph has a Euler Path");
            break;
        default:
            puts("Graph is not Eulerian");
    }
}
void inScan(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    return;
}
int main(){
    inScan();
    checkEulerStatus(n);
    return 0;
}

/*
 *
Input 1:

 5 5
1 2
1 3
2 3
1 4
4 5
 o/p
Graph has a Euler Path

Input 2:

 5 6
1 2
1 3
2 3
1 4
4 5
1 5
 O/P
Graph has Euler Cycle

 Input 3 :

 5 6
1 2
1 3
2 3
1 4
4 5
2 4
 O/P
Graph is not Eulerian

 * */
