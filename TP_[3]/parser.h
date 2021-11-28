#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/// \fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// \brief lee los datos del .txt y los carga en memoria
/// \param pFile puntero al archivo .txt
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return retorna 0 si se pudo añadir al menos un empleado al linked list y -1 si no se pudo
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// \brief lee los datos del .bin y los carga en memoria
/// \param pFile puntero al archivo .bin
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return retorna 0 si se pudo añadir al menos un empleado al linked list y -1 si no se pudo
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_EmployeeToText(FILE*, LinkedList*)
/// \brief escribe en el .txt los datos en memoria
/// \param pFile puntero al archivo .txt
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return retorna 0 si se pudo escribir al menos un empleado en el .txt y -1 si no se pudo
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_EmployeeToBinary(FILE*, LinkedList*)
/// \brief  escribe en el .bin los datos en memoria
/// \param pFile puntero al archivo .bin
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return retorna 0 si se pudo escribir al menos un empleado en el .bin y -1 si no se pudo
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_EmployeeFromTextForId(FILE*, LinkedList*)
/// \brief realiza una lectura fantasma del .txt para obtener un ultimo id, pero sin cargar datos
/// \param pFile puntero al archivo .txt
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return retorna el id maximo del .txt y -1 si no hay datos a leer
int parser_EmployeeFromTextForId(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
