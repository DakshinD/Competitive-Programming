//http://www.usaco.org/index.php?page=viewproblem2&cpid=968

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
int n, m;
int currComponentID = 0;
bool visited[100001]; //visited array to keep track of nodes we have already gone to
int comp[100001];
int cowTypes[100001]; //vector to keep track of cow types
vector<int> adjList[100001]; //adjacency list for dfs


void dfs(int currentNode){

    if(visited[currentNode]) { //break if we have already visited this node
        return;
    }
    visited[currentNode] = true; //set this node's ID to match it's component
    comp[currentNode] = currComponentID;

    for(int j : adjList[currentNode]){
        if(!visited[j] && cowTypes[currentNode] == cowTypes[j])
            dfs(j);
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
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
//-------------------------------------------------
    cin >> n >> m;
    //taking in types of Cows in the Farms
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        cowTypes[i] = c;
    }

    //taking input into adjacency list
    for(int i = 0; i < n-1; i++){
        int one, two;
        cin >> one >> two;
        adjList[one-1].push_back(two-1);
        adjList[two-1].push_back(one-1);
    }

    //time to dfs to mark connected components


    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    for(int i = 0; i < n; i++) {
        dfs(i);
        currComponentID++;
    }

    //done with dfs, now we can take queries
    for(int q = 0; q < m; q++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        //done taking input now check the two nodes components IDs
        if(comp[a] != comp[b] || cowTypes[a] == c || cowTypes[b] == c)
            cout << 1;
        else
            cout << 0;
    }




    return 0;
}
//Sum formula n^1 = n(n+1)/2
//Sum formula n^2 = n(n+1)(2n+1)/6
//Arithmetic (Constant) Progression = n(a+b)/2
//Geometric Progression = (bk-a)/(k (ratio difference)-1)
//1+2+4+8+...+2^(n−1) = 2^n − 1.

