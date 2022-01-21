#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool sortBySecond(pair<int,int>& a, pair<int,int>& b){
    return a.second < b.second; 
}
int main() 
{
    int n, i;
    cin >> n; 
    vector<pair<int,int>> v(n); 
    for(i = 0; i < n; ++i) cin >> v[i].first >> v[i].second; 
    sort(v.begin(), v.end(), sortBySecond);
    pair<int,int> start = v[0];
    for(i = 1; i < n; ++i){
        if(v[i].first >= start.second) v.erase(v.begin() + i);
    }
    cout << v.size() << "\n";

	return 0;
}