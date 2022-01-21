#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 2 * (1e5);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int LOG = 20;
ll m[MAX_N][LOG]; 
ll binlog[MAX_N];

ll query(ll L, ll R){
    ll length = R - L + 1; 
    ll k = (binlog[length]); 
    return min(m[L][k], m[R - (1<<k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, q, i; 
    cin >> n >> q; 
    vector<ll> a(n); 
    binlog[1] = 0; 
    for(i = 2; i <= n; ++i){
        binlog[i] = binlog[i/2] + 1; 
    }
    //Preprocessing: O(N*log(N))
    //m[i][j] here i = starting position of query, j = power of two so m[i][j] is the minimum value from [i, i + 2^j]
    //m[i][0] = a[i] itself since 2^0 = 1 and minimum of each query of size 1 is the number itself. 
    for(i = 0; i < n; ++i){
        cin >> a[i];
        m[i][0] = a[i];
    }

    //k = powers of 2, i = starting position. 
    for(ll k = 1; k < LOG; ++k){
        for(i = 0; i + (1 << k) - 1 < n; ++i){
            m[i][k] = min(m[i][k-1], m[i + (1 << (k - 1))][k-1]); 
        }
    }
    for(i = 0; i < q; ++i){
        ll a,b;
        cin >> a >> b; 
        a -= 1; 
        b -= 1; 
        cout << query(a,b) << "\n";
    }
    return 0; 
}