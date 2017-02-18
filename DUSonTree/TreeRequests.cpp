//
// Created by RAHUL KUMAR SINGH on 17/02/17.
//
//http://codeforces.com/contest/570/problem/D
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

#define FOR(a,b) for(ULL i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) prULLf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second

template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }

typedef int64_t ULL;
using namespace std;
#define MAXN 500005
#define ABCSIZE 26
vector<ULL> graph[MAXN];
char alphabet[MAXN];
vector< pair<int,int> > Queries[MAXN];
bool ans[MAXN],cnt[MAXN][ABCSIZE],bigChain[MAXN];
int height[MAXN],sz[MAXN],cntf[MAXN],n,Q;
void getSz(int node,int parent){
    sz[node]=1;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(child!=parent){
            height[child]=height[node]+1;
            getSz(child,node);
            sz[node]+=sz[child];
        }
    }
}
void addInfo(int node,int x,int parent){
    cntf[height[node]]-=cnt[height[node]][alphabet[node-1]-'a'];
    cnt[height[node]][alphabet[node-1]-'a']^=1;
    cntf[height[node]]+=cnt[height[node]][alphabet[node-1]-'a'];
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        if(child!=parent){
           if(!bigChain[child])
            addInfo(child,x,node);
        }
    }
}
void dfs(int node,int parent,bool keep){
    int maxSize=0,bigChild=-1;
    for(int i=0;i<graph[node].size();i++) {
        int child = graph[node][i];
        if(child!=parent){
            if(smax(maxSize,sz[child]))
                bigChild=child;
        }
    }

    for(int i=0;i<graph[node].size();i++) {
        int child = graph[node][i];
        if (child != bigChild) {
            dfs(child,node,false);
        }
    }
    if(maxSize>0){
        bigChain[bigChild]=true;
        dfs(bigChild,node,true);
    }
    addInfo(node,1,parent);
    for(int i=0;i<Queries[node].size();i++){
        int queryIndex=Queries[node][i].second;
        int queryHeight=Queries[node][i].first;
        ans[queryIndex]=cntf[queryHeight]<=1;
    }
    if(maxSize>0)
        bigChain[bigChild]=false;
    if(!keep)
        addInfo(node,-1,parent);

}
void preProcess(){
    height[1]=1;
    getSz(1,-1);
    dfs(1,-1,true);
}
void inScan(){
    int p,vertex,hei;
    //cin>>n>>Q;
    scanf("%d%d",&n,&Q);
    for(int i=2;i<=n;i++){
        //cin>>p;
        scanf("%d",&p);
        graph[p].push_back(i);
    }
    cin>>alphabet;
    for(int i=1;i<=Q;i++){
       // cin>>vertex>>hei;
        scanf("%d%d",&vertex,&hei);
        Queries[vertex].push_back(std::make_pair(hei,i));
    }
}
void outScan(){
    for(int i=1;i<=Q;i++){
        if(ans[i])
            puts("Yes");
        else
            puts("No");
    }
}
int main(){
    inScan();
    preProcess();
    outScan();
    return 0;
}
