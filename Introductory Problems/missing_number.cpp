#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    ll n, i;
    bool flag = true;
    cin >> n; 

    if(n == 2){
        int t;
        cin >> t;
        t == 2 ? cout << 1 : cout << 2;
    }
    
    else{
       vector<int> v(n-1); 
       for(i = 0; i < n - 1; i++) cin >> v[i];

       sort(v.begin(), v.end());

       if(v[0] != 1){
           cout << 1;
       }else if(v[n-2] != n){
           cout << n;
       }else{
           for(i = 1; i < n - 1; i++){
               if(v[i] - v[i-1] != 1) cout << v[i-1] + 1;
           }
       }
    }
  
	return 0;
}