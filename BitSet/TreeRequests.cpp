//
// Created by RAHUL KUMAR SINGH on 18/02/17.
//using Bitset : http://codeforces.com/contest/570/problem/D
// it can be done by DSU also : https://github.com/selfcompiler/Algorithms/blob/master/DUSonTree/TreeRequests.cpp
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
typedef int64_t ULL;
typedef long long ll;
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) prULLf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)

template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }

const double eps = 1e-8;
const double pi = acos(-1.0);
const ll inf = 1e17 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;

#define MAXN 500005

int n,m;
vector<int> graph[MAXN];
vector< pair<int,int> > H[MAXN];
int inTime[MAXN],outTime[MAXN];
int A[30];
string s;
int ti=0;
void dfs(int v,int h){
    inTime[v]=++ti;
    H[h].pb(mp(ti,H[h].back().second^A[s[v]-'a']));
    forn(i,graph[v].size()){
        dfs(graph[v][i],h+1);
    }
    outTime[v]=++ti;
}
int main(){
    cin>>n>>m;
    forn(i, n)
        H[i].resize(1);
    forn(i,30)
        A[i]=1<<i;
    forn(i,n-1){
        int parent;
        S(parent);
        graph[parent-1].pb(i+1);
    }
    cin>>s;
    dfs(0,0);
    forn(i,m){
        int h, v;
        S2(v,h);
        v--,h--;
        int l,r,t;
        l=lower_bound(H[h].begin(),H[h].end(),mp(inTime[v],-1))-H[h].begin()-1;
        r=lower_bound(H[h].begin(),H[h].end(),mp(outTime[v],-1))-H[h].begin()-1;
        t=H[h][l].second^H[h][r].second;
        bool ok=t-(t&-t);
        if(!ok)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
