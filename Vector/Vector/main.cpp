// Vector v0.9
#include <iostream>
#include <algorithm>

using namespace std;

// ���� ������ ����
int Size = 0;

// �ִ� ���� ����
int Capacity = 0;

// �����̳�
int* Vector = nullptr;

// �����̳��� ������ ��ġ�� ���� �߰�
void push_back(const int& _Value);

// �����̳��� ������ ��ġ�� ���� ����
void pop_back();

// �����̳��� ���� �� �ʿ� �ִ� ����
int front();

// �����̳��� ���� �� �ʿ� �ִ� ����
int back();

// _where�� ��ġ�� ������ ����
void erase(const int& _where);

// _index�� ��ġ�� ������ �߰�
void insert(const int& _index, const int& _Value2);

int main(void)
{
	// ������ Ƚ����ŭ ��ȿ����
	for (int i = 0; i < 10; ++i)
		push_back(i * 1 + 1); // f12�� ������� ������ �Լ��� ���Ƿ� �̵��Ѵ�

	insert(4, 10);

	for (int i = 0; i < Size; ++i)
		cout << "Value : " << Vector[i] << endl;

	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	return 0;
}

void push_back(const int& _Value)
{
	// ���� ���̻� ������ �� �ִ� ������ ���ٸ�
	if (Capacity <= Size)
	{
		// ���� ���뷮�� 4���� �۴ٸ� 1�� �����ϰ�
		// ���� ���뷮�� 4���� ũ�ų� ���ٸ� 1/2 ��ŭ �߰���
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// �ӽ��� ����Ҹ� ����
		int* Temp = new int[Capacity + 1];

		// ������ ������ �ʱ�ȭ��
		for (int i = 0; i < Capacity; ++i)
			Temp[i] = NULL;

		// ������ �ִ� ���� ����
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// ������ ���� ����
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		// �ӽ��� ��(�ش� �ּ�)�� �����ؿ�
		Temp[Size] = _Value;

		// �ӽ��� �ּҰ��� �����ص� ���� �߰��� ���ο� ���� �ٽ� ���������� ����Ǿ� �ִ� Vector�� ������
		Vector = Temp;
	}
	else
		// ������ ��ġ�� �� �߰�
		Vector[Size] = _Value;

	// ���� ������ �ִ밪 ����
	++Size;

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
	// ���� ������ �ִ밪 ����
	--Size;
}

int front()
{
	// 0��° ���� ��ȯ
	return Vector[0];
}

int back()
{
	// ������ ���� ��ȯ
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// Ư�� ��ġ�� �ִ� ���Ҹ� �����ϰ� ����
	// ���� ������ �ִ밪 ����
	--Size;

	// ������
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

void insert(const int& _index, const int& _Value2)
{
	// Ư�� ��ġ�� ������ �� �ִ� insert �Լ� �����
	// 
	if (Capacity <= Size)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

	// �ӽ� �����
	int* Temp = new int[Capacity + 1];

	// �ʱ�ȭ
	for (int i = 0; i < Capacity; ++i)
		Temp[i] = NULL;

	// �ش� ��ġ ������ ���� ����
	for (int i = 0; i < _index; ++i)
		Temp[i] = Vector[i];

	// �ش� ��ġ�� ���� ����
	Temp[_index] = _Value2;
	++Size;

	// �ش� ��ġ ������ ���� ����
	for (int i = _index + 1; i < Size; ++i)
		Temp[i] = Vector[i - 1];

	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}

	Vector = Temp;
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

// Call by Reference