#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n;
    cin >> n; 

    int a[n], i;
    for(i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for(i = 1; i < n; i++){
        if(a[i] < a[i-1]) sum += a[i-1] - a[i];
    }

    cout << sum;

	return 0;
}