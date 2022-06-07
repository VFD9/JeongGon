// Vector v0.9
#include <iostream>
#include<algorithm>

using namespace std;

// ������ ����
int Size = 0;

// �ִ� ���� ����
int Capacity = 0;

// �����̳�
int* Vector = nullptr;

// �����̳��� ������ ��ġ�� ���� �߰�
void push_back(const int& _Value);
void pop_back();
int front();
int back();
void erase(const int& _where);

int main(void)
{
	// ������ Ƚ����ŭ ��ȿ����
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100); // f12�� ������� ������ �Լ��� ���Ƿ� �̵��Ѵ�

	pop_back();
	push_back(10000);

	erase(3);

	cout << front() << endl;
	cout << back() << endl << endl;

	for (int i = 0; i < Size; ++i)
		cout << "Value : " << Vector[i] << endl;

	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	return 0;
}

void push_back(const int& _Value)
{
	if (Capacity <= Size)
	{
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		int* Temp = new int[Capacity + 1];

		/*for (int i = 0; i < Capacity; ++i)
			Vector[i]= NULL;*/

		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		Temp[Size] = _Value;
		Vector = Temp;
	}
	else
		Vector[Size] = _Value;

	++Size;

	cout << "Value : " << _Value << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	// �߰��� ������ �������� ���뷮�� �߰��ǵ��� �ڵ带 ����
	/*Capacity += (Capacity <= 3) ? 1 : (Capacity > Size ? 0 : Capacity >> 1);

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

	Vector = Temp;*/
}

void pop_back()
{
	--Size;
}

int front()
{
	return Vector[0];
}

int back()
{
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// Ư�� ��ġ�� �ִ� ���Ҹ� �����ϰ� ����
	
	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

// Ư�� ��ġ�� ������ �� �ִ� insert �Լ� �����

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