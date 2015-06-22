#include <stdio.h>
#include <math.h>
#include "pasLib.h"

int readInt()
{
	int x;
	scanf("%d", &x);
	return x;
}

int readChar()
{
	int x;
	char ch;
	scanf("%c", &ch);
	x = ch;
	return x;
}

void writeInt(int x)
{
	printf("%d", x);
}

void writeChar(int x)
{
	char ch = x;
	printf("%c", ch);
}

void writelnInt(int x)
{
	printf("%d\n", x);	
}

void writelnChar(int x)
{
	char ch = x;
	printf("%c\n", ch);	
}

int absInt(int x)
{
	return abs(x);
}

int oddInt(int x)
{
	return (x % 2);
}

int sqrInt(int x)
{
	return x * x;
}

int sqrtInt(int x)
{
	return (int)sqrt(x);
}