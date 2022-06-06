// Vector v0.7
#include <iostream>
#include<algorithm>

using namespace std;

// ������ ����
int Size = 0;

// �ִ� ���� ����
int Capacity = 0;

// �����̳�
int* Vector = nullptr;

void push_back(const int& _Value);

int main(void)
{
	// ������ Ƚ����ŭ ��ȿ����
	for (int i = 0; i < 29; ++i)
		push_back(i * 100 + 100);

	/*for (int i = 0; i < Size; ++i)
		cout << Vector[i] << endl;*/
	
	return 0;
}

void push_back(const int& _Value)
{
	Capacity += (Capacity <= 3) ? 1 : (Capacity > Size ? 0 : Capacity >> 1);

	int* Temp = new int[Capacity];

	for (int i = 0; i < Size; ++i)
		Temp[i] = Vector[i];

	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}

	Temp[Size] = _Value;
	++Size;

	Vector = Temp;
	
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;
}

// �迭�� Ư¡
/*
	����
	1. ���� ������ �����ϴ�.
	2. �����Ͱ� �����Ǿ ���� �ӵ��� �����ϴ�.
	3. �����ͳ� �ؽ�ó�� �ҷ����� ����.

	����
	1. �迭�� ���� ��ȯ�� �Ұ����ϴ�.(���̰� �������� �ٲ� �� ����)
	2. �����͸� ��� �״��� �� �� ����.
	3. ������Ʈ�� ��⿡�� ��ȿ�����̱⿡ ������� �ʴ´�.
*/

// �̵��� �������� ������.

	// ** 1. ������ �߰� (���ο� ���� Ȯ��)
	// ** 2. ������ ����
	// ** 3. �����͸� ������ �� �ִ� ������ ũ��
	// ** 4. ���� ���ԵǾ��ִ� ������ ����
	// ** 5. �����̳��� ���� ����
	// ** 6. �����̳��� ���� ����