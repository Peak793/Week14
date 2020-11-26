#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "string.h"
#include "stdlib.h"
void Cipher(char message[100], int n);
int main()
{
	char **plainText;
	unsigned int a;
	printf("How mamy message : ");
	scanf("%u", &a);
	plainText = (char**)malloc(a * sizeof(plainText));
	for (int i = 0; i < a; i++)
	{
		plainText[i] = (char*)malloc(sizeof(char [100]));
	}
	printf("\n||Enter your message||\n\n");
	for (int i = 0; i < a; i++)
	{
		printf("Plain Text[%d] : ", i + 1);
		scanf(" %[^\n]s", plainText[i]);
	}
	unsigned int n;
	printf("\n\nHow many character you want to shift : ");
	scanf("%u", &n);

	for (int i = 0; i < a; i++)
	{
		Cipher(plainText[i],n);
	}

	printf("\n=============================================\n");

	for (int i = 0; i < a; i++)
	{
		printf("Cipher Text[%d] : %s\n", i + 1,plainText[i]);
	}
	return 0;
}

void Cipher(char message[100],int n)
{
	for (int i = 0; i < strlen(message); i++)
	{
		if ((message[i] >= 'a' && message[i] <= 'z'))
		{
			message[i] += n;
			if (message[i] > 'z')
			{
				message[i] -= 26;
			}
		}
		else if((message[i] >= 'A' && message[i] <= 'Z'))
		{
			message[i] += n;
				if (message[i] > 'Z')
				{
					message[i] -= 26;
				}
		}
		else
		{
			continue;
		}
	}
}