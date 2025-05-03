#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FIN;

    int n,a,b;
    cin >> n;
    cin >> a;
    cin >> b;
    vector<int> presas(n);

    for (int i=0; i<n; i++){
        presas[i]=0;
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;

// int main(){
//     FIN;
    
//     map<int,pair<int,int>> mp; //presas, depredadores
//     int n,a,b,val;
//     cin >> n;
//     cin >> a;
//     cin >> b;

//     for (int i=0; i<n; i++){
//         cin >> val;
//         mp[val].first = 0;
//         mp[val].second = 0;

//         auto it = mp.lower_bound(val-b);
//         if(it != mp.end() && it->first < b){
//             mp[val].first ++;
//             mp[it->first].second++;
//         }
//     }

//     for(int i=0; i<n; i++)
//         cout << mp[i].first << " " << mp[i].second << "\n";

//     return 0;
// }

/*
A. Depredador o presa
time limit per test2 s.
memory limit per test256 MB
El Rodo ha estado investigando recientemente las relaciones de depredación en un ecosistema. Él descubrió que: - Cada animal se le puede asignar un factor de depredación de pi
, el cúal es un entero positivo.

También aprendió que los animales van a depredar otros animales según su factor relativo de depredación. Un animal i
 va a depredar a otro animal j
 si la diferencia entre pi
 y pj
 es al menos a
. Sin embargo, si la diferencia es b
 o más, el animal i
 considera que el animal j
 es muy débil y no se lo va a comer.

Existen n
 animales en el ecosistema. Para cada animal, encontrar la cantidad de depredadores y presas que tiene.

Input
La primera línea contiene 3
 enteros n,a,b
. (1≤n≤2⋅105)
 (1≤a<b≤109)

La segunda línea contiene n
 enteros p1,p2,…,pn
 (1≤pi≤109)
 representando el factor de depredador de cada animal.

Output
Imprimir n
 lineas. En la i
-ésima línea imprimir 2
 enteros, correspondientes al número de depredadores y al números de presas que el animal i
 tiene.
*/