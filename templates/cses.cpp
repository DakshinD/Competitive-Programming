#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma comment(linker, "/stack:200000000")

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
const ll NINF = -1e18;
const int inf = 1e9+5;
const int ninf = -(1e9+5);
const int mod = 1e9+7;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#define whatis(x) cerr << #x << " is " << x << endl;
#define dbg(x, n) for(int i = 0; i < n; i++) cerr << x[i] << " ";cout << endl;
#define yes() cout << "YES" << endl;
#define no() cout << "NO" << endl;
#define here() cout << "here" << endl;
#define endl "\n"
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ft front()
#define bk back()
#define sz(x) (long long)x.size()
#define all(x) (x).begin(), (x).end()
#define ub upper_bound
#define lb lower_bound
#define trav(a, x) for(auto a : x)
#define travto(a, x) for(auto& a : x)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FoR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a-1; i >= b; i--)
#define RoF(i, a, b) for (int i = a-1; i > b; i--)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

int rup(int a, int b){return (a+b-1)/b;}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
//-----------------------| Template By: Dakshin Devanand |----------------------------


int main(){
    
    return 0;
    // Read notes to self
}

/* NOTES TO SELF:
 * See if the restrictions can hint at a solution!
 * Check for int vs ll, worst case just switch everything to ll
 * Check for array bounds if you SEGFAULT, especially in range based loops
 * Always initialize everything in global 
 * Edge cases such as n = 1 or 0
 * Make sure to calculate big O complexity
 * You are geniosity you got this
 */
