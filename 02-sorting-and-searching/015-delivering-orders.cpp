#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = (ll)a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v) forn(_,SZ(v)) cerr << v[_] << " "
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
int main() {
  FIN; 
  
  ll k,n; cin>>k;
  vi ing(k); forn(i,k) cin>>ing[i];
  cin>>n;
  vector<vi> orders(n,vi(k,0));
  vi cycle(k,0);
  forn(i,n){
    ll ingred;
    forn(j,k){
      cin>>ingred;
      orders[i][j]=ingred;
      cycle[j]+=ingred;
    }
  }
  ll ciclos=1e13;
  forn(i,k) if(cycle[i]>0) ciclos=min(ciclos,ing[i]/cycle[i]);
  forn(i,k) ing[i]-=(cycle[i]*ciclos);
  bool sigo=true;
  ll pos=0;
  // DBGV(ing); cerr<<endl;
  while(sigo and pos<n){
    ll cont=0;
    forn(i,k){
      if(orders[pos][i]<=ing[i]){
        cont++;
        ing[i]-=orders[pos][i];
      }
    }
    if(cont<k) sigo=false;
    pos++;
  }
  cout<<ciclos+1<<" "<<pos<<"\n";
  return 0; 
}

// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main() {
//     // FIN;
    
//     int k, n;
//     cin >> k;
//     vector<long long> stock(k);  // usar long long p
//     for (int i = 0; i < k; i++) {
//         cin >> stock[i];
//     }

//     cin >> n;
//     vector<vector<long long>> pedidos(n, vector<long long>(k));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < k; j++) {
//             cin >> pedidos[i][j];
//         }
//     }

//     int dia = 1;
//     while (true) {
//         for (int i = 0; i < n; i++) {
//             bool puede = true;
//             for (int j = 0; j < k; j++) {
//                 if (stock[j] < pedidos[i][j]) {
//                     cout << dia << " " << i + 1 << "\n";
//                     return 0;
//                 }
//             }
//             for (int j = 0; j < k; j++) {
//                 stock[j] -= pedidos[i][j];
//             }
//         }
//         dia++;
//     }

//     return 0;
// }


// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main(){
//     // FIN;
    
//     int n, k, dia=1, pedidoActual;
//     bool fin=false;
//     cin >> k;
//     vector<int> stock(k);
//     vector<int> sumaIngredientes(k, 0);

//     for(int i=0; i<k; i++){
//         sumaIngredientes[i] =0;
//     }

//     for (int i=0; i<k; i++){
//         cin >> stock[i];
//     }

//     cin >> n;
//     vector<vector<int>> pedidos(n, vector<int>(k));

//     for(int i=0; i<n; i++){
//         for(int j=0; j<k; j++){
//             cin >> pedidos[i][j];
//             sumaIngredientes[j]+=pedidos[i][j];
//         }
//     }

//     // cout << "---------suma------------\n";

//     // for(int i=0; i<k; i++){
//     //     cout << sumaIngredientes[i] << " ";
//     // }

//     // cout << "\n---------dias-------------\n";


//     int minPedido = n;
//     long long minDias = LONG_MAX, diasActual;
//     for(int i=0; i<k; i++){ ///para cada ingrediente
//         fin = false;
//         if (sumaIngredientes[i] != 0){
//             diasActual = stock[i] / sumaIngredientes[i] + 1; //me fijo en cuantos días se acaba
//             // cout << diasActual << " ";
//             // cout << "minDias " << minDias <<"\n";
//             // cout << "diasActual " << diasActual <<"\n";
//             // cout << "columna " << i << "\n";
//             if(diasActual <= minDias){ //si es de los que se acaban rápido, entonces me fijo cual es el último pedido que se llega a hacer
//                 minDias = diasActual;
//                 // cout << "entro al if en la columna " << i << "\n";
//                 while (not fin){
//                     for (int j=0; j<n; j++){
//                         // cout << "columna " << i << ", fila " << j << "= " << pedidos[j][i] << "\n";    
                        
//                         stock[i]-=pedidos[j][i]; //a un ingrediente fijo le voy restando los diferentes N pedidos
//                         if(stock[i]<0){
//                             minPedido = min(minPedido, j+1);
//                             fin=true;
//                             break;
//                         }
//                     }   
//                 }
                
//             }
//         }
//     }
//     // cout << "\n";

//     cout << minDias << " " << minPedido;

//     return 0;
// }

// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;

// int main(){
//     FIN;

//     int n, k;
//     cin >> k;
//     vector<int> stock(k), pedidosDiarios(k);
//     vector<int> mejorPedidoPorIngrediente(k);
//     vector<long long> mejorValPorIngrediente(k, LLONG_MAX);

//     for (int i = 0; i < k; ++i) cin >> stock[i];
//     cin >> n;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < k; ++j) {
//             int pedidoActual;
//             cin >> pedidoActual;
//             pedidosDiarios[j] += pedidoActual;

//             if (pedidosDiarios[j] > 0) {
//                 long long val = stock[j] / pedidosDiarios[j] + 1;
//                 if (val < mejorValPorIngrediente[j]) {
//                     mejorValPorIngrediente[j] = val;
//                     mejorPedidoPorIngrediente[j] = i + 1;
//                 }
//             }
//         }
//     }

//     long long diaMin = LLONG_MAX;
//     int pedidoMin = n;

//     for (int i = 0; i < k; ++i) {
//         if (mejorValPorIngrediente[i] < diaMin) {
//             diaMin = mejorValPorIngrediente[i];
//             pedidoMin = mejorPedidoPorIngrediente[i];
//         } else if (mejorValPorIngrediente[i] == diaMin) {
//             pedidoMin = min(pedidoMin, mejorPedidoPorIngrediente[i]);
//         }
//     }

//     cout << diaMin << " " << pedidoMin << "\n";
//     return 0;
// }


// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main(){
//     FIN;
    
//     int n, k, pedidoActual, mejorPedido;
//     long long diaMin=LONG_MAX, val, minVal=LONG_MAX;
//     bool fin=false;
//     cin >> k;
//     vector<int> stock(k);
//     vector<int> pedidosDiarios(k);
//     vector<pair<int,long long>> valoresAux(k);

//     for (int i=0; i<k; i++){
//         valoresAux[i].second = LONG_MAX;
//     }
//     for (int i=0; i<k; i++){
//         cin >> stock[i];
//     }
//     cin >> n;

//     for (int i=0; i<n; i++){//para cada uno de los N pedidos
        
//         for(int j=0; j<k; j++){//recibo la cantidad que necesita de cada ingrediente
//             // cout << "elemento " << k << "\n";
//             cin >> pedidoActual;
//             pedidosDiarios[j] += pedidoActual;
            
//             if(pedidosDiarios[j] != 0){
//                 val = stock[j] / pedidosDiarios[j] + 1;

//                 if(val < valoresAux[j].second){
//                     valoresAux[j].first = i+1;
//                     valoresAux[j].second = val;
//                 }
//             }
//         }
//     }
//     for (int i=0; i<k; i++){
//         if(pedidosDiarios[i] <= diaMin){
//             diaMin = valoresAux[i].second;
//             minVal = min(minVal, valoresAux[i].second);
//         }
//     }
//     cout << diaMin << " " << minVal << "\n";

//     return 0;
// }
 

// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main(){
//     FIN;
    
//     int n, k, pedidoActual, mejorPedido;
//     long long diaMin=LONG_MAX, val;
//     bool fin=false;
//     cin >> k;
//     vector<int> stock(k);
//     vector<int> pedidosDiarios(k);
//     vector<pair<int,long long>> valoresAux(k);

//     for (int i=0; i<k; i++){
//         valoresAux[i].second = LONG_MAX;
//     }
//     // cout << "aux \n";
//     for (int i=0; i<k; i++){
//         cin >> stock[i];
//     }
//     // cout << "termino de leer el stock \n";

//     cin >> n;
//     int pedidoMin=n;

//     for (int i=0; i<n; i++){//para cada uno de los N pedidos
        
//         for(int j=0; j<k; j++){//recibo la cantidad que necesita de cada ingrediente
//             // cout << "elemento " << k << "\n";
//             cin >> pedidoActual;
//             pedidosDiarios[j] += pedidoActual;
            
//             if(pedidosDiarios[j] != 0)
//                 val = stock[j] / pedidosDiarios[j] + 1;

//             if(val < valoresAux[j].second){
//                 valoresAux[j].first = i+1;
//                 valoresAux[j].second = val;
//             }
//         }
//     }
//     // cout << "\n";
//     for (int i=0; i<k; i++){
//         // cout << valoresAux[i].second << " ";
//         // cout << "diaMin=" << diaMin;
//         // cout << ", val=" << valoresAux[n-1].second;

//         if(valoresAux[i].second <= diaMin){
//             diaMin = valoresAux[i].second;
//             auto menor = *min_element(valoresAux.begin(), valoresAux.end());
//             mejorPedido = menor.first;
//             pedidoMin = min(pedidoMin, mejorPedido);
//         }
//         // cout << "diaMin actualizado=" << diaMin << "\n";
//     }
//     // cout << "\n";

//     cout << diaMin << " " << pedidoMin << "\n";

//     return 0;
// }
 
// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main(){
//     FIN;
    
//     int n, k, dia=1, pedidoActual;
//     bool fin=false;
//     cin >> k;
//     vector<int> stock(k);

//     for (int i=0; i<k; i++){
//         cin >> stock[i];
//     }

//     cin >> n;
//     while (not fin) {
//         for (int i=0; i<n; i++){//para cada uno de los N pedidos
//             for(int j=0; j<k; j++){//recibo la cantidad que necesita de cada ingrediente

//                 cin >> pedidoActual;
//                 stock[j]-=pedidoActual;
//                 if(stock[j]<0){
//                     fin=true;
//                     cout << dia << i+1 << "\n";
//                     break;
//                 }
//             }
//             if (fin==true){
//                 break;
//             }
//         }
//         dia++;
//     }

//     return 0;
// }
