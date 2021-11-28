#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief abre el archivo, llama al parser para cargarlo y luego cierra el archivo
/// \param path archivo .txt a cargar
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo cargar el archivo .txt y -1 si no se pudo
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief abre el archivo, llama al parser para cargarlo y luego cierra el archivo
/// \param path archivo .bin a cargar
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo cargar el archivo .bin y -1 si no se pudo
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_addEmployee(LinkedList*)
/// \brief permite al usuario ingresar un nuevo empleado, utilizano los setters
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo cargar el empleado y -1 si no se pudo
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_editEmployee(LinkedList*)
/// \brief permite al usuario editar uno o mas datos de un empleado
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo editar el empleado y -1 si no se pudo
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_removeEmployee(LinkedList*)
/// \brief permite al usuario eliminar un empleado
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo eliminar el empleado y -1 si no se pudo
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_ListEmployee(LinkedList*)
/// \brief imprime una lista de todos los empleados cargados
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo imprimir al menos un empleado y -1 si no se pudo
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_sortEmployee(LinkedList*)
/// \brief ordena la lista de empleados bajo un criterio especifico
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo ordenar y -1 si no se pudo
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief abre el archivo .txt, llama al parser para guardar los datos y cierra el archivo
/// \param path archivo .txt a manipular
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo guardar los datos y -1 si no se pudo
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief abre el archivo .bin, llama al parser para guardar los datos y cierra el archivo
/// \param path archivo .bin a manipular
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se pudo guardar los datos y -1 si no se pudo
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_getLastId(char*, LinkedList*)
/// \brief lectura fantasma para obtener un id a partir de un .txt
/// \param path archivo .txt donde se aloja el ultimo id
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \return devuelve 0 si se obtuvo el ultimo id y -1 si no se pudo
int controller_getLastId(char* path, LinkedList* pArrayListEmployee);

/// \fn int controller_getLastIdTxt(char*)
/// \brief abre el archivo .txt, lee el ultimo id y lo cierra
/// \param path archivo .txt donde se aloja el ultimo id
/// \return devuelve el id obtenido del .txt y -1 si no se obtuvo ningun id
int controller_getLastIdTxt(char* path);

/// \fn int controller_getIndex(LinkedList*, char[], char[], int)
/// \brief obtiene el indice de un empleado segun su id
/// \param pArrayListEmployee puntero a la linkedlist con los empleados
/// \param retries numero de intentos
/// \return devuelve el indice del empleado con su id y -1 si no se encontro el empleado
int controller_getIndex(LinkedList* pArrayListEmployee, char message[], char errorMessage[], int retries);


