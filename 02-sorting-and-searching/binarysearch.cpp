#include <bits/stdc++.h>

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

using namespace std;

bool binarySearch(vector <int> &v, int x) {
// 0 a n-1
int n = v.size();
int l = -1, r = n;
while(r-l > 1) {
int med = (l+r)/2;
if(v[med] >= x) r = med;
else l = med;
}
if(r == n) return false;  
if(v[r] == x) return true;
else return false;
}

int main() {
FIN;

int n, q;
cin >> n >> q;
vector <int> v(n);
for(int i = 0; i < n; i++) cin >> v[i];
for(int i = 0; i < q; i++) {
int x;
cin >> x;
bool ans = binarySearch(v,x);
if(ans == true) cout << "YES\n";
else cout << "NO\n";
}

return 0;
}