#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef void(*PFunc)(int*);

void DiceResult(int* n) {
	srand(time(nullptr));
	int dice = rand() % 5 + 1;

	if (dice % 2 == 0) {
		printf("アタリ\n");
	}
	else {
		printf("ハズレ\n");
	}

	printf("サイコロの結果 → %d\n", dice);
}

void SetTimeout(PFunc p, int secound, int number) {
	Sleep(secound);
	p(&number);
}

int main(void) {
	PFunc p;

	int number = 0;     // 番号
	int secound = 3000; // 秒数

	printf("半(奇数)だと思ったら [ 1 ] 、 丁(偶数)だと思ったら [ 0 ]を入力してください\n↓\n");
	scanf_s("[ %d ]", &number);

	p = DiceResult;
	SetTimeout(p, secound, number);

	return 0;
}