#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FIN;

    long long n,a,b,val;
    cin >> n;
    cin >> a;
    cin >> b;
    vector<long long> animales(n);
    vector<long long> animalesOrdenados(n);
    vector<pair<long long,long long>> presasDepredadores(n);

    for (int i=0; i<n; i++){
        cin >> val;
        animales[i]=val;
        animalesOrdenados[i]=val;
    }

    sort(animalesOrdenados.begin(), animalesOrdenados.end()); //sort no devuelve nada, primero debemos copiar el vector

    for(int i=0; i<n; i++){
        long long val = animales[i];
        long long aux;

        //para buscar todos los elementos dentro de un rango, buscar el primer elemento que vale hasta el primer elemento que no vale, así después no tengo que sumar 1 ni restar  1

        //cuento presas entre (val-b, val-a]
        auto itMenorPresa = upper_bound(animalesOrdenados.begin(), animalesOrdenados.end(), val-b); //x > val-b (no se incluye a val-b en el rango)
        auto itMayorPresa = upper_bound(animalesOrdenados.begin(), animalesOrdenados.end(), val-a); //y > val-a (me paso del rango máximo val-a y doy un paso para atrás para estar en el último valor >= val-a)
        aux = distance(itMenorPresa,itMayorPresa); //sumo 1 porque si ambos iteradores apuntan al mismo animal, me devolvería 0
        // cerr << aux << endl;
        presasDepredadores[i].first = max(0LL, aux); //si no hay menor presa entonces itMenorPresa apuntaría al final, resultando en un número negativo

        //cuento depredadores entre [val+a, val+b)
        auto itMenorDepredador = lower_bound(animalesOrdenados.begin(), animalesOrdenados.end(), val+a); //busco el primer elemento >= val+a
        auto itMayorDepredador = lower_bound(animalesOrdenados.begin(), animalesOrdenados.end(), val+b); //busco el primer elemento mayor a val+b y luego voy una posición atrás
        aux = distance(itMenorDepredador, itMayorDepredador);
        presasDepredadores[i].second = max(0LL, aux);
    }

    for (int i=0; i<n; i++){
        cout << presasDepredadores[i].second << " " << presasDepredadores[i].first << "\n";
    }

    return 0;
}

//failed attemp
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