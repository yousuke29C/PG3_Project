#include <stdio.h>
#include <windows.h>
#include <random>
#include <ctype.h>
#include <time.h>
#include <functional>

using namespace std;

/// <summary>
/// �ҋ@
/// </summary>
/// <param name="second">�ҋ@����b��</param>
void SetTimeout(int second) {
	Sleep(second * 1000);
}

int main(int arge, const char* argv[]) {
	
	srand(time(nullptr));

	int num;//�v���C���[
	int answer = rand() % 6 + 1;//�_�C�X

	//�ϐ�dice��1�`6�܂ł̒l�������_���œ���
	function<int(int)> dice = [](int x) {return x; };

	function<void(int)> timer = SetTimeout;

	printf("�(��)�Ȃ�u�P�v����(��)�Ȃ�u�Q�v����͂��ĉ�����\n\n");
	num = getchar();//�l�𓾂�
	printf("\n");

	if (isdigit(num)) {
		// ����
		printf("���͂����̂� : %c\n\n", num);//�擾�����l
	}
	else {
		printf("%c �͐����ł͂���܂���\n", num);
		return 1;
	}

	timer(3);//3�b�҂�

	printf("���� : %d\n\n", dice(answer));//����

	//�����Ȃ�
	if (dice(answer) % 2 == 0) {
		printf("��\n\n");

		//�����Ȃ�
		if (num % 2 == 0) {
			printf("������\n");
		}
		//��Ȃ�
		else {
			printf("�͂���\n");
		}
	}
	//��Ȃ�
	else {
		printf("��\n\n");
		//�����Ȃ�
		if (num % 2 == 0) {
			printf("�͂���\n");
		}
		//��Ȃ�
		else {
			printf("������\n");
		}
	}

	return 0;
}