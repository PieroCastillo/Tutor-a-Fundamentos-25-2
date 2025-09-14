#include <iostream>
#include <string>

using namespace std;

using lista = int[6]; 

void recursive(lista arr, int idx)
{
    // condición de parada
    if (idx >= 6)
    {
        return;
    }

    // llamada recursiva
    cout << arr[idx] << endl;
    recursive(arr, idx+1);
}

// a_k+1 = a_k + 1


void iterative(lista arr)
{
    for(int i = 0; i < 6; i++)
    {
        
    }
}

int main() {

    lista valores = {1,2,3,4,5,6};
    recursive(valores, 0);

    return 0;
}