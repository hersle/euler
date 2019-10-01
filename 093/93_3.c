#include <stdio.h>

int p[24][4] = {
	{1, 2, 3, 4},
	{1, 3, 2, 4},
	{2, 1, 3, 4},
	{2, 3, 1, 4},
	{3, 1, 2, 4},
	{3, 2, 1, 4},
	{1, 2, 4, 3},
	{1, 3, 4, 2},
	{1, 4, 2, 3},
	{1, 4, 3, 2},
	{2, 1, 4, 3},
	{2, 3, 4, 1},
	{2, 4, 1, 3},
	{2, 4, 3, 1},
	{3, 1, 4, 2},
	{3, 2, 4, 1},
	{3, 4, 1, 2},
	{3, 4, 2, 1},
	{4, 1, 2, 3},
	{4, 1, 3, 2},
	{4, 2, 1, 3},
	{4, 2, 3, 1},
	{4, 3, 1, 2},
	{4, 3, 2, 1}
};

int oper[3] = {0, 0, 0};

double eval(double a, int oper, double b) {
	if (oper == 0)
		return a + b;
	if (oper == 1)
		return a - b;
	if (oper == 2)
		return a * b;
	else 
		return a / b;
}

void func(double nums[], int len) {
	int i;
	double num1, num2;

	/*
	for (i = 0; i < len; i++) 
		printf("%d ", nums[i]);
	printf("\n");
	*/

	if (len == 1) {
		printf("%lf\n", nums[0]);
	} 
	if (len >= 2) {
		num1 = nums[0];
		num2 = nums[1];
		nums[1] = eval(num1, oper[0], num2);
		func(nums + 1, len - 1);
		nums[0] = num1;
		nums[1] = num2;
	} 
	if (len >= 3) {
		num1 = nums[1];
		num2 = nums[2];
		nums[1] = eval(num1, oper[1], num2);
		if (len == 4) {
			nums[2] = nums[3];
		}
		func(nums, len - 1);
		if (len == 4) {
			nums[3] = nums[2];
		}
		nums[1] = num1;
		nums[2] = num2;
	} 
	if (len == 4) {
		num1 = nums[2];
		num2 = nums[3];
		nums[2] = eval(num1, oper[2], num2);
		func(nums, len - 1);
		nums[2] = num1;
		nums[3] = num2;
	}
}

int main() {
	int i, j;
	double a, b, c, d;
	double nums[4];

	a = 1.0, b = 2.0, c = 3.0, d = 4.0;

	for (i = 0; i < 24; i++) {
		nums[p[i][0]] = a;
		nums[p[i][1]] = b;
		nums[p[i][2]] = c;
		nums[p[i][3]] = d;
		for (oper[0] = 0; oper[0] < 4; oper[0]++) {
			for (oper[1] = 0; oper[1] < 4; oper[1]++) {
				for (oper[2] = 0; oper[2] < 4; oper[2]++) {
					func(nums, 4);
				}
			}
		}
	}

	return 0;
}
