#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n, m, i;
    cin >> n >> m; 
    vector<int> p(n), c(m); 
    for(i = 0; i < n; ++i) cin >> p[i];
    for(i = 0; i < m; ++i) cin >> c[i]; 

    sort(p.begin(), p.end());

    for(auto customer : c){
        int l = 0, r = n - 1; 
        bool found = false; 
        while(l < r){
            int mid = l + (r-l)/2; 
            if(p[mid] == customer){
                cout << p[mid] << "\n"; 
                found = true; 
                break; 
            }
            else if(p[mid] > customer) r = mid - 1; 
            else l = mid + 1; 
        }
        if(!found) cout << p[l] << "\n";
    }
   


	return 0;
}