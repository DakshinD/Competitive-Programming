#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> mpq;

const ll INF = 1e18;
const int mod = 1e9+7;
const int dX[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#define whatis(x) cerr << #x << " is " << x << endl;
#define endl "\n"
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define FOR(i, a) for(int i = 0; i < a; i++)
#define FoR(i, a) for(int i = 1; i <= a; i++)
#define ROF(i, a) for (int i = (a)-1; i >= 0; i--)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

void readIn(string fileName) { freopen(fileName.c_str(), "r", stdin); }
void writeOut(string fileName) { freopen(fileName.c_str(), "w", stdout); }
void syncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string str = ""){ syncIO(); if(sz(str)) { readIn(str+".in"), writeOut(str+".out"); }}

int main(){
    string fileName = "filename"; setIO(fileName);
//-------------------------------------------------

    return 0;
    // Read notes to self
}

/* NOTES TO SELF:
 * Check for int vs ll, worst case just switch everything to ll
 * Check for array bounds if you SEGFAULT, especially in range based loops
 * Always initialize everything in global 
 * Edge cases such as n = 1 or 0
 * Make sure to calculate big O complexity
 * You are geniosity you got this
 */


