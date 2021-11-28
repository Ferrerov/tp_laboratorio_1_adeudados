#include "Input.h"

int OnlyStringValidation(char string[])
{
	int i = 0;
	int validation = 0;

	while (string[i] != '\0')
	{
		if ((isdigit(string[i])) != 0)
		{
			validation = -1;
			break;
		}
		i++;
	}

	return validation;
}

int GetString(char string[], char message[], char errorMessage[], int retries)
{
	int validation = -1;
	printf("%s", message);
	fflush(stdin);
	gets(string);

	if(OnlyStringValidation(string) != 0 || !(strlen(string) > 0))
	{
		while(retries > 0)
		{
			retries--;
			printf("%s", errorMessage);
			fflush(stdin);
			gets(string);
			if(strlen(string) > 0 && OnlyStringValidation(string) == 0)
			{
				validation = 0;
				break;
			}
		}
	}
	else
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
	char string[20];

	printf("%s", message);
	scanf("%s", string);

	while(retries > 0)
	{
		retries--;
		if (FloatStringValidation(&number, string) == 0)
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
		scanf("%s", string);
	}
	return validation;
}

int FloatStringValidation(float* result, char string[])
{
	int validation = -1;
	//char string[20];

	//scanf("%s", string);
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

int GetCuit(char string[], char message[], char errorMessage[], int retries)
{
	int validation = -1;
	int len;
	char stringAux[15];
	int j = 0;

	printf("%s", message);
	fflush(stdin);
	gets(string);
	len = strlen(string); //20-43261392-6

	while(retries > 0 && !(len == 11))
	{
		retries--;
		if(len == 13 && string[2] == '-' && string[11] == '-')
		{
			for(int i = 0; i<len; i++)
			{
				if(string[i] != '-')
				{
					stringAux[j] = string[i];
					j++;
				}
			}
			stringAux[j] = '\0';
			strcpy(string, stringAux);
			len = strlen(string);
			validation = 0;
			break;
		}
		printf("%s", errorMessage);
		fflush(stdin);
		gets(string);
		len = strlen(string);
	}
	if(len == 11)
	{
		validation = 0;
	}

	return validation;
}

