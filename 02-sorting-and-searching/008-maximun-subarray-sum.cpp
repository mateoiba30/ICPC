#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    FIN;
    int n;
    long long prefixSum = 0, x;
    cin >> n;
    vector<long long> prefixSums(n);

    for (int i=0; i<n; i++){
        cin >> x;
        prefixSum += x;
        prefixSums[i] = prefixSum;
    }

    long long max = prefixSums[0];
    long long minPrefix = 0;

    for (int i=0; i<n; i++){
        long long sum = prefixSums[i] - minPrefix;
        if (sum > max)
            max = sum;
        if(prefixSums[i]<minPrefix)
            minPrefix=prefixSums[i];
        //si minPrefix sería un set entonces podría hacer algo como setMinPrefix.insert(prefixSums[i])
    }

    cout << max << "\n";

    return 0;
}

//esta solución es de O(n^2), por eso no nos sirve

// #include <bits/stdc++.h>
// #define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// int main(){
//     FIN;
//     int n;
//     cin >> n;
//     vector<int> v(n);

//     for (int i=0; i<n; i++){
//         cin >> v[i];
//     }

//     int start, end;
//     long long maxSum=1e11;
//     maxSum *= -1;

//     for (int i=1; i<=n; i++){ //tamaño del subarray
//         start = 0;
//         end = i;//no se incluye el end
//         long long actualSum = 0;

//         for(int j=0; j<end; j++)
//             actualSum+=v[j];    

//         while(end<n){//mientras no me pase del array
//             //cout << "tamaño del subarray: " << i << " subarray [ "<<start<<", "<<end<<" ] = "<<actualSum<<"\n";
//             if(actualSum>maxSum)
//                 maxSum=actualSum;
//             actualSum += v[end]; //ahora si incluimos el end y desp actualizamos el end
//             actualSum -= v[start];
//             start++;
//             end++;
//         }  
//     }

//     cout << maxSum << "\n";

//     return 0;
// }

/*
E. Maximum Subarray Sum
time limit per test2 s
memory limit per test256 megabytes
Given an array of n
 integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input
The first input line has an integer n: the size of the array.

The second line has n
 integers x1,x2,…,xn
: the array values.

Constraints:

1≤n≤2⋅105
−109≤xi≤109
Output
Print one integer: the maximum subarray sum.
*/