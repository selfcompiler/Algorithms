// http://codeforces.com/problemset/problem/779/D

//
// Created by RAHUL KUMAR SINGH on 26/02/17.
//

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
#define REP(i,n) for (int i = 0; i < n; i++)

template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }

const double eps = 1e-8;
const double pi = acos(-1.0);
const ll inf = 1e17 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;



const int MAXN = 200005;

char S[MAXN], T[MAXN];
int P[MAXN];
int N, M;

bool present[MAXN];

bool can(int x) {
    REP(i, N) {
        present[i] = true;
    }
    for (int i = 0; i < x; i++) {
        present[P[i]] = false;
    }

    int t = 0;
    REP(i, N) if (present[i]) {
            if (S[i] == T[t]) {
                t++;
            }
            if (t == M) {
                return true;
            }
        }
    return false;
}

int main() {
    scanf("%s %s", S, T);
    N = strlen(S);
    M = strlen(T);

    REP(i, N) {
        scanf("%d", &P[i]);
        P[i]--;
    }

    int lo = 0, hi = N;
    int res;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can(mid)) {
            res = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    printf("%d\n", res);
}
