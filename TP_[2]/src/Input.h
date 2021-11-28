#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

int OnlyStringValidation(char string[]);

/// @fn void getString(char[], char[], int)
/// @brief solicita al usuario una cadena de caracteres
/// @param message
/// @param string
/// @param tam
int GetString(char string[], char message[], char errorMessage[], int retries);

/// @fn int getYesNo(char[], char[], char*, int)
/// @brief funcion para obtener respuesta (s/n)
/// @param message mensaje que pide el caracter
/// @param errorMessage mensaje en caso de que el caracter sea erroneo
/// @param pAnswer devuelve como puntero el caracter respuesta
/// @param retries cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se obtuvo una respuesta valida
int GetYesNo(char message[], char errorMessage[], char* pAnswer, int retries);

/// @fn int getNumber(int*, char[], char[], int, int, int)
/// @brief solicita al usuario un numero entero
/// @param pResult devuelve como puntero el numero solicitado
/// @param message mensaje que pide el numero
/// @param errorMessage mensaje en caso de que el numero sea erroneo
/// @param min numero minimo a pedir
/// @param max numero maximo a pedir
/// @param retries cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int GetInt(int* pResult, char message[], char errorMessage[], int min, int max, int retries);

/// @fn int getFloat(float*, char[], char[], int, int, int)
/// @brief solicita al usuario un numero flotante
/// @param pResult devuelve como puntero el numero solicitado
/// @param message mensaje que pide el numero
/// @param errorMessage mensaje en caso de que el numero sea erroneo
/// @param min numero minimo a pedir
/// @param max numero maximo a pedir
/// @param retries cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int GetFloat(float* pResult, char message[], char errorMessage[], int min, int max, int retries);

/// @fn int FloatStringValidation(float*)
/// @brief  si la cadena de caracteres no tiene digitos, lo convierte a flotante
/// @param result devuelve el numero flotante
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int FloatStringValidation(float* result, char string[]);

/// @fn int FloatNumberValidation(char[])
/// @brief  verifica si la cadena de caracteres tiene algun digito invalido
/// @param string devuelve la cadena de caracteres
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int FloatNumberValidation(char string[]);

/// @fn int stringValidation(int*)
/// @brief  si la cadena de caracteres no tiene digitos, lo convierte a entero
/// @param pResult devuelve el numero entero
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int StringValidation(int* pResult);

/// @fn int numberValidation(char[])
/// @brief  verifica si la cadena de caracteres tiene algun digito invalido
/// @param string devuelve la cadena de caracteres
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int NumberValidation(char string[]);

int GetCuit(char string[], char message[], char errorMessage[], int retries);

#endif /* INPUT_H_ */
