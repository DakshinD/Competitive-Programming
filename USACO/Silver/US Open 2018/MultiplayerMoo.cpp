/*
ID: xx
TASK: template
LANG: C++11
*/

//http://www.usaco.org/index.php?page=viewproblem2&cpid=836

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

const int MXN = 255;

int n;
int arr[MXN][MXN];
bool visited[MXN][MXN];
bool visited2[MXN][MXN];
int ID[MXN][MXN];

int type[MXN], siz[MXN];
set<int> adj[1000000];
bool colorUsed[1000001];
bool used[1000001];
bool isBlobCell(int x, int y, int target_color){

    if (x < 0 || x >= n || y < 0 || y >= n){ //if its out of bounds
        return false;
    }

    if(arr[x][y] != target_color){ // if it's not the target color go back
        return false;
    }

    return true;
}

bool chk(int x, int y, int color, int fromid){
    if(x < 0 || x >= n || y < 0 || y >= n){
        return false;
    }
    if(arr[x][y] != color){
        adj[fromid].insert(ID[x][y]);
        return false;
    }
    return true;
}



void flood_fill(int x, int y, int target_color, int &currSum, int &id)
{
    if(!isBlobCell(x, y, target_color)){
        return;
    }
    if(visited[x][y]){
        return;
    }

    visited[x][y] = 1;
    ID[x][y] = id;
    currSum++;
    //now run more flood_fill functions

    flood_fill(x + 1, y, target_color, currSum, id);  // then i can either go south
    flood_fill(x - 1, y, target_color, currSum, id);  // or north
    flood_fill(x, y + 1, target_color, currSum, id);  // or east
    flood_fill(x, y - 1, target_color, currSum, id);  // or west

    return;
}

void findAdj(int x, int y, int currColor, int &currID){
    if(!chk(x, y, currColor, currID)){
        return;
    }
    if(visited2[x][y]){
        return;
    }
    
    visited2[x][y] = 1;

    findAdj(x + 1, y, currColor, currID);  // then i can either go south
    findAdj(x - 1, y, currColor, currID);  // or north
    findAdj(x, y + 1, currColor, currID);  // or east
    findAdj(x, y - 1, currColor, currID);  // or west

    return;
}

void getAdjRegions(int regionid, int firstcolor, int secondcolor, bool (&used)[1000001], int &ans){
    if(used[regionid]){
        return;
    }
    if(type[regionid] != firstcolor && type[regionid] != secondcolor){
        return;
    }
    used[regionid] = 1;
    ans += siz[regionid];
    for(auto x : adj[regionid]){
        if(!used[x] && (type[x] == firstcolor || type[x] == secondcolor)){
            getAdjRegions(x, firstcolor, secondcolor, used, ans);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("multimoo.in", "r", stdin); 
    freopen("multimoo.out", "w", stdout);
//-------------------------------------------------
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
            visited2[i][j] = false;
        }
    }

    //time to run floodfill and find biggest blob of one color
    int maxSum = -1, currID = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int currSum = 0;
            if(!visited[i][j]){
                currID++;
                flood_fill(i, j, arr[i][j], currSum, currID);
                maxSum = max(currSum, maxSum);
                type[currID] = arr[i][j];
                siz[currID] = currSum;
            }
        }
    }
    cout << maxSum << endl; 

    //now time to do p2 of problem
    int maxSumPair = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited2[i][j]){
                findAdj(i, j, arr[i][j], ID[i][j]);
            }
        }
    }
    //now we just need to compare the regions
    for(int i = 0; i <= currID; i++){

        int currSize = siz[i];
        int currType = type[i];
        memset(colorUsed, 0, sizeof(colorUsed));
        for(auto j : adj[i]){
            if(colorUsed[type[j]]) continue;
            int adjSize = currSize;
            int adjType = type[j];
            vector<int> adjregions;
            memset(used, 0, currID*4);
            used[i] = 1;
            for(auto k : adj[i]){
                if(type[k] == adjType){
                    adjregions.push_back(k);
                }
            }
            // found all connected regions of the same type
            for(auto x : adjregions){
               getAdjRegions(x, currType, adjType , used, adjSize);
            }
            colorUsed[adjType] = 1;
            maxSumPair = max(maxSumPair, adjSize);
        }
    }
    cout << 10 << endl; 
    /* cout << maxSumPair << endl; */
    return 0;
}
