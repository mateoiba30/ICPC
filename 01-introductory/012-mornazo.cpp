#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FIN;

    string frase;
    cin >> frase;
    int len = frase.size();
    // map<string,int> mp;
    // mp["."]=0;
    // mp["-."]=1;
    // mp["--"]=2;

    for (int i=0; i<len; i++){
        if(frase[i]=='.'){
            cout << "0";
        }
        else{
            i++;
            if(i<len){
                if(frase[i]=='.')
                    cout << "1";
                else 
                    cout << "2";
            }
        }
    }
    cout << "\n";

    return 0;
}

/*
G. MORNAZO
time limit per test2 s.
memory limit per test256 MB
La notación numérica ternaria es muy popular en la casa del Mono. Para telegrafiar el número ternario se utiliza el alfabeto MORNAZO basado en el Morse. El digito 0 es transmitido como «.», 1 es «-.» y 2 es «--». Debe decodificar el código MORNAZO, es decir, averiguar el número ternario según su representación en el alfabeto MORNAZO.

Input
La primera línea contiene un número en código MORNAZO. La longitud de la cadena oscila entre 1 y 200 caracteres. Se garantiza que la cadena dada es un código MORNAZO válido de algún número ternario (este número puede tener ceros a la izquierda).

Output
Genera el número ternario decodificado. Puede tener ceros a la izquierda.
*/