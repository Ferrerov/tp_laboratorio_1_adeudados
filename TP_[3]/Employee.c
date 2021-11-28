#include "Employee.h"

Employee* employee_new()
{
	Employee* NuevoEmpleado = NULL;
	NuevoEmpleado = (Employee*) malloc(sizeof(Employee));

	if(NuevoEmpleado != NULL)
	{
		NuevoEmpleado->id = 0;/////////////CORREGIR
		strcpy(NuevoEmpleado->nombre, " ");
		NuevoEmpleado->horasTrabajadas = 0;
		NuevoEmpleado->sueldo = 0;
	}

	return NuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr) //CORREGIR
{
	Employee* pNuevoEmpleado = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL &&
	   NumberValidation(idStr) == 0 && NumberValidation(horasTrabajadasStr) == 0 && NumberValidation(sueldoStr) == 0)
	{
		pNuevoEmpleado = employee_new();

		if(pNuevoEmpleado != NULL)
		{
			employee_setId(pNuevoEmpleado, atoi(idStr));
			employee_setNombre(pNuevoEmpleado, nombreStr);
			employee_setHorasTrabajadas(pNuevoEmpleado, atoi(horasTrabajadasStr));
			employee_setSueldo(pNuevoEmpleado, atoi(sueldoStr));
		}
	}


	return pNuevoEmpleado;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->nombre , nombre);
		retorno = 0;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre , this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_print(Employee* this)
{
	int retorno = -1;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(this != NULL)
	{
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		employee_getSueldo(this, &sueldo);

		printf("\n|%*d|%*s|%*d|%*d|", -12, id, -20, nombre,-18, horasTrabajadas,-11 , sueldo);
		retorno = 0;
	}

	return retorno;
}

int employee_compareId( void *empleadoUno, void *empleadoDos)
{
	int retorno = 0;
	Employee *auxEmpleadoUno;
	Employee *auxEmpleadoDos;
	int idUno;
	int idDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		auxEmpleadoUno = (Employee*)empleadoUno;
		auxEmpleadoDos = (Employee*)empleadoDos;
		employee_getId(auxEmpleadoUno, &idUno);
		employee_getId(auxEmpleadoDos, &idDos);
		if(idUno < idDos)
		{
			retorno = 1;
		}
		else
		{
			if(idUno > idDos)
			{
				retorno = -1;
			}
		}
	}


	return retorno;
}
int employee_compareNombre( void *empleadoUno, void *empleadoDos)
{
	int retorno = -1;
	Employee *auxEmpleadoUno;
	Employee *auxEmpleadoDos;
	char nombreUno[128];
	char nombreDos[128];

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		auxEmpleadoUno = (Employee*)empleadoUno;
		auxEmpleadoDos = (Employee*)empleadoDos;
		employee_getNombre(auxEmpleadoUno, nombreUno);
		employee_getNombre(auxEmpleadoDos, nombreDos);
		retorno = strcmp(nombreUno, nombreDos);
	}

	return retorno;
}
int employee_compareHorasTrabajadas( void *empleadoUno, void *empleadoDos)
{
	int retorno = 0;
	Employee *auxEmpleadoUno;
	Employee *auxEmpleadoDos;
	int horasTrabajadasUno;
	int horasTrabajadasDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		auxEmpleadoUno = (Employee*)empleadoUno;
		auxEmpleadoDos = (Employee*)empleadoDos;
		employee_getHorasTrabajadas(auxEmpleadoUno, &horasTrabajadasUno);
		employee_getHorasTrabajadas(auxEmpleadoDos, &horasTrabajadasDos);
		if(horasTrabajadasUno < horasTrabajadasDos)
		{
			retorno = 1;
		}
		else
		{
			if(horasTrabajadasUno > horasTrabajadasDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
int employee_compareSueldo( void *empleadoUno, void *empleadoDos)
{
	int retorno = 0;
	Employee *auxEmpleadoUno;
	Employee *auxEmpleadoDos;
	int sueldoUno;
	int sueldoDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		auxEmpleadoUno = (Employee*)empleadoUno;
		auxEmpleadoDos = (Employee*)empleadoDos;
		employee_getSueldo(auxEmpleadoUno, &sueldoUno);
		employee_getSueldo(auxEmpleadoDos, &sueldoDos);
		if(sueldoUno < sueldoDos)
		{
			retorno = 1;
		}
		else
		{
			if(sueldoUno > sueldoDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}


