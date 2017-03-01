//
// Created by RAHUL KUMAR SINGH on 01/03/17.
/*
 * PreRequisite : Graph should contain Euler Ciruit , else this method won't work
 *
 * Choose any starting vertex v, and follow a trail of edges from that vertex until returning to v. It is not possible to get stuck at any vertex other than v, because indegree and outdegree of every vertex must be same, when the trail enters another vertex w there must be an unused edge leaving w.
The tour formed in this way is a closed tour, but may not cover all the vertices and edges of the initial graph.
As long as there exists a vertex u that belongs to the current tour but that has adjacent edges not part of the tour, start another trail from u, following unused edges until returning to u, and join the tour formed in this way to the previous tour.
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
void findEulerCircuitinDG(int totalNodes){
    map<int,int> edge_count;
    bool isGraphEmpty=true;
    for(int i=1;i<=totalNodes;i++){
        edge_count[i]=graph[i].size();
        if(edge_count[i]>0)
            isGraphEmpty= false;
    }
    if(isGraphEmpty){
        puts("Graph is Empty");
        exit(0);
    }
    stack<int> path;
    vector<int> circuit;
    path.push(1);
    int currentV=1;
    while(path.size()){
        if(edge_count[currentV]>0){
            int nextV=graph[currentV].back();
            graph[currentV].pop_back();
            edge_count[currentV]--;
            path.push(currentV);
            currentV=nextV;
        }
        else{
            circuit.push_back(currentV);
            currentV=path.top();
            path.pop();
        }
    }
    for(int i=circuit.size()-1;i>=0;i--)
        cout<<circuit[i]<<" ";
    puts("\n");

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
    findEulerCircuitinDG(n);
    return 0;
}

/*
 *
 * Input
3 3
1 2
2 3
3 1

 Output
1 2 3 1
 *
 *
 *
 * */
