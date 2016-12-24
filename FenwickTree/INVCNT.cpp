//
// Created by RAHUL KUMAR SINGH on 24/12/16.
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

#define FOR(a,b) for(int i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
typedef long long int LL;
typedef int64_t i64;

class BIT{
    vector<int> tree;
    int maxValue;
public: BIT(){
    }
public: BIT(int size){
        tree.resize(size+1);
        maxValue=size;
        tree[0]=0;
    }

public: void update(int idx,int value){

     while(idx<=maxValue){
         tree[idx]+=value;
         idx+=idx&(-idx);
     }
    }

public: int cummulativesum(int idx){
        /* get sum upto sum=f[1]+f[2]+f[3]+...+f[idx]*/
        int sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }

public: int readSingle(int idx){
        int sum=tree[idx];
        if(idx>0){
            int z=idx-(idx&-idx);
            idx--;
            while(idx!=z){
                sum-=tree[idx];
                idx-=idx&(-idx);
            }
        }
        return sum;
    }

public:void clearBit(){
        tree.clear();
    }

public:void initializeBit(int size){
        tree.resize(size+1);
        tree[0]=0;
        maxValue=size;
    }

public:void printTree(){
        cout<<"\nTree Start\n";
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<"\nTree End\n";
    }
};
LL inputData[200004];
LL inputData2[200004];
char s[2];
map<LL,int> rankmap;
int main(){
    int tc,n,x,maxv=-1;
    LL ans;
    cin>>tc;
    BIT bit1=BIT();
    while(tc--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>inputData[i];
            inputData2[i-1]=inputData[i];
            if(maxv<inputData[i])
                maxv=inputData[i];
        }
        cin.getline(s,1);
        sort(inputData2,inputData2+n);
        int rank=0;
        for(int i=0;i<n;i++){
            if(rankmap.find(inputData2[i])==rankmap.end())
            {
                rank++;
                rankmap[inputData2[i]]=rank;
            }
        }
        bit1.initializeBit(rank);
        for(int i=n;i>=1;i--){
            bit1.update(rankmap[inputData[i]],1);
            ans+=bit1.cummulativesum(rankmap[inputData[i]]-1);
          //  bit1.printTree();
        }
        cout<<ans<<endl;
        bit1.clearBit();
        rankmap.clear();
    }
    return 0;
}
