#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
	ll n;
	cin >> n; 
	cout << n << " ";
	while(n != 1){
		n % 2 == 0 ? n /= 2 : n = 3*n + 1;
		cout << n << " ";
	}
	return 0;
}