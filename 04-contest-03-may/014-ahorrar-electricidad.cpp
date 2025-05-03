#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void resolver(){
    int n, m, rta;
    cin >> n;
    cin >> m;

    if(n % 2 != 0){
        rta = ((n-1)/2) * m +m/2;
        if(m % 2 !=0)
            rta ++;
    }
    else
        rta = (n/2)*m;

    cout << rta << "\n";
}

int main() {
    FIN;

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        resolver();
    }

    return 0;
}

/*
C. Ahorremos electricidad que salta la térmica
time limit per test2 s.
memory limit per test256 MB
Debido a la pandemia de coronavirus, las autoridades municipales obligaron a los ciudadanos a mantener la distancia social. El Intendente, Rodo, quiere iluminar el parque San Martin para que la gente pueda verse incluso de noche y así mantener la distancia social.

El parque es una mesa rectangular con n
 filas y m
 Columnas, donde las celdas de la tabla son cuadrados y los límites entre celdas son calles. Los bordes externos también son calles. Cada calle tiene una longitud 1
. Por ejemplo, parque con n=m=2
 tiene 12
 calles.

Se te asignó desarrollar un plan para iluminar el parque. Puedes colocar faroles en medio de las calles. La farola ilumina dos casillas cercanas (o solo una si está en el límite del parque).

El tamaño del parque es: n=4
, m=5
. Las plazas iluminadas estan marcadas en amarillo. Tenga en cuenta que todas las calles tienen una longitud 1
. Se colocan faroles en medio de las calles. En la imagen, no todas las plazas están iluminadas.
Rodo quiere gastar la menor cantidad posible en iluminación, pero también quiere que la gente de todo el parque mantenga la distancia social. Por eso, te pide que encuentres el número mínimo de faroles necesarios para iluminar todas las plazas.

Input
La primera linea contiene un solo entero t
 (1≤t≤104
) — El numero de casos de prueba. Entonces a continuacion se presentan los t
 casos de prueba siguientes.

Cada caso de prueba es una linea que contiene dos enteros n
, m
 (1≤n,m≤104
) — con los tamaños de los parques.

Output
Imprime t
 respuestas para los casos de prueba. Cada respuesta debe ser un entero: el número mínimo de faroles necesarios para iluminar todos los cuadrados.
*/