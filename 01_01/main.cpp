#include <stdio.h>

int Recursive(int n, int salary) {
	if (n <= 1) {
		return salary;
	}
	return (Recursive(n - 1, salary) * 2 - 50);
}

int main() {
	
	int n = 8;
	int salary = 100;
	int result;

	result = Recursive(n, salary);
	printf("�ċN�\�Ȓ����̌n�ł�%d���Ԗڂ̎��� = %d\n", n, result);



	return (0);
}