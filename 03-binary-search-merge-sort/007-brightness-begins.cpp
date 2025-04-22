#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    FIN; //fast input
    //aplciar binari search? desconozco la cota superior para este problema
    int t;
    long long k;
    cin >> t;

    for (int m=0; m<t; m++){
        cin >> k;
        
        long long l = 0, r = 2e18, n, result;
        while(r-l>1){
            n = (l+r)/2;

            result = n - (long long)sqrtl(n); //result is the "K" generated
            if(result>=k)
                r = n;
            else
                l = n;
        }

        //if(r == n) //no nececsario chequear porque la solución seguro existe

        cout << r<< "\n";
    }

    return 0;
}

/*
cada bombilla cambia de estado cuantos divisores tenga. Si tiene divisores impar entonces queda apagada, si tiene un número par queda prendida. Solo los cuadrados perfectos tienen un nro impar de divisores (1^2, 2^2, 3^2, etc); entonces la cantidad de bombillas prendidas (k) es de N - cant de cuadrados perfectos, siendo N la cantidad de bombillas a usar. Para saber cuantos cuadrados perfectos hay de 1 a N debemos tomar la parte entera (truncar) de la raíz cuadrada de N: de 1 a 10 hay (10)^0.5 ~= 3.16 ~= 3 cuadrados perfectos (1, 4 y 9).
*/

/*
A. Brightness Begins
time limit per test1 second
memory limit per test256 megabytes
Imagine you have n
 light bulbs numbered 1,2,…,n
. Initially, all bulbs are on. To flip the state of a bulb means to turn it off if it used to be on, and to turn it on otherwise.

Next, you do the following:

for each i=1,2,…,n
, flip the state of all bulbs j
 such that j
 is divisible by i†
.
After performing all operations, there will be several bulbs that are still on. Your goal is to make this number exactly k
.

Find the smallest suitable n
 such that after performing the operations there will be exactly k
 bulbs on. We can show that an answer always exists.

†
 An integer x
 is divisible by y
 if there exists an integer z
 such that x=y⋅z
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line of each test case contains a single integer k
 (1≤k≤1018
).

Output
For each test case, output n
 — the minimum number of bulbs.
*/