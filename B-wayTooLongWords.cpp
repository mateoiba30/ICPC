#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i=0; i++; i<n){
        cin >> palabra;
        int tamanio = palabra.size();
        if (tamanio > 10){
            string resultado = "";
            resultado = palabra[0] + to_string(tamanio) + palabra[tamanio-1];
            cout << resultado << "\n";
        }
        else{
            cout << palabra << "\n";
        }   
    }

    return 0;
}

/*

recibo n palabras separadas por un salto de línea

por n veces:
si tiene más de 10 caracteres
    contar caracteres
    mostrar 1er letra
    mostrar cant chars
    mostrar ult letra
*/