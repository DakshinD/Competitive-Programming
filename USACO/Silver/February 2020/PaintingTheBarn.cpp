//http://www.usaco.org/index.php?page=viewproblem2&cpid=992

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

int n, k;
int arr[1001][1001];

int main() {
//CHECK LIMITS U RARTED DUMBO - 10^9 too SLO for BF
//FIND PATTERN IF TOO SLOW FOR BRUTE FORCE
//CHECK ALL PARAMETERS
//MAKE SURE YOU FIGURE OUT WHICH YOU USE (int vs ll)
//WRITE SOL ON PAPER BFR IMPLEMENTING
//WRITE YOUR OWN TEST CASES TO DEAL WITH EDGE CASES
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
//-------------------------------------------------
    cin >> n >> k;
    int a, b, c, d;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        for(int j = a; j < c; j++){
            arr[j][b]++;  //we mark when the rectangle begins and when it ends wth 1s and -1s, this is because we take psumss of columns
            arr[j][d]--;
        }
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++) {
            if (arr[i][j] == k)
                ans++;
            arr[i][j + 1] += arr[i][j];
        }
    }


    cout << ans;

    return 0;
}
//Sum formula n^1 = n(n+1)/2
//Sum formula n^2 = n(n+1)(2n+1)/6
//Arithmetic (Constant) Progression = n(a+b)/2
//Geometric Progression = (bk-a)/(k (ratio difference)-1)
//1+2+4+8+...+2^(n−1) = 2^n − 1.
//sumq(a,b) = sumq(0,b)−sumq(0,a−1)
