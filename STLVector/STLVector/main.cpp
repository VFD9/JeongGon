// STLVector v0.2
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int MAX = 50;

	vector<int> vecNumbers;

	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i);
		//cout << "apacity : " <<  vecNumbers.capacity() << endl;
		//cout << "size : " << vecNumbers.size() << endl << endl;
	}

	// ���� �տ� �ִ� ���Ҹ� ��ȯ
	vecNumbers.front();

	// ���� �ڿ� �ִ� ���Ҹ� ��ȯ
	vecNumbers.back();

	// �������� ����Ű�� �ݺ���
	vecNumbers.begin();

	// ���� ������ ����Ű�� �ݺ���
	vecNumbers.end();

	/*for (vector<int>::iterator iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (int i = 0; i < vecNumbers.size(); ++i)
		cout << vecNumbers[i] << endl;*/

	/*// ���� ������ ������ ������ �迭
	int Array[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	// ���� ������ �ȵɶ� ������� ��ü��
	int* iterator = Array;

	for (int i = 0; i < 16; ++i)
		cout << Array[i] << endl;

	for (int i = 0; i < 16; ++i)
		cout << *(iterator + i) << endl;*/

	/*for (auto iter = vecNumbers.begin(); iter != vecNumbers.end();)
	{
		if ((*iter) > MAX)
			iter = vecNumbers.erase(iter);
		else
			++iter;
	}

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;*/

	return 0;
}

// ���� ������ stack�� �ְ� ���ԵǴ� ���� heap�� �ִ�.
// ���� �����Ϳ� ���� �ݿ��ϰ� ������ ������(Call by Reference)�� ����Ѵ�.