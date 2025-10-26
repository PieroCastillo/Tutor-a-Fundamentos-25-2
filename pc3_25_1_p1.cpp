#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

// defines
#define MAX_ENTRIES_SIZE 100

// plantilla
struct historyEntry
{
    int id;
    string title;
    string url;
    string date;
    string hour;
};
// linear allocator

bool shouldExit = false;
int currentEntryIndex = -1;
historyEntry entries[MAX_ENTRIES_SIZE]; // tamaño determinado en compile time

/*
programa: |  instrucciones  |
proceso:  |   bss  |   heap   |  stack   |   instrucciones   | ...
*/

void showEntry(int idx)
{
    std::cout << "ID:     " << entries[idx].id;
    std::cout << " | Titulo: " << entries[idx].title;
    std::cout << " | URL:    " << entries[idx].url;
    std::cout << " | Fecha:  " << entries[idx].date;
    std::cout << " | Hora:   " << entries[idx].hour << std::endl;
}

void addEntry()
{
    if (currentEntryIndex >= MAX_ENTRIES_SIZE)
    {
        std::cout << "Capacidad Máxima de Entradas al historial alcanzadas" << std::endl;
        return;
    }

    // iniciar nueva entrada
    historyEntry newEntry = {};
    /*   |  stack  |
            | var |
    */
    std::cout << "Ingrese la URL: ";
    std::cin >> newEntry.url;

    std::cout << "Título de la página: ";
    std::cin >> newEntry.title;

    std::cout << "Fecha (dd/mm/aaaa): ";
    std::cin >> newEntry.date;

    std::cout << "Hora (hh:mm): ";
    std::cin >> newEntry.hour;

    currentEntryIndex++;
    newEntry.id = currentEntryIndex;
    std::cout << ">> Entrada agregada con ID: " << newEntry.id << std::endl;

    entries[currentEntryIndex] = newEntry;
}

void showEntries()
{
    for (int i = 0; i <= currentEntryIndex; i++)
    {
        showEntry(i);
    }
}

void deleteEntry()
{
    /*
    |    n   |   idx  |  m   |
    //...
    |    n   |     m    |
    */
    std::cout << "ingrese ID de la entrada a eliminar: ";
    int id; // indice de la entrada a eliminar
    std::cin >> id;

    currentEntryIndex--;

    // encontrar index usando id con busqueda lineal
    int idx = INT32_MAX;
    for (int i = 0; i <= currentEntryIndex; i++)
    {
        if (id == entries[i].id)
        {
            idx = i;
            break;
        }
    }

    // validacion de Indice
    if (idx == INT32_MAX)
    {
        std::cout << "No hay entradas al historial con ID: " << id << std::endl;
        return;
    }

    for (int i = 0; i <= currentEntryIndex; i++)
    {
        if (i < idx)
        {
            continue;
        }
        entries[i] = entries[i + 1];
    }
}

void search()
{
    string url;
    std::cout << "Ingrese URL a buscar: ";
    std::cin >> url;

    for (int i = 0; i <= currentEntryIndex; i++)
    {
        if (entries[i].url == url)
        {
            showEntry(i);
            return;
        }
    }
    std::cout << "entrada con URL : " << url << " no ha sido encontrada" << std::endl;
}

void clear()
{
    currentEntryIndex = -1;
}

void exit()
{
    shouldExit = true;
}

int main()
{
    while (!shouldExit)
    {
        std::cout << R"(--- HISTORIAL DE NAVEGACIÓN WEB ---
1. Agregar entrada al historial
2. Mostrar historial completo
3. Eliminar una entrada por ID
4. Buscar visitas por URL
5. Limpiar historial completo
0. Salir)" << std::endl;

        int option;
        std::cin >> option;

        switch (option)
        {
        case 1:
            addEntry();
            break;
        case 2:
            showEntries();
            break;
        case 3:
            deleteEntry();
            break;
        case 4:
            search();
            break;
        case 5:
            clear();
            break;
        case 0:
            exit();
            break;
        };
    }
    return 0;
}