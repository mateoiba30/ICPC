#include <bits/stdc++.h>

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

using namespace std;

//esta estructura siempre encuentra el menor caso válido, donde l apunta a una posición inválida y r a la posible respuesta
bool binarySearch(vector <int> &v, int x) {
    // 0 a n-1  
    int n = v.size();
    int l = -1, r = n; //definimos punteros antes del primer índice y otro después del último índice, para asegurar que entre Right y Left siempre hayan elementos
    while(r-l > 1) { //mientras hayam 2 valores entre Right y Left. Si queda solo 1 ya es evaluado en la línea 21
        int med = (l+r)/2; //calculamos el índice del medio (es int para que no de con coma)
        if(v[med] >= x) //nos quedamos con la mitad correspondiente
            r = med; //l = med si busco el mayor
        else 
            l = med; //r = med si busco el mayor
    }
    //r es el puntero que puede tener la respuesta, porque es el que puede ser igual a x (v[l] solo puede ser menor)
    if(r == n) //analizar si nos quedamos con una posición inválida
                //if l == 0 si busco el mayor
        return false;  
    if(v[r] == x)  //v[l]==x si busco el mayor
        return true;
    else 
        return false;
}

int main() {
    FIN;
    int n, q;
    cin >> n >> q;
    vector <int> v(n);

    for(int i = 0; i < n; i++) 
        cin >> v[i];

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        bool ans = binarySearch(v,x);
        if(ans == true) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;   
}