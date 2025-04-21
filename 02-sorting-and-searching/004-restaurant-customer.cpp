/*map cuesta más que un vector, porque cada vez que ingreso un dato me lo ordena. En este caso es mejor usar un vector<pair<int,int>> y luego ordenarlo con sort 1 sola vez*/
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, l;
    map<int,int> mp;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> l;
        // cout << "a:" << a << " l:" << l <<"\n";
        mp[a]++;
        mp[l]--;
    }

    int mx=-1;
    int sum=0;
    int value =0;
    auto it = mp.begin();
    while(it != mp.end()){
        value = (*it).second;
        sum+=value;
        mx=max(mx,sum);
        it++;
    }

    cout << mx << "\n";
    return 0;
}
/*
You are given the arrival and leaving times of n
 customers in a restaurant.

What was the maximum number of customers?

Input
The first input line has an integer n
: the number of customers.

After this, there are n
 lines that describe the customers. Each line has two integers a
 and b
: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Constraints:

1≤n≤2⋅105
1≤a≤b≤109
Output
Print one integer: the maximum number of customers.
*/


//1er intento
// si llega un intervalo de 1 a 10^9 es mucho tiempo y tengo que asignar varios pair<int, int> que se pasan del límite
//además esta solución tiene un error en algún lado

// #include <bits/stdc++.h>

// using namespace std;

// #define all(x) x.begin(),x.end()

// int main(){
//     int n, a, l;
//     map<int, int> mp;
//     cin >> n;
//     for (int i=n; i<n; i++){
//         // int a, l; // esto es peor en tiempo, pero mejor en memoria
//         cin >> a, l;
//         for(int j=a; i++; i<l){
//             mp[i]++;
//         }
//     }
//     //el map ordena por key, para obtener el mayor valor lo tengo que recorrer todo. Recorrer con un iterador
//     auto it = mp.begin();
//     int ans = -1;
//     while(it != mp.end()){
//         pair <int,int> value = *it;
//         cout << value;
//         ans = max(ans, value.second);
//         it++;
//     }

//     cout << ans << "\n"; //el max_element devuelve un iterador
//     return 0;
// }

/*
otra solución:

opción con map:
- cada dato se ingresa ordenado  en orden logn
- al final no debemos ordenar nada

opción con vector
- cada dato se ingresa sin un orden (O(1))
- al final debemos ordenar con merge sort (O(nlogn))

ambas opciones tardan aprox lo mismo, son opciones equivalentes para este problema. Lo malo de usar map es que desp tengo que manipular iteradores (casi nada accede más rápido a un dato que un vector, por eso el usar iteradores es más lento)

#include <bits/stdc++.h>
using namespace std;
 
  int main() {
      int n;
      cin>> n;
      
      vector<pair<int,int>>events;
      
      for(int i = 0; i < n; ++i){
      int a, b;
      cin>> a >> b;
      events.push_back({a, 1});
      events.push_back({b, -1});
      }
      sort(events.begin(), events.end());
      
      int current = 0;
      int max_costumers=0;
      
      for(auto[time, type]: events){
          current += type;
          max_costumers= max(max_costumers, current);
          
      }
      cout<< max_costumers << "\n";
      return 0;
  }
*/