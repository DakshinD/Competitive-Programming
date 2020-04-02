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

int n, m;
pii cows[100001];
int foodTypes[100001];
int ans[100001];
int main() {
//CHECK LIMITS U RARTED DUMBO - 10^9 too SLO for BF
//FIND PATTERN IF TOO SLOW FOR BRUTE FORCE
//CHECK ALL PARAMETERS
//MAKE SURE YOU FIGURE OUT WHICH YOU USE (int vs ll)
//WRITE SOL ON PAPER BFR IMPLEMENTING
//WRITE YOUR OWN TEST CASES TO DEAL WITH EDGE CASES
//lower_bound will give you the soonest place the inputted
//number can be put in a sorted array, and upper_bound
//will give you the last place a number can be put
//in a sorted array, good for range querys
   /* ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);*/
//-------------------------------------------------
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        cows[i].first = a;
        cows[i].second = b;
    }
    //reverse(cows, cows+n);

    fill(ans, ans+n, 0);
    for(int i = 0; i < n; i++){
        fill(foodTypes, foodTypes+n, 1);
        int satisfied = 0;
        for(int j = i; j < n; j++) {
            if (foodTypes[cows[j].first] != 0) {
                foodTypes[cows[j].first]--;
                satisfied++;
            } else if (foodTypes[cows[j].second] != 0) {
                foodTypes[cows[j].second]--;
                satisfied++;
            }
        }
        cout << satisfied << endl;
    }
   /* for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }*/

    return 0;
}

