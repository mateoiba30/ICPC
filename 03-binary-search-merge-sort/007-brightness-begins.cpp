#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    FIN; //fast input

    //aplciar binari search? desconozco la cota superior para este problema

    return 0;
}

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