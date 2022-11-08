#include <stdio.h>
#include <windows.h>
#include <random>
#include <ctype.h>
#include <time.h>
#include <functional>

using namespace std;

/// <summary>
/// 待機
/// </summary>
/// <param name="second">待機する秒数</param>
void SetTimeout(int second) {
	Sleep(second * 1000);
}

int main(int arge, const char* argv[]) {
	
	srand(time(nullptr));

	int num;//プレイヤー
	int answer = rand() % 6 + 1;//ダイス

	//変数diceに1～6までの値がランダムで入る
	function<int(int)> dice = [](int x) {return x; };

	function<void(int)> timer = SetTimeout;

	printf("奇数(半)なら「１」偶数(丁)なら「２」を入力して下さい\n\n");
	num = getchar();//値を得る
	printf("\n");

	if (isdigit(num)) {
		// 入力
		printf("入力したのは : %c\n\n", num);//取得した値
	}
	else {
		printf("%c は数字ではありません\n", num);
		return 1;
	}

	timer(3);//3秒待つ

	printf("結果 : %d\n\n", dice(answer));//結果

	//偶数なら
	if (dice(answer) % 2 == 0) {
		printf("丁\n\n");

		//偶数なら
		if (num % 2 == 0) {
			printf("当たり\n");
		}
		//奇数なら
		else {
			printf("はずれ\n");
		}
	}
	//奇数なら
	else {
		printf("半\n\n");
		//偶数なら
		if (num % 2 == 0) {
			printf("はずれ\n");
		}
		//奇数なら
		else {
			printf("当たり\n");
		}
	}

	return 0;
}