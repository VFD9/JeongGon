// Vector v0.7
#include <iostream>
#include<algorithm>

using namespace std;

// 원소의 개수
int Size = 0;

// 최대 수용 개수
int Capacity = 0;

// 컨테이너
int* Vector = nullptr;

void push_back(const int& _Value);

int main(void)
{
	// 누적된 횟수만큼 비효율적
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

// 배열의 특징
/*
	장점
	1. 직접 접근이 가능하다.
	2. 데이터가 나열되어서 접근 속도가 일정하다.
	3. 데이터나 텍스처를 불러오기 좋다.

	단점
	1. 배열의 동적 변환이 불가능하다.(길이가 정해지면 바꿀 수 없다)
	2. 데이터를 어디에 뒀는지 알 수 없다.
	3. 오브젝트를 담기에는 비효율적이기에 사용하지 않는다.
*/

// 이동이 복제보다 빠르다.

	// ** 1. 데이터 추가 (새로운 공간 확보)
	// ** 2. 데이터 삭제
	// ** 3. 데이터를 삽입할 수 있는 공간의 크기
	// ** 4. 현재 삽입되어있는 원소의 개수
	// ** 5. 컨테이너의 시작 지점
	// ** 6. 컨테이너의 종료 지점