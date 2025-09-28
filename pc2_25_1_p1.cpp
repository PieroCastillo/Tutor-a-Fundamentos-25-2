#include <iostream> //input output stream
#include <cmath>

using namespace std;

/*
 1 2 3 4 5 6
 | 1 | -> | 2 | -> | 3 | -> | 4 | -> | 5 | -> | 6 |
   |
   n = 6
   k = 1 ->  k = 1
   k = 2 -> k = 2
   k = 6 -> k = 6
   k = 7 -> k = 1                                          
   
   
   cuda_malloc, shared memory, local memory, thread
*/

struct Node {
    int value;
    Node* next;
};

// k pasos derecha, si k > 0
// k pasos izquierda, si k < 0 
void printLista(Node* arr, int n, int k)
{
    Node* next = arr;


    // k> 0, desplaza a la izquierda
    if (k > 0)
    {
        k = (k) % n;
        cout << k << endl;
        for (int i = 0; i < k; i++)
        {
            next = next->next;
        }
    }
    else if (k < 0)
    {
        k = (n+k) % n;
        cout << k << endl;
        for (int i = 0; i < k; i++)
        {
            next = next->next;
        }
    }


    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << next->value << " ";
        next = next->next;
    }
    cout << "]" << endl;
}

Node* crearList(int* numbers, int n)
{
    Node* last = nullptr;
    Node* head = nullptr;
    for(int i = 0; i < n; i++)
    {
        Node* node = new Node;
        node->value = numbers[i];
        node->next = nullptr;

        if(i == 0)
        {
            head = node;
        }

        if(last)
        {
            last->next = node;
        }
        last = node;
    }
    last->next = head;
    
    return head;
}

void eliminarList(Node* arr, int n)
{
    Node* temp = arr;
    for(int i = 0; i < n; i++)
    {
        auto c = temp->next;
        delete temp;
        temp = c;
    }
}

int main() {

    int k = 0;
    cin >> k;

    Node n6 = { 7, nullptr };
    Node n5 = { 0, &n6 };
    Node n4 = { 2, &n5 };
    Node n3 = { 3, &n4 };
    Node n2 = { 5, &n3 };
    Node n1 = { 1, &n2 };
    n6.next = &n1;
    Node* head = &n1;

    printLista(head, 6, k);

    int numeros[6] = {1,2,3,4,5,6}; 
    Node* list = crearList(numeros, 6);
    printLista(list, 6, 0);
    eliminarList(list, 6);

    return 0;
}