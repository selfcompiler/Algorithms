//
// Created by RAHUL KUMAR SINGH on 24/12/16.
//

//
// Created by RAHUL KUMAR SINGH on 24/12/16.
//
//link: https://www.codechef.com/problems/LEBOBBLE

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

template <class T>
class BIT  {
    std::vector<T> tree;
    int maxValue;
public: BIT(){
    }
public: BIT(int size){
        tree.resize(size+1);
        maxValue=size;
        tree[0]=0;
    }

public: void update(int idx,T value){

        while(idx<=maxValue){
            tree[idx]+=value;
            idx+=idx&(-idx);
        }
    }

public: T cummulativesum(int idx){
        /* get sum upto sum=f[1]+f[2]+f[3]+...+f[idx]*/
        T sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }

public: T readSingle(int idx){
        T sum=tree[idx];
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

public:void setMaxValue(int value){
        maxValue=value;
    }

public:void setTreeValue(int value){
        for(int i=0;i<tree.size();i++)
            tree[i]=0;
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
LL inputData[50006];
vector<LL> inputData2;
int prob[50006];
char s[2];
map<LL,int> rankmap;
int main(){
    int tc,n,d,x,maxv=-1;
    double ans;
    cin>>tc;
    BIT<LL> bit1;
    while(tc--){
        //cin>>n>>d;
        scanf("%d%d",&n,&d);
        ans=0;
        for(int i=1;i<=n;i++){
            //cin>>inputData[i];
            scanf("%lld",&inputData[i]);
            if(maxv<inputData[i])
            {
                maxv=inputData[i];
            }
            if(maxv<(inputData[i]+d)){
                maxv=inputData[i]+d;
            }
            inputData2.push_back(inputData[i]);
            inputData2.push_back(inputData[i]+d);
        }
        for(int i=1;i<=n;i++){
           // cin>>prob[i];
            scanf("%d",&prob[i]);
        }
        sort(inputData2.begin(),inputData2.end());
        int rank=0;
        for(int i=0;i<inputData2.size();i++){
            if(rankmap.find(inputData2[i])==rankmap.end())
            {
                rank++;
                rankmap[inputData2[i]]=rank;
            }
        }
        bit1.initializeBit(rank);
        for(int i=n;i>=1;i--){

            ans+=(100-prob[i])*bit1.cummulativesum(rankmap[inputData[i]]-1);
            ans+=(prob[i])*bit1.cummulativesum(rankmap[inputData[i]+d]-1);
            bit1.update(rankmap[inputData[i]],100-prob[i]);
          //  bit1.printTree();
            bit1.update(rankmap[inputData[i]+d],prob[i]);
          //  bit1.printTree();
        }
        printf("%.4f\n",ans/10000.0);
        bit1.clearBit();
        rankmap.clear();
        inputData2.clear();
    }
    return 0;
}
