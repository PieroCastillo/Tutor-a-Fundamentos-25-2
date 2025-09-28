#include <iostream> //input output stream
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char EsNombreValido(const char* p)
{
    char* temp = new char[strlen(p)];
    strcpy(temp, p);

    cout << temp << endl;

    int pos = 1;

    int underscoreCounter = 0;

    while (temp)
    {
        auto chr = *temp;
        cout << chr << " ";

        if (chr == '\0')
        {
            break;
        }

        // regla de ser siempre letra, numero o guion bajo
        if (!(isalnum(chr) || chr == '_'))
            return pos;

        if (pos == 1 & isdigit(chr))
        {
            return pos;
        }

        if (chr == ' ')
            return pos;

        if (chr == '_')
            underscoreCounter++;

        if (underscoreCounter >= 2)
            return pos - 1;

        temp++;
        pos++;
    }

    return 0;
}

int main()
{
    cout << to_string(EsNombreValido("mi_variable1")) << endl;// 0-> variable correcta
    cout << to_string(EsNombreValido("1variable")) << endl; // 1 → empieza con dígito
    cout << to_string(EsNombreValido("var name")) << endl; // 4 → espacio en blanco
    cout << to_string(EsNombreValido("var__name")) << endl; // 4 → doble guion bajo

    return 0;
}