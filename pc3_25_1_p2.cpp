#include <iostream>
#include <cmath>
#include <numbers>

struct Vertex
{
    double x;
    double y;
};

struct Poligonal
{
    int vertexCount;
    Vertex* pVertices;
};

void displayPoligonal(Poligonal& poly)
{
    for (int i = 0; i < poly.vertexCount;i++)
    {
        std::cout << " ( " << poly.pVertices[i].x << " , " << poly.pVertices[i].y << " ) ";
    }
    std::cout << std::endl;
}

int main()
{
    int vertexCount;
    double radious;

    // fill initial values

    std::cout << "ingrese número de vértices: ";
    std::cin >> vertexCount;
    std::cout << "ingrese radio: ";
    std::cin >> radious;

    // formula
    /*
    x[n] = x_c + r cos ( 2pi n / N + Thetha)
    y[n] = y_c + r sen ( 2pi n / N + Thetha)
    n : iteracion
    N : # vertices
    Thetha : angulo inicial
    x_c, y_c : centro
    r : redio
    entonces, con centro en 0,0 y Thetha = 45º

    x[n] = r cos ( 2pi n / N + pi/4)
    y[n] = r sen ( 2pi n / N + pi/4)
    */
    Poligonal poligon = {};
    poligon.vertexCount = vertexCount;
    poligon.pVertices = new Vertex[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        double angle = (2 * std::numbers::pi * i / (double)vertexCount);// * (std::numbers::pi / 2);

        double x = radious * std::cos(angle);
        double y = radious * std::sin(angle);

        poligon.pVertices[i] = { x, y };
    }
    displayPoligonal(poligon);

    /*
                                           /\
                                          /  \
    -------------------------- -> --------    ---------
                    1  segmentos -> 3 vertices
                    = 3 vertices
                    n lados -> 3*n vertices nuevos, + vertices existentes = 4*n
                    https://larryriddle.agnesscott.org/ifs/kcurve/kcurve.htm

    */

    double x1, y1, x2, y2, x3, y3, x4, y4;

    Vertex* newVertices = new Vertex[4 * vertexCount];

    for (int i = 0; i < vertexCount; i++) {

        double x = poligon.pVertices[i].x;
        double y = poligon.pVertices[i].y;
        
        x1 = (1 / 3) * x;
        y1 = (1 / 3) * y;

        x2 = (1 / 6) * x - (sqrt(3) / 6) * y + (1 / 3);
        y2 = (sqrt(3) / 6) * x + (1 / 6) * y;

        x3 = (1 / 6) * x + (sqrt(3) / 6) * y + (1 / 2);
        y3 = -(sqrt(3) / 6) * x + (1 / 6) * y + (sqrt(3) / 6);

        x4 = (1 / 3) * x + (2 / 3);
        y4 = (1 / 3) * y;

        std::cout << "point: " << x1 << " ,  " << y1 << std::endl;
        std::cout << "point: " << x2 << " ,  " << y2 << std::endl;
        std::cout << "point: " << x3 << " ,  " << y3 << std::endl;
        std::cout << "point: " << x4 << " ,  " << y4 << std::endl;

        newVertices[(4 * i)] = { x1, y1 };
        newVertices[(4 * i) + 1] = { x2, y2 };
        newVertices[(4 * i) + 2] = { x3, y3 };
        newVertices[(4 * i) + 3] = { x4, y4 };
    }
    delete[] poligon.pVertices;

    poligon.vertexCount = 4 * vertexCount;
    poligon.pVertices = newVertices;

    displayPoligonal(poligon);

    delete[] poligon.pVertices;

    return 0;
}