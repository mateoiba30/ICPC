#include <bits/stdc++.h>
using namespace std;

/*
 12 10
 9 10
 10 11
 9 11
 0 1
 1 3
 3 5
 7 8
 1 4
 4 2
 5 2
 
 
 */
const int MAXN=1e5+5;
 
vector <bool> visto(MAXN,false);

void dfs(int v, vector <vector<int>> &g){
    visto[v]=true;
    for(auto u : g[v]) if(!visto[u]) dfs(u,g);
}

int main()
{
    int n, m; cin >> n >> m;
    vector <vector<int>> g(n);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cont=0;
    vector <int> vertices;
    for(int i=0; i<n; i++) if(!visto[i]){
        vertices.push_back(i);
        dfs(i,g);
        cont++;
    }
    cout << cont-1 << "\n";
    for(int i=1; i<cont; i++) cout << vertices[0]+1 << " " << vertices[i]+1 << "\n";
    return 0;
}