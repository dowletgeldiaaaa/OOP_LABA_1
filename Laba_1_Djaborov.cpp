#include <iostream>
#include <ctime>

using namespace std;

void del_all(int **mas, int n);
void input(int **mas, int n, int m);
void print(int **mas, int n, int m);
int** res_func(int **mas1, int n1, int m1, int **mas2, int n2, int m2);

int main()
{
	int **mas1, **mas2, **mas3;
	int n1, m1, n2, m2, n3 = 0, m3 = 0;

	srand(time(NULL));

	cout << "Input size of massives :" << endl;
	cout << "n = ";
	cin >> n1;
	cout << "m = ";
	cin >> m1;
	mas1 = new int*[n1];
	for (int i = 0; i < n1; i++)
		mas1[i] = new int[m1];
	input(mas1, n1, m1);

	n2 = n1;
	m2 = m1;
	mas2 = new int*[n2];
	for (int i = 0; i < n2; i++)
		mas2[i] = new int[m2];
	input(mas2, n2, m2);

	mas3 = res_func(mas1, n1, m1, mas2, n2, m2);
	n3 = n1;
	m3 = m1;

	cout << "Massive 1 :" << endl;
	print(mas1, n1, m1);
	cout << "Massive 2 :" << endl;
	print(mas2, n2, m2);
	cout << "Massive 3 :" << endl;
	print(mas3, n3, m3);

	del_all(mas1, n1);
	del_all(mas2, n2);
	del_all(mas3, n3);

	system("pause");
	return 0;
}
void del_all(int **mas, int n)
{
	for (int i = 0; i < n; i++)
		delete mas[i];
	delete mas;
	cout << "Massive is deleted!" << endl;
}
void input(int **mas, int n, int m)
{
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cout << "ms[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> mas[i][j];
		}
	cout << endl;*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			mas[i][j] = rand() % 50 - 25;
		}
}
void print(int **mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << "\t";
		cout << endl;
	}
}
int** res_func(int **mas1, int n1, int m1, int **mas2, int n2, int m2)
{
	int **ms;
	ms = new int*[n1];
	for (int i = 0; i < n1; i++)
		ms[i] = new int[m1];

	for(int i=0;i<n1;i++)
		for (int j = 0; j < m1; j++)
		{
			ms[i][j] = mas1[i][j] + mas2[i][j];
		}

	return ms;
}
