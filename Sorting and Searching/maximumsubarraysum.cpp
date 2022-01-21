#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    ll n, i;
    cin >> n; 
    vector<ll> a(n);
    for(i = 0; i < n; ++i) cin >> a[i];

    ll cur_max = a[0], global_max = a[0];
    for(i = 1; i < n; ++i){
        cur_max = max(a[i], cur_max + a[i]);
        if(cur_max > global_max) global_max = cur_max;
    }
    cout << global_max; 
	return 0;
}