// STLVector v0.1
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vecNumbers;

	for(int i = 0; i < 10; ++i)
		vecNumbers.push_back(10 * i);

	for (vector<int>::iterator iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	/*// ���� ������ ������ ������ �迭
	int Array[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	// ���� ������ �ȵɶ� ������� ��ü��
	int* iterator = Array;

	for (int i = 0; i < 16; ++i)
		cout << Array[i] << endl;

	for (int i = 0; i < 16; ++i)
		cout << *(iterator + i) << endl;*/

	return 0;
}



// ���� ������ stack�� �ְ� ���ԵǴ� ���� heap�� �ִ�.
// ���� �����Ϳ� ���� �ݿ��ϰ� ������ ������(Call by Reference)�� ����Ѵ�.