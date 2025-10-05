#include <iostream>

using namespace std;

void printMat(int** mat)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matPower(int** mat, int k)
{
    int** res = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++)
    {
        res[i] = (int*)malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = mat[i][j];
        }
    }

    for (int s = 0; s < k; s++) {
        cout << "prod " << s << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int x = 0; x < 2; x++)
                {
                    res[i][j] += res[i][x] * mat[x][j];
                }
            }
        }
        printMat(res);
    }

    printMat(res);

    for (int i = 0; i < 2; i++)
    {
        free(res[i]);
    }
    free(res);
}

int main()
{
    int k = 20;

    int f1[2] = { 2,3 };
    int f2[2] = { 4,5 };
    int** mat = (int**)malloc(2 * sizeof(int*));
    mat[0] = f1;
    mat[1] = f2;
    printMat(mat);
    matPower(mat, k);
}