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

	// 가장 앞에 있는 원소를 반환
	vecNumbers.front();

	// 가장 뒤에 있는 원소를 반환
	vecNumbers.back();

	// 시작점을 가리키는 반복자
	vecNumbers.begin();

	// 종료 지점을 가리키는 반복자
	vecNumbers.end();

	/*for (vector<int>::iterator iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (int i = 0; i < vecNumbers.size(); ++i)
		cout << vecNumbers[i] << endl;*/

	/*// 직접 접근이 가능한 형태인 배열
	int Array[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	// 직접 접근이 안될때 대신해줄 대체제
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

// 지역 변수는 stack에 있고 대입되는 값은 heap에 있다.
// 원본 데이터에 값을 반영하고 싶으면 포인터(Call by Reference)를 사용한다.