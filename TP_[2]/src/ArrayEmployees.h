#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "Input.h"

#define EMPTY 0
#define OCCUPIED 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

void initEmployees(eEmployee employee[], int len);

int addEmployee(eEmployee employee[], int len, int ultimoId, int* pIdEmployee);

int findEmployeeById(eEmployee employee[], int len, int retries, int* index);

int modifyEmployee(eEmployee[], int len, int retries);

int removeEmploye(eEmployee employee[], int len, int retries);

int organizeByLastName(eEmployee employee[], int len);

int printEmployee(eEmployee employee);

int printEmployeeList(eEmployee employee[], int len);

int salaryAverage(eEmployee employee[], int len, float* pAverage, float* pTotal, int* pCounter);

int salaryAverageList(eEmployee employee[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
