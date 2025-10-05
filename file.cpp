/*
Ordenamiento 2 : merge sort, quick sort
Busqueda binaria
Punteros, punteros dobles, punteros hacia cadenas
*/

/*
Puntero ? 
|--------------- Memoria ---------------|
| Bloque 0 | B 1   ......     |  B n-1  |
  address: |

int num = 7;
int* pNum = (int*)malloc(sizeof(int));  
int* rNum = &num;

memoria:
|       stack        |        heap         |
|#############       |  ###   #    ####  # |
// stack overflow

int* pHola = (int*)malloc(4*sizeof(int));
programaAlmacenarEnMemoriaRAM(); // ERROR
el unico que puede es el SO, windows, linux, android
llamada syscall (system call), WindowsUsarMemoriaRAM(param1, param2, param3 ...) // si se puede ejecutar
el lenguaje C te ofrece una abstraccion,
    malloc(size) -> void*  // almacena en heap
    free(ptr)              // libera en heap       
en C++ existe:
    new 
    delete


|       stack        |        heap         |
|#############       |  ###   #    ####  # |

llamas a malloc(2*sizeof(int)):
|       stack        |        heap         |
|#############       |  ###   # ## ####  # |
                retorna:        ^

int num = 7;      // guardas en stack
int* rNum = &num; // puntero al stack
int* pNum = (int*)malloc(sizeof(int)); // guardas en heap

// caso 1
void* crearOtraCosa()
{
    int value = 9; // guardas en stack
    return (void*)&value; // retornas puntero al stack
}

|    stack     |
|########      | ejecuta crearOtraCosa()
|#####         | sale de crearOtraCosa()
        ^
void algo()
{
    void* ptr = crearOtraCosa(); // retornas puntero al stack, pero el stack es destruido
    std::cout << *((char*)ptr) << std::endl; // 890943894890490889024 
}

// caso 2 
void* crearOtraCosa()
{
    int* valuePtr = (int*)malloc(sizeof(int)); // guardas en stack
    *valuePtr = 9;
    return (void*)valuePtr; // retornas puntero al stack
}

|      heap        |
|# ##   #    ######| ejecuta crearOtraCosa()
|# ##   #    ######| sale de crearOtraCosa()
        ^
void algo()
{
    void* ptr = crearOtraCosa(); // retornas puntero al stack, pero el stack es destruido
    std::cout << *((char*)ptr) << std::endl; // 9
    free(ptr);
}

///////////////////////77

void recurse()
{
    int x = 10; // guardas en stack
    recurse(); // llamas de forma recursiva
}

int hola = 999; // guardas en stack



*/

/* puntero doble

|       stack       |       heap       |
| #######           | #    ####   # ## |
malloc(): 
|       stack       |       heap       |
| #######           | # ## ####   # ## |
                        ^ 
void*, int *, char*
uint64_t // un puntero es una direccion, esa direccion es un numerito
puedes guardar direcciones, en el heap

int* lista1 = malloc(10*sizeof(int));
int* lista2 = malloc(5*sizeof(int));

int** listas = (int**)malloc(2*sizeof(int*));
listas[0] = lista1;
listas[1] = lista2;

// caso: redimensionar lista
lista1 = (int*)realloc(lista1, 20*sizeof(int));
####
######## : nuevo tamaño

ObjectoDesc* algo = {...} ;
Objeto** algoObj = createAlgo(&algo); // directx

lista:
|    direccion    | valor:
lista1            | 0x0009292929292
lista2            | 0x0C000FD111111

char** cadena = "hola";
int** mat;

malloc()/free()
realloc()
calloc()

struct DyArray
{
    int size;
    int capacity;
    int* data;
};
DyArray* create(..);
void free(DyArray* arr);
void push(DyArray* arr, int value);
int  pop(DyArray* arr);

//static
int arr[1000] = {0,1,4,5};
int* arr2; //añadi, quitar, aumentar cap, disminuirla
*/