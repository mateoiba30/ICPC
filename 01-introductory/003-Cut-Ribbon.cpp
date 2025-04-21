#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	int ans = 0;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			int suma = a*i + b*j; //voy probando todas las posibles combinaciones de cortes de tamaño a o b
			if(suma > n) continue; //me aseguro de no pasarme
			if((n-suma)%c != 0) continue; //si ya no queda nada por cortar o si el lugar restante se puede cortar en pedazos de tamaño C
			ans = max(ans,i+j+(n-suma)/c); //cant de cortes = i (cortes tamaño a) + j (cortes tamaño b) + cortes_de_tamaño_C: me fijo si la nueva respuesta es mejora que la anterior
		}
	}
	cout << ans << "\n";
	return 0;
}

/*
hay que prestarle atención a las cotas

Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.

Input
The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.

Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.
*/