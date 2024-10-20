// GameCoding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#include <stdio.h>

struct DataList {
	int a, b, c;
};

void ModifyData(int* p_Value) {
	if (*p_Value < 0)
		printf("값을 %d에서 %d로 변경함.\n", -*p_Value, *p_Value = -*p_Value);
}

int MultiplyPositiveDataList(struct DataList* p_Values) {
	ModifyData(&p_Values->a);
	ModifyData(&p_Values->b);
	ModifyData(&p_Values->c);

	return p_Values->a * p_Values->b * p_Values->c;
}

int main()
{
	struct DataList values;

	printf("곱셈할 수 3개를 입력하시오:");

	scanf_s("%d %d %d", &values.a, &values.b, &values.c);
	printf("Result : %d",MultiplyPositiveDataList(&values));

	struct DataList other = { -3,-4, 2 };
	printf("Result : %d", MultiplyPositiveDataList(&other));

	

}

