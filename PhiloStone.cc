#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
#define lli long long int
void solve(){
	auto x=0,y=0; cin >> x >> y;
	vector<vector<int>> grid(x,vector<int>(y));
	for(auto i=0;i<x;i++) for(auto j=0;j<y;j++) cin >> grid[i][j];
	vector<vector<int>> mem(x,vector<int>(y));
	for(auto j=0;j<y;j++) mem[0][j] = grid[0][j];
	for(auto i=1;i<x;i++){
		for(auto j=0;j<y;j++){
			if(j==0) mem[i][j] = grid[i][j] + max(mem[i-1][j],mem[i-1][j+1]);
			else if (j==y-1) mem[i][j] = grid[i][j] + max(mem[i-1][j], mem[i-1][j-1]);
			else mem[i][j] = grid[i][j] + max(mem[i-1][j-1],max(mem[i-1][j],mem[i-1][j+1]));
				}
		}
	lli ans=LLONG_MIN;
	for(auto j=0;j<y;j++) if(mem[x-1][j] >= ans) ans = mem[x-1][j];
	cout << ans << endl;
return;
}
int main(){
	fastio();
	auto t=0; cin >> t;
	while(t--) solve();
return 0;
}
