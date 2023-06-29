#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
 * factorizer - Factorize as many numbers
 * as possible into a product of two smaller numbers
 * @number: number to factor
 * Return: nothing
 */
void factorizer(char *number)
{
	unsigned long num = strtoul(number, NULL, 10), i = 2;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%lu=%lu*%lu\n", num, num / i, i);
			return;
		}
	}
}
/**
 * main - main entry
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char buffer[BUFFER_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (-1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Failed to open file: %s\n", argv[1]);
		return (-1);
	}
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
	{
		factorizer(buffer);
	}
	fclose(fp);
	return (0);
}
