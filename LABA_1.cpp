#include <iostream>

using namespace std;

int main()
{
	int **mtr;
	int n = 0, m = 0;

	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;

	mtr = new int*[n];
	for (int i = 0; i < n; i++)
		mtr[i] = new int[m];

	cout << "Input values: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "mtr[" << i+1 << "][" << j+1 << "] = ";
			cin >> mtr[i][j];
		}

	int count, temp, c;
	int *mtr_p = new int[m];
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < m; j++)
			if (mtr[i][j] >= 0)
			{
				mtr_p[count] = mtr[i][j];
				count++;
			}
		for (int k = 0; k < count; k++)
			for (int j = 0; j < count-1; j++)
				if (mtr_p[j] < mtr_p[j + 1])
				{
					c = mtr_p[j];
					mtr_p[j] = mtr_p[j + 1];
					mtr_p[j + 1] = c;
				}

		temp = 0;
		for (int j = 0; j < m; j++)
			if (mtr[i][j] >= 0)
			{
				mtr[i][j] = mtr_p[temp];
				temp++;
			}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mtr[i][j] << "\t";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete mtr[i];
	delete mtr;

	system("pause");
	return 0;
}
