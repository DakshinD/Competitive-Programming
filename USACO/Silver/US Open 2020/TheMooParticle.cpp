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

int n;
pair<int, int> particles[100001];
vector<int> adjList[100001];
int ctr = 0;
bool visited[100001]; //this will keep track if a particle has been obliterated by another particle

bool comp(pii a, pii b){
        return a.first > b.first;
}

void dfs(int currentNode){
    if(visited[currentNode]){
        return;
    }
    visited[currentNode] = true;
    for(int j : adjList[currentNode]){
        if(!visited[j]){
            dfs(j);
        }
    }
}

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
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
//-------------------------------------------------
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> particles[i].first >> particles[i].second;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(particles[i].first >= particles[j].first && particles[i].second >= particles[j].second && particles[i] != particles[j]){
                adjList[i].pb(j);
                adjList[j].pb(i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }


    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            ctr++;
        }
    }
    cout << ctr;


    return 0;
}

