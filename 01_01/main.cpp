#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef void(*PFunc)(int*);

void DiceResult(int* n) {
	srand(time(nullptr));
	int dice = rand() % 5 + 1;

	if (dice % 2 == 0) {
		printf("�A�^��\n");
	}
	else {
		printf("�n�Y��\n");
	}

	printf("�T�C�R���̌��� �� %d\n", dice);
}

void SetTimeout(PFunc p, int secound, int number) {
	Sleep(secound);
	p(&number);
}

int main(void) {
	PFunc p;

	int number = 0;     // �ԍ�
	int secound = 3000; // �b��

	printf("��(�)���Ǝv������ [ 1 ] �A ��(����)���Ǝv������ [ 0 ]����͂��Ă�������\n��\n");
	scanf_s("[ %d ]", &number);

	p = DiceResult;
	SetTimeout(p, secound, number);

	return 0;
}