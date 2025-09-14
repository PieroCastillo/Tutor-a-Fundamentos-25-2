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

int binarySearch(int* arr, int length, int key)
{
    int a = 0;
    int b = length-1;

    int c = (a+b)/2;

    auto val = arr[c];

    if(key == val)
        return c;
    // else if ( key > val)
    //     return binarySearch(arr, b-)

    return -1;
}

int main() {
    int n = 2;
    int length = 5;
    int* distancias = new int[length] { 7, 2, 5, 10, 8};
    printLista(distancias, length);

    /*
    optimizar tiempos
    -> cada tiempo de cada sublista sea cercano a un valor
    valor = distancia promedio
    distancia promedio = suma de valores de array / #elementos
    
    int start = 0;
    int end = X;
    int result = 0;
    while(start <= end){
        int mid = (start + end)/2;
        for(int i = 0; i < n; i++){
        if sum of current segment > mid
            split

        }
        if total segment > N
        start = mid + 1;
        else 
        update result;
        end = mid - 1;
    }
    
    */


    delete[] distancias;
    return 0;
}