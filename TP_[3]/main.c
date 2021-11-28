#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    controller_getLastId("data.csv", listaEmpleados);

    do{
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
        		"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
        		"3. Alta de empleado.\n"
        		"4. Modificar datos de empleado.\n"
        		"5. Baja de empleado.\n"
        		"6. Listar empleados.\n"
        		"7. Ordenar empleados.\n"
        		"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
        		"9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
        		"10. Salir.\n");

    	GetInt(&option, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 10, 5);

        switch(option)
        {
            case 1:
            	printf("Usted ha seleccionado la opción 1: Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
                if(controller_loadFromText("data.csv",listaEmpleados) == 0)
                {
                	printf("Se han cargado los datos desde el .txt exitosamente.\n");
                }
                else
                {
                	printf("No se han podido cargar los datos desde el .txt.\n");
                }
                break;
            case 2:
            	printf("Usted ha seleccionado la opción 2: Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
            	if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
            	{
					printf("Se han cargado los datos desde el .bin exitosamente.\n");
				}
				else
				{
					printf("No se han podido cargar los datos desde el .bin.\n");
				}
                break;
            case 3:
            	printf("Usted ha seleccionado la opción 3: Alta de empleado.\n");
            	if(controller_addEmployee(listaEmpleados) == 0)
            	{
					printf("\nSe ha añadido el empleado.\n");
				}
				else
				{
					printf("No se ha podido añadir el empleado.\n");
				}
                break;
            case 4:
            	printf("Usted ha seleccionado la opción 4: Modificar datos de empleado.\n");
            	if(controller_editEmployee(listaEmpleados) == 0)
				{
					printf("Se ha editado el empleado.\n");
				}
				else
				{
					printf("No se ha podido editar el empleado.\n");
				}
                break;
            case 5:
            	printf("Usted ha seleccionado la opción 5: Baja de empleado.\n");
            	if(controller_removeEmployee(listaEmpleados) == 0)
				{
					printf("Se ha eliminado el empleado.\n");
				}
				else
				{
					printf("No se ha podido eliminar el empleado.\n");
				}
                break;
            case 6:
            	printf("Usted ha seleccionado la opción 6: Listar empleados.\n");
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	printf("Usted ha seleccionado la opción 7: Ordenar empleados.\n");
            	if(controller_sortEmployee(listaEmpleados) == 0)
            	{
            		printf("Se han reordenado la lista de empleados.\n");
            	}
            	else
            	{
            		printf("No se ha podido ordenar la lista de empleados.\n");
            	}
                break;
            case 8:
            	printf("Usted ha seleccionado la opción 8: Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
            	if(controller_saveAsText("data.csv" , listaEmpleados) == 0)
				{
					printf("Se ha guardado el listado de empleados.\n");
				}
				else
				{
					printf("No se ha podido guardar el listado de empleados.\n");
				}
                break;
            case 9:
            	printf("Usted ha seleccionado la opción 9: Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
            	if(controller_saveAsBinary("data.bin" , listaEmpleados) == 0)
				{
					printf("Se ha guardado el listado de empleados.\n");
				}
				else
				{
					printf("No se ha podido guardar el listado de empleados.\n");
				}
                break;
        }
    }while(option != 10);
    return 0;
}

