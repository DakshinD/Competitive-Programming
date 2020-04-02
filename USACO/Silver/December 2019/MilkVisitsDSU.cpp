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
char cowTypes[100001];
bool visited[100001];
vector<int> adjList[100001];

struct DSU {
    int dsu[100001];
    int sizes[100001];

    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int a) {
        if (dsu[a] == a) return a;
        return (dsu[a] = find(dsu[a]));
    }

//weighted union function
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sizes[a] < sizes[b])
                swap(a, b);
            dsu[b] = a;
            sizes[a] += sizes[b];
        }
    }


    bool isSameSet(int a, int b){
        int x = find(a);
        int y = find(b);
        return x == y;
    }

};

DSU dsu;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
//-------------------------------------------------
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cowTypes[i];
    }
    dsu.make_set(100001);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        if(cowTypes[dsu.find(x)] == cowTypes[dsu.find(y)] && !dsu.isSameSet(x, y)){
            dsu.join(x, y);
        }
    }
    /*for(int i = 0; i < n; i++){
        cout << dsu.find(i) << endl;
    }*/
    int a, b;
    char c;
    string ans;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--;b--;
        if((!dsu.isSameSet(a,b) || cowTypes[dsu.find(a)] == c || cowTypes[dsu.find(b)] == c)) {
            //cout << "i got here at " << a << " " << b << " " << dsu.find(a) << " " << dsu.find(b) << endl;
            ans += "1";
        }
        else {
            ans += "0";
        }
    }
    cout << ans << endl;
    return 0;
}

