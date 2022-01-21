#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n, m, k, i; 
    cin >> n >> m >> k; 
    vector<int> customers(n), apts(m); 
    for(i = 0; i < n; ++i) cin >> customers[i];
    for(i = 0; i < m; ++i) cin >> apts[i];

    sort(customers.begin(), customers.end());
    sort(apts.begin(), apts.end()); 

    int ans = 0;
    int j = 0; 
    i = 0;
    while(i < n && j < m){
       if(abs(customers[i] - apts[j]) <= k){
           ans += 1; 
           i += 1;
           j += 1; 
       }else{
           if(customers[i] - apts[j] > k){
               j += 1; 
           }
           else{
               i += 1; 
           }    
       }
    }
    cout << ans << "\n";
    
	return 0;
}