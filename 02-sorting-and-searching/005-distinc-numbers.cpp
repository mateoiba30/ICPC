#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, val;
    map<int,int> mp;
    cin >> n;
    
    for (int i=0; i<n; i++){
        cin >> val;
        mp[val]=1;
    }
    cout << mp.size() << "\n";
    return 0;
}

/*
time limit per test2 seconds
memory limit per test256 megabytes
You are given a list of n
 integers, and your task is to calculate the number of distinct values in the list.

Input
The first input line has an integer n
: the number of values.

The second line has n
 integers x1,x2,…,xn
.

Constraints:

1≤n≤2⋅105
1≤xi≤109
Output
Print one integer: the number of distinct values
*/