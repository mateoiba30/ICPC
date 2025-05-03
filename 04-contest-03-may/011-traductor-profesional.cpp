#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FIN;

    int n,m;
    string wordX, wordEnglish;
    cin >> n;
    cin >> m;
    map <string, string> mp;

    for (int i=0; i<n; i++){
        cin >> wordX;
        cin >> wordEnglish;
        mp[wordX] = wordEnglish;
    }

    for (int i=0; i<m; i++){
        cin >> wordX;
        cout << mp[wordX] << " ";
    }
    cout << "\n";

    return 0;
}

/*
B. Traductor profesional
time limit per test1 s.
memory limit per test1024 MB
Como todos saben, el Mono es un traductor profesional.

El mono tiene la traducción de n
 palabras de un idioma extraño, y una frase de m
 palabras. Traducir la frase mediante las reglas de traducción que tiene el Mono.

Input
La primera línea contiene dos enteros positivos n
 y m
 (1≤n,m≤100)
.

Las siguientes n
 lineas contienen dos strings si
 y ti
 cada una (1≤|si|,|ti|≤10)
. Que significa que la traducción de la palabra del idioma extraño si
 se traduce a ti
. Es garantizado que todas las si
 y las ti
 son palabras distintas.

La siguiente línea contiene m
 palabras p1,p2,…,pm
 (1≤|pi|≤10)
 separados por un espacio, formando la frase que debe ser traducida por el Mono. Es garantizado que cada palabra en la frase se encuentra en el manual de traducción del Mono.

Todas las palabras están compuestas por letras minúsculas del inglés.

Output
Imprimir una línea con m
 palabras q1,q2,…,qm
, separadas por un espacio, representando la traducción de la frase completa.
*/