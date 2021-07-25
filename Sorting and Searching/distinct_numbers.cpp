#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    int n;
    cin >> n; 

    int a[n], i;
    set<int> s;
    for(i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    cout << s.size();
	return 0;
}