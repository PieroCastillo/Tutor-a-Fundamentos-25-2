#include <iostream> //input output stream
#include <cmath>

using namespace std;

void printLista(int* arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //swap
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int aparece(int* lista, int n)
{
    /*
    4 5 1 2 1 4 2 :
    1 1 2 2 4 4 5 : ordenado
    ctd = 0
    last = listaOrdenada[0]
    for num in listaOrdenada[1:n-1]:
        num == last
            ctd++
            last = num
            continua

        num != last y ctd == 1
            return last

        ctd = 0
    */
    bubbleSort(lista, n);
    printLista(lista, n);
    int  ctd = 1;
    int last = lista[0];

    for (int i = 1; i < n; i++)
    {
        auto val = lista[i];

        // imprimir estado
        cout << "lista[i] : " << val << " last : " << last << "  contador : " << ctd << endl;

        if ((val != last) & (ctd == 1))
        {
            return last;
        }

        if (val == last)
        {
            ctd++;
            cout << "continue " << endl;
            continue;
        }

        // caso implicito: val != last y ctd != 1 ; 3 4 5
        last = val;
        ctd = 1;
    }
    return -1;
}

int main() {
    int n = 9;
    int* lista = new int[n] { 4, 5, 1, 2, 1, 4, 2, 6, 6};
    printLista(lista, n);
    cout << "resultado: " << aparece(lista, n) << endl;
    return 0;
}