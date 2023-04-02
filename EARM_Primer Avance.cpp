//Edwin Aaron Rodriguez Morales 2041605
#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using  namespace std;

struct articulos
{
    int nITEM;
    float IVA;
    char Nom[50], Descripcion[100], gen[50], clas[50], consola[50];

};

int main()
{
    articulos inventario[3]
    int opc, des;
    float Precio;
    printf("\t ***MENU DE OPCIONES***\n");
    printf("1.- Alta de articulos\n");
    printf("2.- Modificacion de articulos\n");
    printf("3.- Baja de articulos\n");
    printf("4.- Lista de articulos\n");
    printf("5.- Limpiar Pantalla\n");
    printf("6.- Salir\n");
    scanf_s("%d", &opc);

    switch (opc)
    {
    case 1: // Alta de articulos
        for (int i = 0; i < 3; i++) 
        {
            printf("Ingrese el Numero del item\n");
            scanf_s("%d", &inventario[i].nITEM);
            cin.ignore();
            printf("Ingrese el Nombre del Articulo\n");
            getline(cin, inventario[i].Nom);
            printf("Ingrese la descripcion del articulo\n");
            getline(cin, inventario[i].Descripcion);
            printf("Ingrese el Genero\n");
            getline(cin, inventario[i].gen);
            printf("Ingrese la clasificacion por edades\n");
            getline(cin, inventario[i].clas);
            printf("¿Para que platarormas estara disponible?\n");
            getline(cin, inventario[i].consola);
            printf("Ingrese el Precio del Articulo\n(El IVA se agregara automaticamente)\n");
            scanf_s("%d", &Precio);
            inventario[i].IVA = Precio + (Precio * 0.16);
        }
        break;
    //Caso 2 y 3 solo pregunta si quieres regresar al menu (Por ahora)
    case 2: // Modificacion
        printf("¿Desea regresar al menu?\n1.- Si 2.- No\n");
        scanf_s("%d", &des);
        if (des == 1)
        {
            return main();
        }
        break;

    case 3: // Baja de articulos
        printf("¿Desea regresar al menu?\n1.- Si 2.- No\n");
        scanf_s("%d", &des);
        if (des == 1)
        {
            return main();
        }
        break;

    case 4: // Lista de Articulos
        for (int i = 0; i < 3; i++)
        {
            printf("Item Numero: %d", inventario[i].nITEM);
            printf("--> %s", inventario[i].Nom);
            printf("Descripcion:\n%s", inventario[i].Descripcion);
            printf("Genero:\n%s", inventario[i].gen);
            printf("Clasificacion por edades:\n%s", inventario[i].clas);
            printf("Plataformas disponibles:\n%s", inventario[i].consola);
            printf("Precio: %f\n(IVA includio)", inventario[i].IVA);
        }
        printf("¿Desea regresar al menu?\n1.- Si 2.- No\n");
        scanf_s("%d", &des);
        if (des == 1)
        {
            return main();
        }
        break;

    case 5: // Limpiar pantalla
        system("cls");
        return main();
        break;
    case 6: // Salir
        exit(1);
        break;
    default:
        system("cls");
        printf("Opcion incorrecta, vuelva a intentar\n");
        return main();
        break;
    }
}