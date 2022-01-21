#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n;
    cin >> n; 
    if(n == 1) cout << 1 << "\n";
    else{
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        set<int> s; 
        int l = 0, r = 0, cur_max = INT_MIN, global_max = INT_MIN; 
        while(l < n && r < n){
            if(s.find(a[l]) == s.end()) s.insert(a[l]); 
            
        }
    }
 

	return 0;
}