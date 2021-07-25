#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() 
{
    string s;
    cin >> s;

    int ans = INT_MIN, cnt = 1, i;
    if(s.length() == 1) cout << 1;
    else{
        for(i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i+1]) cnt += 1;
        else cnt = 1;
            ans = max(ans, cnt);
        }

        cout << ans;
    }

	return 0;
}