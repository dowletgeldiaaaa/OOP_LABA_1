#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int sortirovka(int **mas1, int m, int n) {
    int temp;
 
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            for (int k = j; k<n; k++)
            {
                if ((mas1[i][j]<mas1[i][k]) && (mas1[i][j]>0))
                {
                    temp = mas1[i][j];
                    mas1[i][j] = mas1[i][k];
                    mas1[i][k] = temp;
                }
            }
        }
    }
    cout << "Sorted matrix: " << endl;
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout << setw(3) << mas1[i][j] << setw(3);
        }
        cout << endl;
    }
    return 0;
}
 
int main(void)
{
    int **mas; // указатель на указатель на массив 
    int m, n; // количество строк и столбцов массива 
    cout << "Stroki i stolbci:" << endl;
    cin >> m >> n; // ввод количества строк и столбцов 
    mas = new int*[n]; // выделение памяти под массив указателей 
    for (int i = 0; i < m; i++)
        mas[i] = new int[n];
    cout << "Vvedite elementi v massiv:" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            //cout <<  i <<  j ;
            while (!(cin >> mas[i][j]))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Nepravelna vvod. Povtoriti.\n";
                //  cout <<  i <<j;
                //cout << "Введите количество строк: ";
            }
            //  cin >> mas[i][j];
        }
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << setw(4) << mas[i][j];
    }
    cout << endl;
 
    sortirovka(mas, n, m);
 
    delete[]mas;
    system("pause");
    return 0;
}
