//http://www.usaco.org/index.php?page=viewproblem2&cpid=966

#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


#define F first
#define S second
#define pb push_back
#define MP make_pair
#define endl '\n'
const ll INF = 1e18;
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

int main() {
//CHECK LIMITS U RARTED DUMBO - 10^9 too SLO for BF
//FIND PATTERN IF TOO SLOW FOR BRUTE FORCE
//CHECK ALL PARAMETERS
//MAKE SURE YOU FIGURE OUT WHICH YOU USE (int vs ll)
//WRITE SOL ON PAPER BFR IMPLEMENTING
//WRITE YOUR OWN TEST CASES TO DEAL WITH EDGE CASES
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
//-------------------------------------------------
    int n; cin >> n;
    int sum = 0;
    if(n%8==0){
        sum = 14;
    }
    if(n%8==1){
        sum = 1;
    }
    if(n%8==2){
        sum = 2;
    }
    if(n%8==3){
        sum = 4;
    }
    if(n%8==4){
        sum = 7;
    }
    if(n%8==5){
        sum = 8;
    }
    if(n%8==6){
        sum = 11;
    }
    if(n%8==7){
        sum = 13;
    }
    cout << sum + (15*((n-1)/8));

    return 0;
}

