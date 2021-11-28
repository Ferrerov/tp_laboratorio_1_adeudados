#include "ArrayEmployees.h"

void initEmployees(eEmployee employee[], int len)
{
	for(int i = 0; i<len; i++)
	{
		employee[i].isEmpty = EMPTY;
	}
}

int addEmployee(eEmployee employee[], int len, int ultimoId, int* pIdEmployee)
{
	int validation = -1;

	for(int i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == EMPTY)
		{
			if(GetString( employee[i].name,"\nIngrese el nombre del empleado: ","Error, ingrese un nombre válido: ", 4) == 0 &&
			GetString( employee[i].lastName,"Ingrese el apellido del empleado: ","Error, ingrese un apellido válido: ", 4) == 0 &&
			GetFloat(&employee[i].salary, "Ingrese el salario del empleado: ", "\nError, ingrese un salario válido: ", 1, INT_MAX, 5) == 0 &&
			GetInt(&employee[i].sector, "Ingrese el sector del empleado: ", "\nError, ingrese un sector válido: ", 1, INT_MAX, 5) == 0)
			{
				employee[i].id = ultimoId + 1;
				*pIdEmployee = employee[i].id;
				employee[i].isEmpty = OCCUPIED;
				validation = 0;
				break;
			}
		}
	}
	return validation;
}

int findEmployeeById(eEmployee employee[], int len, int retries, int* index)
{
	int validation = -1;
	int idFind;

	do
	{
		retries--;

		GetInt(&idFind, "\nIngrese el ID del empleado: ", "\nError, ID fuera de rango. Ingrese nuevamente: ", 1, len, 5);

		for(int i = 0; i < len; i++)
		{
			if(employee[i].isEmpty == OCCUPIED &&  employee[i].id == idFind)
			{
				*index = i;
				retries = 0;
				validation = 0;
				break;
			}
		}
		if(validation != 0)
		{
			printf("ID no encontrado.");
		}
	}while(retries > 0);

	return validation;
}

int modifyEmployee(eEmployee employee[], int len, int retries)
{
	int validation = -1;
	int index;
	int response;

		if(findEmployeeById(employee, len, retries, &index) == 0)
		{
			printf("\nQue dato desea modificar?"
					"\n1. Nombre "
					"\n2. Apellido "
					"\n3. Salario "
					"\n4. Sector");
			GetInt(&response, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 11, INT_MAX);

			switch(response)
			{
			case 1:
				GetString( employee[index].name,"\nIngrese el nombre del empleado: ","Error, ingrese un nombre válido: ", 4);
				validation = 0;
				break;
			case 2:
				GetString( employee[index].lastName,"\nIngrese el apellido del empleado: ","Error, ingrese un apellido válido: ", 4);
				validation = 0;
				break;
			case 3:
				if(GetFloat(&employee[index].salary, "\nIngrese el salario del empleado: ", "\nError, ingrese un salario válido: ", 1, INT_MAX, 5) == 0)
				{
					validation = 0;
				}
				break;
			case 4:
				if(GetInt(&employee[index].sector, "\nIngrese el sector del empleado: ", "\nError, ingrese un sector válido: ", 1, INT_MAX, 5) == 0)
				{
					validation = 0;
				}
				break;
			}
		}
	return validation;
}

int removeEmploye(eEmployee employee[], int len, int retries)
{
	int validation = -1;
	int index;
	char response;

	if(findEmployeeById(employee, len, retries, &index) ==0)
	{
		if(GetYesNo("\nEsta seguro que desea dar de baja al cliente? (s/n): ", "\nError, ingrese una opción válida: ", &response, 4) == 0 &&
				response == 's')
		{
			employee[index].isEmpty = EMPTY;
			validation = 0;
		}
	}
	return validation;
}

int organizeByLastName(eEmployee employee[], int len)
{
	int validation = -1;
	eEmployee aux;

	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(employee[i].sector < employee[j].sector)
			{
				aux = employee[i];
				employee[i] = employee[j];
				employee[j] = aux;
				validation = 0;
			}
			else
			{
				if(employee[i].sector == employee[j].sector && strcmp(employee[i].lastName, employee[j].lastName) > 0)
				{
					aux = employee[i];
					employee[i] = employee[j];
					employee[j] = aux;
					validation = 0;
				}
			}
		}
	}
	return validation;
}

int printEmployee(eEmployee employee)
{
	int validation = -1;

	printf("\n|%*d|%*s|%*s|%*.2f|%*d|", -5, employee.id, -20, employee.name,-20, employee.lastName,-11 , employee.salary, -6, employee.sector);
	validation = 0;

	return validation;
}

int printEmployeeList(eEmployee employee[], int len)
{
	int validation = -1;

	for(int i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCCUPIED)
		{
			printf("\n--------------------------------------------------------------------");
			printf("\n|%*s|%*s|%*s|%*s|%*s|", -5, "ID", -20, "NOMBRE",-20, "APELLIDO",-11 , "SALARIO",-6, "SECTOR");
			printf("\n--------------------------------------------------------------------");
			printEmployee(employee[i]);
			printf("\n|------------------------------------------------------------------|");
			validation = 0;
		}
	}

	return validation;
}

int salaryAverage(eEmployee employee[], int len, float* pAverage, float* pTotal, int* pCounter)
{
	int validation = -1;
	float total = 0;
	float average;
	int counter = 0;
	int moreThanAverageCounter = 0;

	for(int i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCCUPIED)
		{
			total = total + employee[i].salary;
			counter++;
			validation = 0;
		}
	}

	average = total / counter;
	*pTotal = total;

	for(int j = 0; j < len; j++)
	{
		if(employee[j].isEmpty == OCCUPIED && employee[j].salary > average)
		{
			total = total + employee[j].salary;
			moreThanAverageCounter++;
			validation = 0;
		}
	}

	*pCounter = moreThanAverageCounter;
	*pAverage = average;

	return validation;
}

int salaryAverageList(eEmployee employee[], int len)
{
	int validation = -1;
	float average;
	float total;
	int counter;

	if(salaryAverage(employee, len, &average, &total, &counter) == 0)
	{
		printf("\nEL total de los salarios es de: %.2f", total);
		printf("\nEL promedio de los salarios es de: %.2f", average);
		printf("\nLa cantidad de empleados que superan el salario promedio es de: %d", counter);
	}

	return validation;
}
