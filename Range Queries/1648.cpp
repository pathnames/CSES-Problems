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
int segtree[MAX_N], a[MAX_N];

void build(int node, int start, int end){
    if(start == end){
        segtree[node] = a[start]; 
        return; 
    }else{
        int mid = start + (end - start)/2; 
        build(2*node + 1, start, mid);
        build(2*node + 2, mid + 1, end);
        segtree[node] = segtree[2*node+1] + segtree[2*node+2];
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start || end < l) return 0; 
    if(l <= start && end <= r) return segtree[node]; 

    int mid = (start + end)/2; 
    int p1 = query(2*node + 1, start, mid, l, r);
    int p2 = query(2*node + 2, mid+1, end, l, r);
    return (p1 + p2); 
}

void update(int node, int start, int end, int l, int idx, int val){
    if(start == end){
        segtree[node] += val; 
        a[node] += val; 
        return; 
    }

    int mid = start + (end - start)/2; 
    if(start <= idx && idx <= mid){
        update(2*node, start, mid, idx, val); 
    }
    update(2*node + 1, start, mid, l, r, val);
    update(2*node + 2, mid+1, end, l, r, val); 
    segtree[node] = segtree[2*node+1] + segtree[2*node+2];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q; 
    cin >> n >> q; 
    int i; 
    for(i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n-1);
    for(i = 0; i < q; ++i){
        int d, e, f;
        cin >> d >> e >> f; 
        if(d == 1){
            //update
            update(0, 0, n-1, e-1, f-1);
        }else{
            //query
            cout << query(0, 0, n-1, e - 1, f - 1) << "\n"; 
        }
    }
    return 0; 
}