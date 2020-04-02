//http://www.usaco.org/index.php?page=viewproblem2&cpid=991

#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
typedef long double ld;



#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'
const ll INF = 1e18;
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

ll n, k, m, x;
ll ans;

bool check(ll x){
    ll needToGive = n;
    ll given = 0; //gallons given
    //do calculations to see if this value of x suffices in k days
    for(int i = 0; i < k; i++){
        ll y = (needToGive - given)/x; //calculating y
        if(y < m){
            y = m;
        }
        given += y;
    }

    //see if this value of x suffices in the given amount of days
    return given >= needToGive;

}


int bSearch(ll low, ll right){
    if(low == right){
        return low;
    }
    if(low + 1 == right) {
        if (check(low)) {
            return low;
        } else {
            return right;
        }
    }
    ll mid = (low+(right - low))/2;
    if(check(mid)){
        return bSearch(mid+1, right);
    }
    else{
        return bSearch(low, mid);
    }
}



int main() {
//CHECK LIMITS U RARTED DUMBO - 10^9 too SLO for BF
//FIND PATTERN IF TOO SLOW FOR BRUTE FORCE
//CHECK ALL PARAMETERS
//MAKE SURE YOU FIGURE OUT WHICH YOU USE (int vs ll)
//WRITE SOL ON PAPER BFR IMPLEMENTING
//WRITE YOUR OWN TEST CASES TO DEAL WITH EDGE CASES
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
//-------------------------------------------------
    cin >> n >> k >> m;
    cout << bSearch(0, 1000000000000000);




    return 0;
}


