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
pair<int, int> intervals[100001];

int check(int d){
    int numCows = 1;
    int currInterval = 0;
    int last = intervals[0].first;
    while(currInterval < m){
        int next = last + d;
        if(next <= intervals[currInterval].second){ //this is when our next position is inside a interval
            last = next; numCows++;
        }
        else{ //if the next optimal position is not inside of an interval
            while(next > intervals[currInterval].second && currInterval < m){
                currInterval++; //iterate until we can find a space to put our next cow
            }
            if(currInterval < m){ //if this next theoretical spot is possible
                if(next >= intervals[currInterval].first){//we just assign the cow to that place
                    last = next; numCows++;
                }
                else{ //if the next spot is before the next interval, we just put it on the beginning of the interval to be optimally positioned
                    last = intervals[currInterval].first; numCows++;
                }
            }
        }
    }
    if(numCows >= n){
        return true;
    }
    return false;
}


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
/*    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);*/
//-------------------------------------------------
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    /*for(int i = 0; i < m; i++){
        cout << intervals[i].first << " " << intervals[i].second << endl;
    }*/
    sort(intervals, intervals+m);
    /*for(int i = 0; i < m; i++){
        cout << intervals[i].first << " " << intervals[i].second << endl;
    }*/
    int low = 1; int right = intervals[m-1].second - intervals[0].first + 1;
    while(low < right){
        int mid = (low+right+1)/2;
        if(check(mid)){
            low = mid;
        }
        else{
            right = mid-1;
        }
    }
    cout << right << endl;

    return 0;
}
