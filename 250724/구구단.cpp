#include <iostream>

using namespace std;

int main()
{
	int i(2);

	while (true)
	{
		int j(1);
		cout << "-------------" << i << "��" << "-------------" << endl;

		while (true)
		{
			cout << i << " * " << j << " = " << i * j << endl;
			j++;

			if (j > 9)
			{
				break;
			}
		}

		i++;

		if (i > 9)
		{
			cout << "----------------------------" << endl;
			cout << "������ ���α׷��� �����մϴ�." << endl;
			break;
		}
	}
	return 0;
}