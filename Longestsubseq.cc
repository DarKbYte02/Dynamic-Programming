#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
#define lli long long int
const int MAXN = 1e3+1;

int solve(int i, int j, string& a, string& b,vector<vector<int>>& mem){
	if(i >= a.size() || j >= b.size()) return 0;
	if(a[i] == b[j]) return mem[i][j] = 1+solve(i+1,j+1,a,b,mem);
	if(mem[i][j] != -1) return mem[i][j];
	return mem[i][j] = max(solve(i+1,j,a,b,mem),solve(i,j+1,a,b,mem));
}
int main(){
	fastio();
	string a,b; cin >> a >> b;
	vector<vector<int>> mem(MAXN,vector<int>(MAXN,-1));
	cout << solve(0,0,a,b,mem) << endl;
return 0;
}
