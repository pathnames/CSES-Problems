#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
   int n, m; 
   vector<vector<pair<int,int>>> adj(n+1);
   
   int a,b,c, i; 
   for(i = 1; i <= m; ++i){
       cin >> a >> b >> c; 
       adj[a].push_back({b,c}); 
   }
   vector<int> dist(n+1, INT_MAX); 
   
	return 0;
}