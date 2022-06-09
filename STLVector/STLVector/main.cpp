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

	/*// 직접 접근이 가능한 형태인 배열
	int Array[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	// 직접 접근이 안될때 대신해줄 대체제
	int* iterator = Array;

	for (int i = 0; i < 16; ++i)
		cout << Array[i] << endl;

	for (int i = 0; i < 16; ++i)
		cout << *(iterator + i) << endl;*/

	return 0;
}



// 지역 변수는 stack에 있고 대입되는 값은 heap에 있다.
// 원본 데이터에 값을 반영하고 싶으면 포인터(Call by Reference)를 사용한다.