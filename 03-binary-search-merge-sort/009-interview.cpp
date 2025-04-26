#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// long long query(int l, int r){ //para preguntarle al juez con su formato. Esto es por organización
//     cout << "? " << (r-l+1);
//     for(int i = l; i<=r; i++) cout << " " << i;
//     cout << endl; //improtante hacer endl y no "\n"
//     long long suma = 0;
//     cin>>suma; //el x que me manda el juez
//     return suma;
// }
long long query (int l,int r) {
	cout << "? " << r;
	for (int i = 0; i < r; i++) cout << " " << i+1;
	cout << endl;
	ll suma;
	cin >> suma;
	return suma;
}
 

void solve(){
    int n;
    cin >> n; //number of piles
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];//receive the number of rocks of each pile
    int l = -1, r = n;
    while(r-l > 1){ //binary search
        int med = (r+l)/2;
        long long rta = query(l, med+1);
        long long suma = 0;
        for(int i=0; i <= med; i++){ //calculamos la suma de pesos si no estaría la piedra especial
            suma += a[i];
        }
        if(rta > suma){
            r = med;
        } else {
            l = med;
        }
    }
    cout << "! " << r+1 << endl;
}

int main(){
    FIN;
    
    int t; 
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

/*
G. Interview
time limit per test2 seconds
memory limit per test256 megabytes
This is an interactive problem. If you are unsure how interactive problems work, then it is recommended to read the guide for participants.

Before the last stage of the exam, the director conducted an interview. He gave Gon n
 piles of stones, the i
-th pile having ai
 stones.

Each stone is identical and weighs 1
 grams, except for one special stone that is part of an unknown pile and weighs 2
 grams.

Gon can only ask the director questions of one kind: he can choose k
 piles, and the director will tell him the total weight of the piles chosen. More formally, Gon can choose an integer k
 (1≤k≤n
) and k
 unique piles p1,p2,…,pk
 (1≤pi≤n
), and the director will return the total weight mp1+mp2+⋯+mpk
, where mi
 denotes the weight of pile i
.

Gon is tasked with finding the pile that contains the special stone. However, the director is busy. Help Gon find this pile in at most 30
 queries.

Input
The input data contains several test cases. The first line contains one integer t
 (1≤t≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of piles.

The second line of each test case contains n
 integers ai
 (1≤ai≤104
) — the number of stones in each pile.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

After reading the input for each test case, proceed with the interaction as follows.

Interaction
You can perform the operation at most 30
 times to guess the pile.

To make a guess, print a line with the following format:

? k p1 p2 p3 ... pk−1 pk
 (1≤k≤n
; 1≤pi≤n
; all pi
 are distinct) — the indices of the piles.
After each operation, you should read a line containing a single integer x
 — the sum of weights of the chosen piles. (Formally, x=mp1+mp2+⋯+mpk
.)
When you know the index of the pile with the special stone, print one line in the following format: ! m
 (1≤m≤n
).

After that, move on to the next test case, or terminate the program if there are no more test cases remaining.

If your program performs more than 30
 operations for one test case or makes an invalid query, you may receive a Wrong Answer verdict.

After you print a query or the answer, please remember to output the end of the line and flush the output. Otherwise, you may get Idleness limit exceeded or some other verdict. To do this, use the following:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
It is additionally recommended to read the interactive problems guide for participants.

Hacks

To make a hack, use the following format.

The first line should contain a single integer t
 (1≤t≤1000
) — the number of test cases.

The first line of each test case should contain two integers n,m
 (1≤n≤2⋅105
) – the number of piles and the pile with the special stone.

The second line of each test case should contain n
 integers ai
 (1≤ai≤104
) — the number of stones in each pile.

Note that the interactor is not adaptive, meaning that the answer is known before the participant asks the queries and doesn't depend on the queries asked by the participant.
*/