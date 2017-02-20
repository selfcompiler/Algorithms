//
// Created by RAHUL KUMAR SINGH on 20/02/17.
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
#define S2(x,y) scanf("%d%d",&x,&y)
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

const double eps = 1e-8;
const double pi = acos(-1.0);
const ll inf = 1e17 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;
#define PATTERN_SIZE 2000
string pattern;
int lcp[PATTERN_SIZE]={0};
void computeLcp(){
    int m=pattern.length();
    int len=0;
    lcp[0]=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lcp[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lcp[len-1];
            }
            else{
                lcp[i]=0;
                i++;
            }
        }
    }
}

void kmpSearch(string text){
    int n=text.length();
    int m=pattern.length();
    int i=0,j=0; // i for text, j for pattern
    while(i<n){
        if(pattern[j]==text[i]){
            i++,j++;
        }
        if(j==m){
            cout<<"Pattern Found";
            j=lcp[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0)
                j=lcp[j-1];
            else
                i=i+1;
        }
    }
}
int main(){
    pattern="da";
    computeLcp();
    kmpSearch("dasdasdasfasfa");
    return 0;
}
