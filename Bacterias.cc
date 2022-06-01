#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
#define lli long long int
int main(){
	fastio();
	auto x=0,y=0; cin >> x >> y;
	vector<vector<int>> grid(x,vector<int>(y));
	for(auto i=0;i<x;i++) for(auto j=0;j<y;j++) cin >> grid[i][j];
	//Solución bottom-up
	/*
	Hacemos una prefix sum a la primera fila y primer columna de nuestra tabla ya que eso representa movernos estrictamente hacia la derecha o
	hacia abajo. Y no podemos llegar a esos puntos de otra manera, debido a las restricciones del problema.
	Para continuar con el llenado analizamos un poco y vemos igual que podemos llegar de varias maneras, la primera es desde arriba 
	(es decir nos movemos hacia abajo) y la segunda es desde la izquierda (es decir nos movemos hacia la derecha) y como se nos solicita el mínimo simplemente
	elegimos el menor entre la posición de arriba o el de la izquierda a partir de donde estemos parados, esto nos garantizará el movimiento más óptimo
	y al terminar de llenar la tabla nuestra respuestá se encontrará en la última posición de la tabla (es decir mem[i][j])
	*/
	vector<vector<int>> mem(x,vector<int>(y));
	mem[0][0] = grid[0][0];
	for(auto i=1;i<x;i++) mem[i][0] = mem[i-1][0] + grid[i][0];
	for(auto j=1;j<y;j++) mem[0][j] = mem[0][j-1] + grid[0][j];
	for(auto i=1;i<x;i++){
		for(auto j=1;j<y;j++){
			mem[i][j] = min(mem[i-1][j]+grid[i][j],mem[i][j-1]+grid[i][j]);
			}
		}
	cout << mem[x-1][y-1] << endl;
return 0;
}
