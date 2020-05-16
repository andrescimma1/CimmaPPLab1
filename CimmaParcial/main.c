#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOT 10
#define TAMTRA 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
}eNotebook;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
}eTrabajo;

void inicializarNotebooks(eNotebook arrayNotebooks[], int tamnot);
int buscarLibre(eNotebook arrayNotebooks[], int tamnot);
void mostrarMarcas(eMarca arrayMarcas[], int tammar);
void mostrarTipos(eTipo arrayTipos[], int tamtip);
void altaNotebook(eNotebook arrayNotebooks[], int tamnot, eMarca arrayMarcas[], int tammar, eTipo arrayTipos[], int tamtip);
void listarNotebook(eNotebook pNotebook, eMarca listmarcas[], int lenmarcas, eTipo listtipos[], int lentipos);
int listarNotebooks(eNotebook listnotebooks[], int len, eMarca listmarcas[], int lenmarcas, eTipo listtipos[], int lentipos);


int main()
{
    char seguir = 's';

    eMarca arrayMarcas[] = {
                           {1000, "Compaq"},
                           {1001, "Asus"},
                           {1002, "Acer"},
                           {1003, "HP"}
                           };
    eTipo arrayTipos[] = {
                            {5000, "Gamer"},
                            {5001, "Disenio"},
                            {5002, "Ultrabook"},
                            {5003, "Normalita"}
                            };

    eServicio arrayServicios[] = {
                                 {20000, "Bateria", 250},
                                 {20001, "Antivirus", 300},
                                 {20002, "Actualizacion", 400},
                                 {20003, "Fuente", 600}
                                 };
    eNotebook arrayNotebooks[TAMNOT];
    inicializarNotebooks(arrayNotebooks, TAMNOT);
    //eTrabajo arrayTrabajos[TAMTRA];
    //inicializarTrabajos(arrayTrabajos, TAMTRA);

    return 0;
}



/** \brief Inicializa las id de las notebooks
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarNotebooks(eNotebook arrayNotebooks[], int tamnot)
{
    int i;
    for(i=0; i<tamnot; i++)
    {
        arrayNotebooks[i].id = 0;
    }
}



/** \brief Busca un espacio libre
 *
 * \param int i;
 * \param int indice = -1;
 * \return indice;
 *
 */
int buscarLibre(eNotebook arrayNotebooks[], int tamnot)
{
    int i;
    int indice = -1;

    for(i=0; i<tamnot; i++)
    {
        if(arrayNotebooks[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



/** \brief Recorre las marcas y las lista
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void mostrarMarcas(eMarca arrayMarcas[], int tammar)
{
    int i;

    for(i=0; i<tammar; i++)
    {
        printf("%d %s\n", arrayMarcas[i].id, arrayMarcas[i].descripcion);
    }
    printf("\n");
}



/** \brief Recorre los tipos de notebooks y los lista
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void mostrarTipos(eTipo arrayTipos[], int tamtip)
{
    int i;

    for(i=0; i<tamtip; i++)
    {
        printf("%d %s\n", arrayTipos[i].id, arrayTipos[i].descripcion);
    }
    printf("\n");
}



/** \brief Da de alta una notebook, pidiendole al usuario: modelo, marca, tipo y precio
 *
 * \param int indice;
 * \param
 * \return No devuelve nada.
 *
 */
void altaNotebook(eNotebook arrayNotebooks[], int tamnot, eMarca arrayMarcas[], int tammar, eTipo arrayTipos[], int tamtip)
{
    int indice;

    system("cls");

    indice = buscarLibre(arrayNotebooks, tamnot);

    if(indice == -1)
    {
        printf("No hay espacio libre\n\n");
    }
    else
    {
        printf("Ingrese modelo: ");
        fflush(stdin);
        gets(arrayNotebooks[indice].modelo);

        mostrarMarcas(arrayMarcas, tammar);
        printf("Ingrese ID de la marca: ");
        scanf("%d", &arrayNotebooks[indice].idMarca);

        mostrarTipos(arrayTipos, tamtip);
        printf("Ingrese ID del tipo: ");
        scanf("%d", &arrayNotebooks[indice].idTipo);

        printf("Ingrese el precio de la notebook: ");
        scanf("%d", &arrayNotebooks[indice].precio);

        arrayNotebooks[indice].id = 1;
    }
}



/** \brief Muestra una sola notebook, pero se puede usar en la funcion listarNotebooks.
 *
 * \param int i, j;
 * \param char marcaEncontrada[20], tipoEncontrado[20];
 * \return No devuelve nada.
 *
 */
void listarNotebook(eNotebook pNotebook, eMarca listmarcas[], int lenmarcas, eTipo listtipos[], int lentipos)
{
    int i, j;
    char marcaEncontrada[20];
    char tipoEncontrado[20];

    for(i=0; i<lenmarcas; i++)
    {
        if(pNotebook.idMarca == listmarcas[i].id)
        {
            strcpy(marcaEncontrada, listmarcas[i].descripcion);
            break;
        }
    }

    for(j=0; j<lentipos; j++)
    {
        if(pNotebook.idTipo == listtipos[j].id)
        {
            strcpy(tipoEncontrado, listtipos[j].descripcion);
            break;
        }
    }


    printf("%7s    %7s  %7s   %d   \n", pNotebook.modelo, marcaEncontrada, tipoEncontrado, pNotebook.precio);
}



/** \brief Muestra una lista con todas las notebooks.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron notebooks, o devuelve 0 si se encontraron.
 *
 */
int listarNotebooks(eNotebook listnotebooks[], int len, eMarca listmarcas[], int lenmarcas, eTipo listtipos[], int lentipos)
{
    int i;
    int indice = -1;

    system("cls");

    printf("Listado de notebooks\n");
    printf("____________________________________\n");
    printf("MODELO    MARCA    TIPO    PRECIO    \n");

    for(i=0; i<len; i++)
    {
        if(listnotebooks[i].id == 1)
        {
            indice = 0;
            listarNotebook(listnotebooks[i], listmarcas, lenmarcas, listtipos, lentipos);
        }
    }

    if(indice == -1)
    {
        printf("\nNo hay notebooks que mostrar\n\n");
    }

    printf("\n\n");

    return indice;
}
