// EightQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct DeskPoint {
	int x;
	int y;
};

int canKill(DeskPoint q1, DeskPoint q2) {
	if (q1.x == q2.x) return 5;
	if (q1.y == q2.y) return 8;
	if ((q1.x - q1.y) == (q2.x - q2.y)) return 3;
	if ((q1.x + q1.y) == (q2.x + q2.y)) return 1;
	return 0;
}

int charLower(int ch) {
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
	return ch;
}

void swap(int *x, int i, int j) {
	int t = x[i];
	x[i] = x[j];
	x[j] = t;
}

bool isSolution(const int *q, int n) {
        return true;
}

void printSolution(const int *q, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	printf("\n");
}

int findMin(const int *x, int n) {
	int iMin = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] < x[iMin]) iMin = i;
	}
	printf("start %d length %d iMin = %d\n", x[0], n, iMin);
	return iMin;
}

void nextSolution(const int *q, int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (q[i - 1] < q[i]) {
			int toSwap = i + findMin(q + i, n - i);
			printf("==should swap %d, %d\n", i - 1, toSwap);
			break;
		}
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	printf("Enter number of queens:");
	int n = getchar();
	getchar();
	n -= '0';
	if ((n < 1) || (n > 9)) {
		printf("ERROR!!!\n");
		return 1;
	}
	int q[9];
	for (int i = 0; i < n; i++) {
		q[i] = i + 1;
	}
	while (1) {
		swap(q, n - 2, n - 1);
		if (isSolution(q, n)) printSolution(q, n);
		nextSolution(q, n);
		if (getchar() == 24) break;
	}
	return 0;
}

