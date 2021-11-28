#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL && parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
	{
		retorno = 0;
	}

	fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		parser_EmployeeFromBinary(pFile , pArrayListEmployee);
	}

	fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pNuevoEmpleado;
	FILE *ultimoIdTxt;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee != NULL)
	{
		pNuevoEmpleado = employee_new();
		if(pNuevoEmpleado != NULL)
		{
			if(GetString("Ingrese el nombre del empleado: ", nombre) == 0 &&
			   GetInt(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas (min. 1 / max 500).", "Error, por favor ingrese una cantidad válida (min. 1 / max 500).", 1, 500, 5) == 0 &&
			   GetInt(&sueldo, "Ingrese el sueldo del empleado (min. 100 / max 300000).", "Error, por favor ingrese un sueldo válido (min. 100 / max 300000).", 100, 300000, 5) == 0)
			{
				id = controller_getLastIdTxt("ultimoId.txt") + 1;

				ultimoIdTxt = fopen("ultimoId.txt", "w");
				if(ultimoIdTxt != NULL)
				{
					fprintf(ultimoIdTxt, "%d", id);

				}
				fclose(ultimoIdTxt);

				employee_setId(pNuevoEmpleado, id);
				employee_setNombre(pNuevoEmpleado, nombre);
				employee_setHorasTrabajadas(pNuevoEmpleado, horasTrabajadas);
				employee_setSueldo(pNuevoEmpleado, sueldo);

				ll_add(pArrayListEmployee, pNuevoEmpleado);
				retorno = 0;
				printf("\nSe ha cargado el siguiente empleado:");
				printf("\n|----------------------------------------------------------------|");
				printf("\n|%*s|%*s|%*s|%*s|", -12, "ID EMPLEADO", -20, "NOMBRE",-18, "HORAS TRABAJADAS",-11 , "SUELDO");
				printf("\n|----------------------------------------------------------------|");
				employee_print(pNuevoEmpleado);
				printf("\n|----------------------------------------------------------------|");
			}
		}
	}



    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pModificarEmpleado;
	int indice;
	char respuesta;
	int opcion;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		indice = controller_getIndex(pArrayListEmployee,"\nIngrese el ID del empleado a modificar: ","Error, por favor ingrese un ID válido: ",5);
		pModificarEmpleado = ll_get(pArrayListEmployee, indice);

		do
		{
			printf("Que dato del empleado desea modificar?\n");
			printf("1. Nombre.\n2.Horas Trabajadas.\n3.Sueldo.\n");
			if(GetInt(&opcion, "Ingrese una opción: ", "Error, por favor ingrese una opción válida: ", 1, 3, 5) == 0)
			{
				switch(opcion)
				{
					case 1:
						if(GetString("Ingrese el nombre del empleado: ", nombre) == 0)
						{
							employee_setNombre(pModificarEmpleado, nombre);
							retorno = 0;
						}
						break;
					case 2:
						if(GetInt(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas (min. 1 / max 500).", "Error, por favor ingrese una cantidad válida (min. 1 / max 500).", 1, 500, 5) == 0)
						{
							employee_setHorasTrabajadas(pModificarEmpleado, horasTrabajadas);
							retorno = 0;
						}
						break;
					case 3:
						if(GetInt(&sueldo, "Ingrese el sueldo del empleado (min. 100 / max 300000).", "Error, por favor ingrese un sueldo válido (min. 100 / max 300000).", 100, 300000, 5) == 0)
						{
							employee_setSueldo(pModificarEmpleado, sueldo);
							retorno = 0;
						}
						break;
				}
				GetYesNo("Desea seguir modificando datos del empleado? (s/n): ","Error, por favor ingrese una respuesta válida (s/n): ", &respuesta, 5);
			}
		}while(respuesta != 'n');

		if(retorno == 0)
		{
			ll_set(pArrayListEmployee, indice, pModificarEmpleado);
		}
	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pEliminarEmpleado;
	int indice;
	char respuesta;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		indice = controller_getIndex(pArrayListEmployee, "\nIngrese el id del empleado a eliminar: ", "Error, por favro ingrese un id de empleado válido: ", 5);
		if(indice != -1)
		{
			GetString("Esta seguro de que desea eliminar al empleado?: ", &respuesta);
			if(respuesta == 's')
			{
				pEliminarEmpleado = ll_get(pArrayListEmployee, indice);
				ll_remove(pArrayListEmployee, indice);
				employee_delete(pEliminarEmpleado);
				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee * auxEmpleado;
	int len;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		printf("\n|----------------------------------------------------------------|");
		printf("\n|%*s|%*s|%*s|%*s|", -12, "ID EMPLEADO", -20, "NOMBRE",-18, "HORAS TRABAJADAS",-11 , "SUELDO");
		printf("\n|----------------------------------------------------------------|");
		for(int i=0; i < len; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_print(auxEmpleado);
			retorno = 0;
		}
		printf("\n|----------------------------------------------------------------|");
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int subOpcion = 5;

	if(pArrayListEmployee != NULL)
	{
		do
		{
			printf("-----------------------------\n"
				   "Ordenar listado de empleados.\n"
				   "-----------------------------\n");
			printf("1. Ordenar empleados por Id.\n"
			   	   "2. Ordenar empleados por nombre.\n"
				   "3. Ordenar empleados por horas trabajadas.\n"
				   "4. Ordenar empleados por sueldo.\n"
				   "5. Salir.\n");
			if(GetInt(&opcion, "Ingrese una opción: ", "Error, por favor, ingrese una opción válida: ", 1, 5, 5) == 0)
			{
				switch(opcion)
				{
					case 1:
						printf("-------------------------\n"
							   "Ordenar empleados por Id.\n"
							   "-------------------------\n");
						printf("1. Ordenar de manera descendente.\n"
							   "2. Ordenar de manera ascendente.\n");
						if(GetInt(&subOpcion, "Ingrese una opción: ", "Error, por favor, ingrese una opción válida: ", 1, 2, 5) == 0)
						{
							subOpcion = subOpcion - 1;
							printf("\nOrdenando lista de empleados...\n");
							ll_sort(pArrayListEmployee, employee_compareId, subOpcion);
							retorno = 0;
						}
						break;
					case 2:
						printf("-----------------------------\n"
							   "Ordenar empleados por nombre.\n"
							   "-----------------------------\n");
						printf("1. Ordenar de manera descendente.\n"
							   "2. Ordenar de manera ascendente.\n");
						if(GetInt(&subOpcion, "Ingrese una opción: ", "Error, por favor, ingrese una opción válida: ", 1, 2, 5) == 0)
						{
							subOpcion = subOpcion - 1;
							printf("\nOrdenando lista de empleados...\n");
							ll_sort(pArrayListEmployee, employee_compareNombre, subOpcion);
							retorno = 0;
						}
						break;
					case 3:
						printf("---------------------------------------\n"
							   "Ordenar empleados por horas trabajadas.\n"
							   "---------------------------------------\n");
						printf("1. Ordenar de manera descendente.\n"
							   "2. Ordenar de manera ascendente.\n");
						if(GetInt(&subOpcion, "Ingrese una opción: ", "Error, por favor, ingrese una opción válida: ", 1, 2, 5) == 0)
						{
							subOpcion = subOpcion - 1;
							printf("\nOrdenando lista de empleados...\n");
							ll_sort(pArrayListEmployee, employee_compareHorasTrabajadas, subOpcion);
							retorno = 0;
						}
						break;
					case 4:
						printf("-----------------------------\n"
							   "Ordenar empleados por sueldo.\n"
							   "-----------------------------\n");
						printf("1. Ordenar de manera descendente.\n"
							   "2. Ordenar de manera ascendente.\n");
						if(GetInt(&subOpcion, "Ingrese una opción: ", "Error, por favor, ingrese una opción válida: ", 1, 2, 5) == 0)
						{
							subOpcion = subOpcion - 1;
							printf("\nOrdenando lista de empleados...\n");
							ll_sort(pArrayListEmployee, employee_compareSueldo, subOpcion);
							retorno = 0;
						}
						break;
				}
			}

		}while(opcion != 5);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL && pArrayListEmployee != NULL && parser_EmployeeToText(pFile, pArrayListEmployee) == 0)
	{
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListEmployee != NULL && parser_EmployeeToBinary(pFile, pArrayListEmployee) == 0)
	{
		retorno = 0;
	}
	fclose(pFile);

    return retorno;
}

int controller_getLastId(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *ultimoIdTxt;
	FILE *txtId;
	int mayorId = 0;

	ultimoIdTxt = fopen("ultimoId.txt", "r");
	if(ultimoIdTxt == NULL)
	{
		txtId = fopen(path, "r");
		mayorId = parser_EmployeeFromTextForId(txtId , pArrayListEmployee);
		fclose(txtId);
		ultimoIdTxt = fopen("ultimoId.txt", "w");
		if(ultimoIdTxt != NULL)
		{
			fprintf(ultimoIdTxt, "%d", mayorId);
		}
		fclose(ultimoIdTxt);
		retorno = 0;
	}

	return retorno;
}

int controller_getLastIdTxt(char* path)
{
	int retorno = -1;
	FILE *pFile;
	int id;

	pFile = fopen(path, "r");
	if(pFile != NULL)
	{
		fscanf(pFile, "%d", &id);
		fclose(pFile);
		printf("ULTIMO ID: %d", id);
		retorno = id;
	}
	return retorno;
}

int controller_getIndex(LinkedList* pArrayListEmployee, char message[], char errorMessage[], int retries)
{
	int retorno = -1;
	Employee *pAuxEmpleado;
	int ultimoId;
	int idModificar;
	int idAux;
	int len;


	ultimoId = controller_getLastIdTxt("ultimoId.txt");

	if(GetInt(&idModificar, message, errorMessage, 1, ultimoId, retries) == 0)
	{
		len = ll_len(pArrayListEmployee);
		for(int i=0; i < len; i++)
		{
			pAuxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &idAux);
			if(idAux == idModificar)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
