// Vector v0.9
#include <iostream>
#include <algorithm>

using namespace std;

// 현재 원소의 개수
int Size = 0;

// 최대 수용 개수
int Capacity = 0;

// 컨테이너
int* Vector = nullptr;

// 컨테이너의 마지막 위치에 값을 추가
void push_back(const int& _Value);

// 컨테이너의 마지막 위치에 값을 삭제
void pop_back();

// 컨테이너의 가장 앞 쪽에 있는 원소
int front();

// 컨테이너의 가장 뒤 쪽에 있는 원소
int back();

// _where의 위치에 데이터 삭제
void erase(const int& _where);

// _index의 위치에 데이터 추가
void insert(const int& _index, const int& _Value2);

int main(void)
{
	// 누적된 횟수만큼 비효율적
	for (int i = 0; i < 10; ++i)
		push_back(i * 1 + 1); // f12를 누를경우 지정한 함수의 정의로 이동한다

	insert(4, 10);

	for (int i = 0; i < Size; ++i)
		cout << "Value : " << Vector[i] << endl;

	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	return 0;
}

void push_back(const int& _Value)
{
	// 만약 더이상 수용할 수 있는 공간이 없다면
	if (Capacity <= Size)
	{
		// 현재 수용량이 4보다 작다면 1씩 증가하고
		// 현재 수용량이 4보다 크거나 같다면 1/2 만큼 추가함
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// 임시의 저장소를 생성
		int* Temp = new int[Capacity + 1];

		// 생성된 공간을 초기화함
		for (int i = 0; i < Capacity; ++i)
			Temp[i] = NULL;

		// 기존에 있던 값을 복사
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// 기존에 값을 삭제
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		// 임시의 값(해당 주소)를 복사해옴
		Temp[Size] = _Value;

		// 임시의 주소값에 복사해둔 값과 추가된 새로운 값을 다시 전역변수로 저장되어 있는 Vector로 가져옴
		Vector = Temp;
	}
	else
		// 마지막 위치에 값 추가
		Vector[Size] = _Value;

	// 현재 원소의 최대값 증가
	++Size;

	// 추가할 공간이 없을때만 수용량이 추가되도록 코드를 수정
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
	// 현재 원소의 최대값 감소
	--Size;
}

int front()
{
	// 0번째 원소 반환
	return Vector[0];
}

int back()
{
	// 마지막 원소 반환
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// 특정 위치에 있는 원소를 삭제하고 정렬
	// 현재 원소의 최대값 감소
	--Size;

	// 재정렬
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

void insert(const int& _index, const int& _Value2)
{
	// 특정 위치에 삽입할 수 있는 insert 함수 만들기
	// 
	if (Capacity <= Size)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

	// 임시 저장소
	int* Temp = new int[Capacity + 1];

	// 초기화
	for (int i = 0; i < Capacity; ++i)
		Temp[i] = NULL;

	// 해당 위치 이전의 값을 복사
	for (int i = 0; i < _index; ++i)
		Temp[i] = Vector[i];

	// 해당 위치에 값을 삽입
	Temp[_index] = _Value2;
	++Size;

	// 해당 위치 이후의 값을 복사
	for (int i = _index + 1; i < Size; ++i)
		Temp[i] = Vector[i - 1];

	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}

	Vector = Temp;
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

// Call by Reference