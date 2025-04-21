#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int> &a) {
    if (a.size() <= 1)
        return;

    int n = a.size();
    vector<int> l, r;

    for (int i = 0; i < n / 2; i++)
        l.push_back(a[i]);
    for (int i = n / 2; i < n; i++)
        r.push_back(a[i]);

    mergesort(l);
    mergesort(r);

    a.clear();
    int posl = 0, posr = 0;

    while (posl < l.size() && posr < r.size()) {
        if (l[posl] <= r[posr]) {
            a.push_back(l[posl]);
            posl++;
        } else {
            a.push_back(r[posr]);
            posr++;
        }
    }

    // Agregar los elementos restantes
    while (posl < l.size()) {
        a.push_back(l[posl]);
        posl++;
    }
    while (posr < r.size()) {
        a.push_back(r[posr]);
        posr++;
    }
}

int main() {
    vector<int> a = {5, 2, 9, 1, 3, 6};

    mergesort(a);

    for (int x : a)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
