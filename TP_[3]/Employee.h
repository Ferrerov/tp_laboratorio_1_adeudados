#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// \fn Employee employee_new*()
/// \brief constructor de la estructura Employee
/// \return devuelve la direccion de memoria de la nueva estructura
Employee* employee_new();

/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief constructor de la estructura Employee con parametros especificos
/// \param idStr cadena de caracteres de id
/// \param nombreStr cadena de caracteres de nombre
/// \param horasTrabajadasStr cadena de caracteres de horas trabajadas
/// \param sueldoStr cadena de caracteres de sueldo
/// \return
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/// \fn void employee_delete(Employee*)
/// \brief elimina una estructura Employee especifica
/// \param this estructura a elminar
void employee_delete(Employee* this);

/// \fn int employee_setId(Employee*, int)
/// \brief asigna el id pasado como parametro a la estructura
/// \param this estructura Employee a modificar
/// \param id id a asingar
/// \return devuelve 0 si pudo asignarlo y -1 si no se pudo asignar
int employee_setId(Employee* this,int id);

/// \fn int employee_getId(Employee*, int*)
/// \brief devuelve como puntero el id de una estructura
/// \param this estructura Employee a obtener el id
/// \param id id del empleado de valor entero
/// \return devuelve 0 si se obtuvo el dato y -1 si no se pudo obtener
int employee_getId(Employee* this,int* id);

/// \fn int employee_setNombre(Employee*, char*)
/// \brief asigna el nombre pasado como parametro a la estructura
/// \param this estructura Employee a modificar
/// \param nombre nombre del empleado a asignar
/// \return devuelve 0 si pudo asignarlo y -1 si no se pudo asignar
int employee_setNombre(Employee* this,char* nombre);

/// \fn int employee_getNombre(Employee*, char*)
/// \brief devuelve como puntero el nombre asignado en la estructura Employee especifica
/// \param this estructura Employee a obtener el nombre
/// \param nombre nombre obtenido de la estructura
/// \return devuelve 0 si se obtuvo el dato y -1 si no se pudo obtener
int employee_getNombre(Employee* this,char* nombre);

/// \fn int employee_setHorasTrabajadas(Employee*, int)
/// \brief asigna las horas pasadas como parametro a la estructura
/// \param this estructura Employee a modificar
/// \param horasTrabajadas horas trabajadas del empleado a asignar
/// \return devuelve 0 si pudo asignarlo y -1 si no se pudo asignar
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// \fn int employee_getHorasTrabajadas(Employee*, int*)
/// \brief devuelve como puntero las horas trabajadas de un empleado
/// \param this estructura Employee a obtener las horas trabajadas
/// \param horasTrabajadas horas trabajadas del empleado
/// \return devuelve 0 si se obtuvo el dato y -1 si no se pudo obtener
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// \fn int employee_setSueldo(Employee*, int)
/// \brief devuelve como puntero el sueldo de un empleado
/// \param this estructura Employee a modificar
/// \param sueldo sueldo del empleado a asignar
/// \return devuelve 0 si pudo asignarlo y -1 si no se pudo asignar
int employee_setSueldo(Employee* this,int sueldo);

/// \fn int employee_getSueldo(Employee*, int*)
/// \brief devuelve como puntero el sueldo de un empleado
/// \param this estructura Employee a obtener el sueldo
/// \param sueldo sueldo del empleado
/// \return devuelve 0 si se obtuvo el dato y -1 si no se pudo obtener
int employee_getSueldo(Employee* this,int* sueldo);

/// \fn int employee_print(Employee*)
/// \brief imprime todos los datos de un empleado
/// \param this estructura del empleado a imprimir
/// \return devuelve 0 si pudo imprimir el empleado y -1 si no existe el empleado
int employee_print(Employee* this);

/// \fn int employee_compareId(void*, void*)
/// \brief compara el id de dos empleados
/// \param empleadoUno
/// \param empleadoDos
/// \return devuelve 0 si los id son iguales,
/// 		1 si el id del primer empleado es menor al del segundo
/// 		y -1 si el id del primer empleado es mayor al del segundo
int employee_compareId( void *empleadoUno, void *empleadoDos);

/// \fn int employee_compareNombre(void*, void*)
/// \brief compara los nombres de dos empleados
/// \param empleadoUno
/// \param empleadoDos
/// \return devuelve 0 si los nombres son iguales,
/// 		un valor mayor a 0 si el nombre del primer empleado es menor al del segundo empleado
/// 		y un valor menor a 0 si el nombre del primer empleado es mayor al del segundo empleado
int employee_compareNombre( void *empleadoUno, void *empleadoDos);

/// \fn int employee_compareHorasTrabajadas(void*, void*)
/// \brief compara las horas trabajadas de dos empleados
/// \param empleadoUno
/// \param empleadoDos
/// \return devuelve 0 si las horas trabajadas son iguales,
/// 		1 si las horas trabajadas del primer empleado son menos que las del segundo
/// 		y -1 si las horas trabajadas del primer empleado son mas que las del segundo
int employee_compareHorasTrabajadas( void *empleadoUno, void *empleadoDos);

/// \fn int employee_compareSueldo(void*, void*)
/// \brief compara el sueldo de dos empleados
/// \param empleadoUno
/// \param empleadoDos
/// \return devuelve 0 si los sueldos son iguales,
/// 		1 si el sueldo del primer empleado es menor que el del segundo
/// 		y -1 si el sueldo del primer empleado es mayor que el del segundo
int employee_compareSueldo( void *empleadoUno, void *empleadoDos);

#endif // employee_H_INCLUDED
