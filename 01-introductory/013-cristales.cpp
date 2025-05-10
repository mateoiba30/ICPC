#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FIN;

    int n, espacios, Ds;
    cin >> n;

    espacios = (n-1)/2;
    Ds = 1;
    for(int i=0; i<(n-1)/2; i++){
        for(int j=0; j<espacios; j++) cout << "*";
        for(int j=0; j<Ds; j++) cout << "D";
        for(int j=0; j<espacios; j++) cout << "*";
        espacios--;
        Ds+=2;
        cout << "\n";
    }

    for(int i=0; i<n; i++) cout << "D";
    cout << "\n";

    espacios = 1;
    Ds = n-2;
    for(int i=0; i<(n-1)/2; i++){
        for(int j=0; j<espacios; j++) cout << "*";
        for(int j=0; j<Ds; j++) cout << "D";
        for(int j=0; j<espacios; j++) cout << "*";
        espacios++;
        Ds-=2;
        cout << "\n";
    }

    return 0;
}

/*
E. Los cristales del Turko
time limit per test1 s.
memory limit per test256 MB
El Turko una vez agarró un cristal en una mina. Un cristal de tamaño n
 (n
 es impar; n>1
) es una matriz n×n
 con un diamante inscrito.

Se te da un entero impar n
. Y tu debes dibujar un cristal tamaño n
. Las celdas de diamante de la matriz deben representarse con el carácter "D". Todas las demás celdas de la matriz deben representarse con el carácter "*". Observe los ejemplos para comprender qué debe dibujar.

Input
La única linea contiene un entero n
 (3≤n≤101
; n
 es impar).

Output
Genera un cristal de tamaño n
.
*/