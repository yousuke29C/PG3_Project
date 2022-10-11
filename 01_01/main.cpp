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
	printf("再起可能な賃金体系での%d時間目の時給 = %d\n", n, result);



	return (0);
}