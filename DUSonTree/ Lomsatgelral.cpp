// Link : http://codeforces.com/contest/600/problem/E

//
// Created by RAHUL KUMAR SINGH on 16/02/17.
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

#define FOR(a,b) for(ULL i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) prULLf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
typedef int64_t ULL;
using namespace std;
#define MAXN 100005
vector<ULL> graph[MAXN];
ULL color[MAXN]={0};
ULL ans[MAXN]={0};
ULL sz[MAXN]={0};
ULL cnt[MAXN]={0};
bool bigChain[MAXN]={false};
ULL n;
ULL maxDegree=0;
ULL sumOfMaxDegreeColors=0;
void getSize(ULL v,ULL parent=-1){
    sz[v]=1;
    for(ULL i=0;i<graph[v].size();i++){
        ULL child=graph[v][i];
        if(child!=parent){
            getSize(child,v);
            sz[v]+=sz[child];
        }
    }
}
void reEvaluateDegree(ULL nodeColor){
    cnt[nodeColor]++;
    if(maxDegree<cnt[nodeColor]){
        maxDegree=cnt[nodeColor];
        sumOfMaxDegreeColors=nodeColor;
    }
    else if(maxDegree==cnt[nodeColor]){
        sumOfMaxDegreeColors+=nodeColor;
    }
}
void addInfo(ULL v,ULL parent=-1){
    reEvaluateDegree(color[v]);
    for(ULL i=0;i<graph[v].size();i++){
        ULL child=graph[v][i];
        if(child!=parent && !bigChain[child]){
            addInfo(child,v);
        }
    }
}

void removeInfo(ULL v,ULL parent=-1){
    cnt[color[v]]--;
    for(ULL i=0;i<graph[v].size();i++){
        ULL child=graph[v][i];
        if(child!=parent && !bigChain[child]){
            removeInfo(child,v);
        }
    }
}

void dfs(ULL v,ULL parent,bool keep=false){
    ULL sizeOfBigChild=0,idOfBigChild=-1;
    for(ULL i=0;i<graph[v].size();i++){
        ULL child=graph[v][i];
        if(child!=parent && (sz[child]> sizeOfBigChild) )
        {
            sizeOfBigChild=sz[child];
            idOfBigChild=child;
        }
    }

    for(ULL i=0;i<graph[v].size();i++){
        ULL child=graph[v][i];
        if(child!=parent && child!=idOfBigChild )
        {
            dfs(child,v,true);
        }
    }
    if(idOfBigChild+1)
    {
        dfs(idOfBigChild,v,false);
        bigChain[idOfBigChild]=true;
    }
    addInfo(v,parent);
    if(idOfBigChild+1)
        bigChain[idOfBigChild]=false;
    ans[v]=sumOfMaxDegreeColors;
    if(keep)
    {
        removeInfo(v,parent);
        sumOfMaxDegreeColors=0;
        maxDegree=0;
    }
}
void preProcess(){
    getSize(1,-1);
    dfs(1,-1,false);
}
void inscan(){
    ULL x,y;
    cin>>n;
    for(ULL i=1;i<=n;i++)
        cin>>color[i];
    for(ULL i=1;i<n;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
void outScan(){
    for(ULL i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
int main(){
    inscan();
    preProcess();
    outScan();
    return 0;
}
