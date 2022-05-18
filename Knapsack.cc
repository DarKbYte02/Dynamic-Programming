#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
#define lli long long int

int solve(int i, int sack, vector<pair<int,int>>& a,vector<vector<int>>& mem){
	if(i < 0) return 0;
	if(mem[i][sack] != -1) return mem[i][sack];
	if(sack < a[i].first) return mem[i][sack] = solve(i-1,sack,a,mem);
	else return mem[i][sack] = max(a[i].second + solve(i-1,sack-a[i].first,a,mem),solve(i-1,sack,a,mem));
}
int main(){
	fastio();
	int sack,n; cin >> sack >> n;
	vector<pair<int,int>> a(n);
	for(auto i=0;i<n;i++) cin >> a[i].first >> a[i].second;
	vector<vector<int>> mem(n+10,vector<int>(sack+10,-1));
	cout << solve(n-1,sack,a,mem) << endl;
return 0;
}
