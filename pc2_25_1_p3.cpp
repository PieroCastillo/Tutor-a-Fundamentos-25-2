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

void printLista(int* arr, int i, int j)
{
    for (int k = i; k <= j; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

bool impar(int k)
{
    return (k % 2) == 1;
}

/*
2,3,2,2,1,1,3,3,7,5,1,2,3
  |
*/

int* encontrarSublista(int* lista, int n)
{
    int* offsets = new int[2];
    offsets[0] = 0;
    offsets[1] = 0;
    int tempOffsets[2] = { 0,0 };
    int tempDist = 0;

    for (int i = 0; i < n; i++)
    {
        if (!impar(lista[i]))
            continue;

        tempOffsets[0] = i;
        for (int j = i; j < n; j++)
        {
            if (!impar(lista[j]))
                break;

            // guardar offsets
            tempOffsets[1] = j;
        }

        int tDist = tempOffsets[1] - tempOffsets[0];
        int dist = offsets[1] - offsets[0];
        if (tDist > dist)
        {
            offsets[0] = tempOffsets[0];
            offsets[1] = tempOffsets[1];
            cout << "salvar offsets" << endl;
        }
        cout << " i: " << i << "  j: " << tempOffsets[1]  << endl;
     }

    return offsets;
}

int main() {
    int lista[15] = { 2,3,2,2,1,1,3,3,7,5,1, 3, 5,2,3 };
    int n = 15;

    printLista(lista, n);
    auto offsets = encontrarSublista(lista, n);
    auto i = offsets[0];
    auto j = offsets[1];
    cout << i << "  " << j << endl;
    printLista(lista, i, j);

    return 0;
}