
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

int n, m; //n is # of cows, m is # of wormholes
int maxWormholeSize = 0;
int numAlrdySorted = 0;
int numVisited = 0;
int startNode = 0;
bool doesItWork = false;
int cows[100001]; //this holds our cows
vector<pii> adjList[100001]; //.first will be the actual nodes, and the .second will be the weight
int visited[100001];



void dfs(int currentNode, int restrictSize){
    if(visited[currentNode]) { //break if we have already visited this node
        return;
    }
    visited[currentNode] = true;
    if(cows[currentNode] != currentNode)
        numVisited++;
    for(pair<int, int> j : adjList[currentNode]){
        if(!visited[j.first] && j.second >= restrictSize)
            dfs(j.first, restrictSize);
    }
    if(numVisited >= n - numAlrdySorted){
        doesItWork = true;
    }
}


int bSearch(int low, int right){
    if(low == right){
        return low;
    }
    if(low + 1 == right) {
        dfs(startNode, right);
        if (doesItWork) {
            return right;
        } else {
            return low;
        }
    }
    int mid = (right + low)/2;
    dfs(startNode, mid);
    if(doesItWork){
        numVisited = 0;
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        doesItWork = false;
        return bSearch(mid, right);
    }
    else{
        numVisited = 0;
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        doesItWork = false;
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
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
//-------------------------------------------------
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
        if(cows[i]-1 == i){
            numAlrdySorted++;
        }
        else{
            startNode = i;
        }
        cows[i]--; //so that we can use 0 indexed stuff
    }
    //we can take in the wormholes as edges between our cows
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        adjList[x-1].pb(make_pair(y-1,z));
        adjList[y-1].pb(make_pair(x-1,z));
        maxWormholeSize = max(maxWormholeSize, z); //this is for the right parameter of our binsearch
    }
    if(is_sorted(cows, cows+n)){
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        //now we are going to need to run binsearch on a the weight of min wormhole
        int ans = bSearch(1, maxWormholeSize + 100);
        cout << ans;
    }

    return 0;
}
//Sum formula n^1 = n(n+1)/2
//Sum formula n^2 = n(n+1)(2n+1)/6
//Arithmetic (Constant) Progression = n(a+b)/2
//Geometric Progression = (bk-a)/(k (ratio difference)-1)
//1+2+4+8+...+2^(n−1) = 2^n − 1.
//sumq(a,b) = sumq(0,b)−sumq(0,a−1)

