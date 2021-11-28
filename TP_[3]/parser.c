#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int cantidad;
	char buffer1[20];
	char buffer2[128];
	char buffer3[20];
	char buffer4[20];

	Employee* pNuevoEmpleado;
	//FILE* ultimoIdTxt;

	if(pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);

		while( !feof(pFile))
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);
			if(cantidad < 4)
			{
				break;
			}

			pNuevoEmpleado = employee_newParametros(buffer1, buffer2, buffer3, buffer4);
			if(pNuevoEmpleado != NULL)
			{
				ll_add(pArrayListEmployee, pNuevoEmpleado);
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int cantidad;
	Employee *auxEmpleado;
	//Employee *pEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		do
		{
			auxEmpleado = employee_new();
			if(auxEmpleado != NULL)
			{
				cantidad = fread(auxEmpleado, sizeof(Employee), 1, pFile);
				if(cantidad == 1)
				{
					ll_add(pArrayListEmployee, auxEmpleado);
					retorno = 0;
				}
				else
				{
					employee_delete(auxEmpleado);
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *auxEmpleado;
	int len;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0; i<len; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i); ///auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(auxEmpleado != NULL)
			{
				employee_getId(auxEmpleado, &id);
				employee_getNombre(auxEmpleado, nombre);
				employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
				employee_getSueldo(auxEmpleado, &sueldo);

				fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *auxEmpleado;
	int len;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(int i=0; i<len; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			fwrite(auxEmpleado, sizeof(Employee), 1, pFile);
			retorno = 0;
		}
	}

	return retorno;
}

int parser_EmployeeFromTextForId(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer1[20];
	char buffer2[128];
	char buffer3[20];
	char buffer4[20];
	int flag = -1;
	int max;
	int aux;

	if(pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);

		while( !feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);
			if(flag != 0)
			{
				max = atoi(buffer1);
				flag = 0;
			}
			aux = atoi(buffer1);
			if(aux > max)
			{
				max = aux;
			}
		}
		retorno = max;
	}
    return retorno;
}
