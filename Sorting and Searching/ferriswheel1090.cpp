#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n, x, i;
    cin >> n >> x; 
    vector<int> a(n);
    for(i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    int l = 0, r = n - 1, ans = 0; 
    while(l < r){
        if(a[l] + a[r] > x){
            r--; 
            ans += 1; 
        }else if(a[l] + a[r] <= x){
            ans += 1; 
            l++;
            r--;
        }
    }
    if(l == r) ans += 1; 
    cout << ans << "\n";

	return 0;
}