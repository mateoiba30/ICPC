#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x, val;
    cin >> n;
    cin >> x;
    map<int,int> mp;

    for(int i=0; i<n; i++){
        cin >> val;
        if(mp.count(x-val)){
            cout << i+1 << " " << mp[x-val] << "\n";
            return 0;
        }
        mp[val] = i+1; //esto lo debemos hacer después para que no se admita responder con el mismo nro 2 veces<
    }
    cout << -1 << "\n";
    return 0;
}

//NOS PASAMOS DE MEMORIA: 2.10^5 * 4 BYTES ES EL TAMAÑO DEL ARRAY, LO CUAL SON APROX 800 MB
// #include <bits/stdc++.h>

// using namespace std;

// int main(){

//     int n, x;
//     cin >> n;
//     cin >> x;
//     //cout << "X: " << x << "\n";
//     vector<int> v(n);

//     for(int i=0; i<n; i++){
//         cin >> v[i];
//         for(int j=0; j<i; j++){
//             cout << v[i] << " + " << v[j] << " = " << v[i]+v[j] << "\n";
//             if(v[i]+v[j]==x){
//                 cout << i+1 << " " << j+1 << "\n";
//                 return 0;
//             }
//         }
//     }
//     cout << -1;
//     return 0;
// }

/*
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array of n
 integers, and your task is to find two values (at distinct positions) whose sum is x
.

Input
The first input line has two integers n
 and x
: the array size and the target sum.

The second line has n integers a1,a2,…,an
: the array values.

Constraints:

2≤n≤2⋅105
1≤x,ai≤109
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print −1
.
*/