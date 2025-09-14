#include <iostream> //input output stream
#include <cmath>

using namespace std;

/*
x_k+1 = numerito + signo*(1/x_k) 
*/

double calcularValor(int pasos, int idx = 0)
{
    if(idx >= pasos)
        return pasos;

    /*             signo:
    0 -> par    |  +1
    1 -> impar  |  -1
    2 -> par    |  +1
    3 -> impar  |  -1
    */
    bool esPar = !(idx % 2);

    /*
    en memoria: 0101010101111100001 = 1*2^0 + 0*2^1 ....
    double: signo: 0 exponente: 01001010100 valor: 1011101
    IEEE-754 : estandar punto flotante
    cpu : procesar
    instrucciones:
        sumarDouble var2, var1, var1
        sumarEntero var2, a, b
    */

    auto var = (double)max(1, idx); 
    auto numerador = max(1.0, ceil(idx/2) );
    
    if(esPar)
        var += (numerador/calcularValor(pasos, idx+1));
    else
        var -= (numerador/calcularValor(pasos, idx+1));

    cout << "idx: "<< idx <<  " valor en func : " << var << endl; 

    return var;
}

int main() {

    cout << "valor : "<< calcularValor(7) << endl;
    return 0;
}