//http://www.usaco.org/index.php?page=viewproblem2&cpid=990

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
#define pb push_back
#define MP make_pair
#define endl '\n'
const ll INF = 1e18;
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
bool comp(int a, int b){
    return a>b;
}
int main() {
//CHECK LIMITS U RARTED DUMBO - 10^9 too SLO for BF
//FIND PATTERN IF TOO SLOW FOR BRUTE FORCE
//CHECK ALL PARAMETERS
//MAKE SURE YOU FIGURE OUT WHICH YOU USE (int vs ll)
//WRITE SOL ON PAPER BFR IMPLEMENTING
//WRITE YOUR OWN TEST CASES TO DEAL WITH EDGE CASES
/*    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);*/
//-------------------------------------------------
    int n, k; cin >> n >> k;
    int berries[n];
    for(int i = 0; i < n; i++){
        cin >> berries[i];
    }
    //now solve
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        int x = 0; //this will store how many baskets of size i we can get
        vector<int> leftovers; //we can store the leftovers in this vector
        for(int j = 0; j < n; j++){
            x += berries[j]/i;
            leftovers.pb(berries[j]%i);
        }
        if(x >= k){ //this means this value of i works
            ans = max(ans, i*(k/2));
            continue;
        }
        if(x < k/2){
            continue;
        }
            int currTotal = (x-k/2)*i;
            sort(leftovers.begin(), leftovers.end(),comp);
            for(int j = 0; j <n && j<k-x; j++){ //so we loop through leftovers until we have k baskets
                currTotal += leftovers[j];
            }
            ans = max(ans, currTotal);

    }
    cout << ans;

    return 0;
}

