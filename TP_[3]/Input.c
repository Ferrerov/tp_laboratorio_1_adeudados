#include "Input.h"

int GetString(char message[],char string[])
{
	int validation = -1;
	printf("%s", message);
	fflush(stdin);
	gets(string);
	if(string != NULL)
	{
		validation = 0;
	}

	return validation;
}

int GetYesNo(char message[], char errorMessage[], char* pAnswer, int retries)
{
	int validation = -1;
	char answer;

	printf("%s", message);
	fflush(stdin);
	scanf("%c", &answer);
	while(!(answer == 's' || answer == 'n') && retries > 0)
	{
		retries--;
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%c", &answer);
	}
	if(answer == 's' || answer == 'n')
	{
		*pAnswer = answer;
		validation = 0;
	}

	return validation;
}

int GetInt(int* pResult, char message[], char errorMessage[], int min, int max, int retries)
{
	int number;
	int validation = -1;

	printf("%s", message);
	while(retries > 0)
	{
		retries--;
		if (StringValidation(&number) == 0)
		{
			if (number >= min && number <= max)
			{
				*pResult = number;
				validation = 0;
				break;
			}
		}
		printf("%s", errorMessage);
	}

	return validation;
}

int GetFloat(float* pResult, char message[], char errorMessage[], int min, int max, int retries)
{
	float number;
	int validation = -1;

	printf("%s", message);

	while(retries > 0)
	{
		retries--;
		if (FloatStringValidation(&number) == 0)
		{
			if (number >= min && number <= max)
			{
				*pResult = number;
				validation = 0;
				break;
			}
			break;
		}
		printf("%s", errorMessage);
	}
	return validation;
}

int FloatStringValidation(float* result)
{
	int validation = -1;
	char string[20];

	scanf("%s", string);

	if(FloatNumberValidation(string) == 0)
	{
		*result = atof(string);
		validation = 0;
	}
	return validation;
}

int FloatNumberValidation(char string[])
{
	int i = 0;
	int validation = 0;
	int flagDot = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '.' && flagDot == 0)
		{
			i++;
			flagDot = 1;
			if ((isdigit(string[i])) == 0)
			{
				validation = -1;
				break;
			}
			i++;
		}
		else
		{
			if ((isdigit(string[i])) == 0)
			{
				validation = -1;
				break;
			}
			i++;
		}
	}
	return validation;
}

int StringValidation(int* pResult)
{
	int validation = -1;
	char string[20];

	scanf("%s", string);

		if(NumberValidation(string) == 0)
		{
		*pResult = atoi(string);
		validation = 0;
		}

	return validation;
}
int NumberValidation(char string[])
{
	int i = 0;
	int validation = 0;

	while (string[i] != '\0')
	{
		if ((isdigit(string[i])) == 0)
		{
			validation = -1;
			break;
		}
		i++;
	}

	return validation;
}

