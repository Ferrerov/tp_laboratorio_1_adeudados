#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;  //Creacion de variable tipo LinkedList
    this = (LinkedList *) malloc(sizeof(LinkedList));  //Asignacion de memoria con malloc
    if(this != NULL) //Verifica que se haya podido asignar la memoria
    {
    	this->size = 0; //Inicializa el tamaño en 0
    	this->pFirstNode = NULL; //Incializa la direccion de memoria en NULL
    }
    return this; //Retorna la direccion de memoria del LinkedList
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size; //Le asigna a la variable a retornar, el tamaño de la LinkedList
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node *node = NULL;   //Creacion de un nuevo nodo
	int len;

	len = ll_len(this);
	if(this != NULL && nodeIndex > -1 && nodeIndex < len) //Verifica que LinkedList exista y que el indice sea valido
	{
		node = this->pFirstNode; //Obtiene la direccion de memoria adonde apunta la cabecera
		for(int i=0; i < nodeIndex; i++) //Recorre todos los nodos hasta llegar al indice indicado
		{
			node = node->pNextNode; //Cuando encuentra el elemento en el indice indicado asigna la direccion de memoria
		}
	}
    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node *newNode = NULL;
    Node *auxNode = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len) //Verifica que la LinkedList exista y que el indice sea valido
    {
    	newNode = (Node*)malloc(sizeof(Node)); //Asigna espacio en memoria al nuevo nodo
    	if(newNode != NULL)
    	{
    		if(nodeIndex != 0)
    		{
    			auxNode = getNode(this, nodeIndex - 1); //Busca el nodo anterior al indice especificado
    			newNode->pNextNode = auxNode->pNextNode; //Al nuevo nodo le asigna el pNextNode del nodo anterior
    			auxNode->pNextNode = newNode; //Al nodo anterior le asigna la direccion de memoria del nuevo nodo
    		}
    		else
    		{
    			newNode->pNextNode = this->pFirstNode; //Al pNextNode del nuevo nodo le asigna el pFirstNode de la cabecera
    			this->pFirstNode = newNode; //Al pFirstNode del nuevo nodo le asigna la direccion de memoria del nuevo nodo
    		}
    		newNode->pElement = pElement; //Le asigna el elemento al nueov nodo
    		this->size++; //Suma en uno el tamaño de la lista
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	index = ll_len(this);
    	addNode(this, index, pElement); //Añade un nuevo nodo con los parametros pasados al final de LinkedList
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node *pNode = NULL;
    int len;

	len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que LinkedList exista y que el indice sea valido
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement; //Retorna el elemento que esta en el indice especificado
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node *pNode = NULL;
    int len;

	len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que LinkedList exista y que el indice sea valido
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement; //Le asigna al pElement del nodo especificado un elemento pasado por parametro
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pNode = NULL;
    Node *auxNode = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que la LinkedList no sea nula y que el indice sea valido
    {
    	pNode = getNode(this, index); //Nodo a eliminar
    	if(pNode != NULL)
    	{
    		if(index > 0)
    		{
    			auxNode = getNode(this, index-1); //Obtiene el nodo anterior al nodo a eliminar
    			auxNode->pNextNode = pNode->pNextNode; //Asigna el pNextNode del nodo a eliminar, al nodo anterior
    		}
    		else
    		{
    			this->pFirstNode = pNode->pNextNode; //Le asigna a la cabecera el pNextNode del nodo a eliminar
    		}
    		free(pNode); //Libera en memoria el nodo eliminado
    		this->size--; //Resta en uno el tamaño del LinkedList
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    if(this != NULL && len > -1)
    {
    	for(int i=0; i < len; i++)  //Recorre todos los nodos hasta llegar al ultimo
    	{
    		ll_remove(this, i); //Libera el nodo del indice especificado
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0)  //Utilizando ll_clear elimina todos los nodos del LinkedList
    {
    	free(this); //Libera en memoria la LinkedList
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && len > -1)
    {
    	for(int i=0; i < len; i++) //Recorre todos los nodos hasta llegar a una coincidencia
    	{
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement) //Obtiene el pElement y lo compara con el pElement pasado por parametro
    		{
    			returnAux = i; //Si son iguales, sale del for y devuelve el indice
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->size > 0)
    	{
    		returnAux = 0; //Devuelve 0 porque hay por lo menos un nodo en la lista
    	}
    	else
    	{
    		returnAux = 1; //Devuelve 1 porque no hay nodos en la lista, por lo que esta vacia
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    if(this != NULL && index <= len && index > -1) //Verifica que la LinkedList no sea NULL y que el indice sea valido
    {
    	addNode(this, index, pElement);  //Utilizando la funcion addNode, agrega el nodo con los parametros pasados
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && index <= len && index > -1) //Verifica que la LinkedList no sea NULL y que el indice sea valido
    {
    	returnAux = ll_get(this, index); //Obtiene la direccion de memoria del pElement de la lista en el indice especificado
    	ll_remove(this, index);  //Elimina el nodo donde esta ese elemento
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && len > -1) //Verifica que la LinkedList exista y que tenga por lo menos un nodo
    {
    	returnAux = 0;
    	for(int i=0; i<len ;i++) //Recorre la lista hasta el ultimo elemento o hasta encontrar el elemento
    	{
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement) //Obtiene el pElement del indice especificado y lo compara con el pElement pasado por parametro
    		{
    			returnAux = 1;  //Si lo encuentra, significa que lo contiene, devuelve 1 y sale del for
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this2);

    if(this != NULL && this2 != NULL && len > -1) //Verifica que ambas LinkedList existan y que la segunda tenga por lo menos un nodo
    {
    	returnAux = 1;
    	for(int i=0; i<len; i++) //Recorre toda la lista hasta el ultimo nodo o hasta encontrar que un elemento no esta contenido
    	{
    		auxElement = ll_get(this2, i); //Obtiene el pElement del indice especificado en la segunda LinkedList para comparar
    		if(ll_contains(this, auxElement) != 1)  //Utilizando ll_contains verifica si el elemento se encuentra en la primera LinkedList
    		{
    			returnAux = 0; //Si no encuentra un elemento, no contiene todos los elementos, por lo que sale del for y devuelve 0
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && to <= len && to > from && from >= 0 && from < len) //Verifica que el LinkedList exista y que los rangos sean validos
    {
    	cloneArray = ll_newLinkedList(); //Crea la nueva LinkedList donde se van a copiar los elementos
    	if(cloneArray != NULL)
    	{
    		for(int i=from; i<to; i++) //Recorre el LinkedList hasta el ultimo nodo
    		{
    			auxElement = ll_get(this, i); //Obtiene el elemento de la LinkedList en el indice especificado
    			ll_add(cloneArray, auxElement); //Añade un nuevo nodo a la nueva lista, insertando el elemento
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
	void *auxElement;

	len = ll_len(this);
	if(this != NULL && len > -1) //Verifica que la LinkedList exista y que tenga por lo menos un nodo
	{
		cloneArray = ll_newLinkedList(); //Crea la nueva LinkedList donde se van a copiar los elementos
		if(cloneArray != NULL)
		{
			for(int i=0; i<len; i++) //Recorre la LinkedList hasta el ultimo elemento
			{
				auxElement = ll_get(this, i); //Obtiene el pElement de la LinkedList en el indice especificado
				ll_add(cloneArray, auxElement); //Añade un nuevo nodo a la lista, insertando el elemento
			}
		}
	}

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	int len;
	Node *auxNodeOne;
	Node *auxNodeTwo;
	void *auxElement;
	int result;

	len = ll_len(this);
	if(this != NULL && order >= 0 && order <=1 && pFunc != NULL) //Verifica que LinkedList y pFunc no sean NULL y que el orden sea 1 o 2
	{
		auxNodeOne = this->pFirstNode; //Inicializa el primer auxiliar en el primer nodo
		for(int i=0; i<len-1; i++) //Recorre LinkedList hasta la anteultima posicion para comparar
		{
			auxNodeTwo = auxNodeOne->pNextNode; //Asigna al segundo auxiliar la posicion siguiente al primer auxiliar
			for(int j=i+1; j<len; j++)  //Recorre LinkedList desde la posicion siguiente al primer elemento
			{
				result = pFunc(auxNodeOne->pElement, auxNodeTwo->pElement);  //Obtiene el resultado de la comparacion entre ambos elementos

				if((order == 0 && result < 0) || (order == 1 && result > 0 ))  //Verifica que se den las condiciones para el swap
				{
					auxElement = auxNodeOne->pElement;
					auxNodeOne->pElement = auxNodeTwo->pElement;
					auxNodeTwo->pElement = auxElement;
					returnAux = 0;
				}
				auxNodeTwo = auxNodeTwo->pNextNode; //Asigna al segundo auxiliar el nodo que le sigue
			}
			auxNodeOne = auxNodeOne->pNextNode; //Asigna al primer auxiliar el nodo que le sigue

		}
	}

    return returnAux;
}

