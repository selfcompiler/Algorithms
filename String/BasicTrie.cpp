//
// Created by RAHUL KUMAR SINGH on 03/03/17.
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

map<char,int> charIndex;
#define MAX_NUMBER_OF_NODES 10005
#define MAX_ASCII_CODE 30

void assignCharIndex(){
    for(int i='0';i<='9';i++){
        charIndex[i]=i-'0'+1;
    }
}
struct trieNode{
    bool isWord;
    int wordCount;
    int prefixCount;
    int nextIndex;
};
struct trieNode Trie[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE];
int nextCounter = 1; //initially all numbers in x are -1
void initialize(){
    for(int i=0;i<MAX_NUMBER_OF_NODES;i++){
        for(int j=0;j<MAX_ASCII_CODE;j++){
            Trie[i][j].isWord=false;
            Trie[i][j].prefixCount=0;
            Trie[i][j].wordCount=0;
            Trie[i][j].nextIndex=-1;
        }
    }
}
void insert(string s){
    int i = 0, v = 0;
    while(i < s.size()){
        if(Trie[v][charIndex[s[i]]].nextIndex == -1)
        {
            Trie[v][charIndex[s[i]]].prefixCount++;
            if((i+1)==s.size()){
                Trie[v][charIndex[s[i]]].isWord=true;
                Trie[v][charIndex[s[i]]].wordCount++;
            }
            v = Trie[v][charIndex[s[i]]].nextIndex = nextCounter++;
        }
        else
        {
            Trie[v][charIndex[s[i]]].prefixCount++;
            if((i+1)==s.size()){
                Trie[v][charIndex[s[i]]].isWord=true;
                Trie[v][charIndex[s[i]]].wordCount++;
            }
            v = Trie[v][charIndex[s[i]]].nextIndex;
        }
        i++;
    }
}

bool searchInTrie(string s){
    int i = 0, v = 0;
    while(i < s.size()){
        if(Trie[v][charIndex[s[i]]].nextIndex == -1)
            return false;
        else
            v = Trie[v][charIndex[s[i]]].nextIndex;
        i++;
    }
    return true;
}
int main(){
    string enter;
    string search;
    int tc;
    cin>>tc;
    assignCharIndex();
    initialize();
    while(tc--){
        cin>>enter;
        insert(enter);
        cin>>search;
        if(searchInTrie(search))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
