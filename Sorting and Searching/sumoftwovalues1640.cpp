#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x; 
    vector<int> a(n);
    int i;
    map<int,int> numToIdx; 
    for(i = 0; i < n; ++i){
        cin >> a[i];
        numToIdx[a[i]] = i+1; 
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int ans1 = -1, ans2 = -1;
    while(l < r){
        if(a[l] + a[r] == x){
            ans1 = a[l];
            ans2 = a[r];
            break;
        }
        if(a[l] + a[r] > x) r--;
        else if(a[l] + a[r] < x) l++; 
        
    }
    if(ans1 && ans2) cout << numToIdx[ans1] << " " << numToIdx[ans2] << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}