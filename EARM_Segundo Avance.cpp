//Edwin Aaron Rodriguez Morales 2041605
#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using namespace std;

struct articulos
{
    int nITEM;
    float IVA, Precio;
    string Nom, Descripcion, gen, clas, consola;
};
int n=0;
articulos inventario[3];

int main()
{
    int opc, des;
    do
    {
        printf("\t ***MENU DE OPCIONES***\n");
        printf("1.- Alta de articulos\n");
        printf("2.- Modificacion de articulos\n");
        printf("3.- Baja de articulos\n");
        printf("4.- Lista de articulos\n");
        printf("5.- Limpiar Pantalla\n");
        printf("6.- Salir\n");
        scanf_s("%d", &opc);
        cin.ignore();

        switch (opc)
        {
        case 1: // Alta de articulos
            if (n == 0)
            {
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
                    scanf_s("%f", &inventario[i].Precio);
                    cin.ignore();
                    inventario[i].IVA = inventario[i].Precio + (inventario[i].Precio * 0.16);
                }
                n = 1;
            }
            else
            {
                printf("Los articulos estan dados de alta\n");
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
            if (n == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    printf("--> Item Numero: %d\n", inventario[i].nITEM);
                    printf("%s\n", inventario[i].Nom.c_str());
                    printf("Descripcion: %s\n", inventario[i].Descripcion.c_str());
                    printf("Genero: %s\n", inventario[i].gen.c_str());
                    printf("Clasificacion por edades: %s\n", inventario[i].clas.c_str());
                    printf("Plataformas disponibles: %s\n", inventario[i].consola.c_str());
                    printf("Precio: %.2f\n(IVA includio)\n", inventario[i].IVA);
                }
            }
            else
            {
                printf("No ha dado de alta los articulos\n");
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
    } while (opc != 6);
   
}