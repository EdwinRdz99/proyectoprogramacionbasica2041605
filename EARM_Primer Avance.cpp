//Edwin Aaron Rodriguez Morales 2041605
#include <iostream>
#include <math.h>
#include <string> //Para agregar "cin.getline"

using namespace std;

int main()
{
    int opc, nITEM, des;
    float Precio, IVA;
    char Nom[50], Descripcion[100], gen[50], clas[50], consola[50];
    cout << "\t ***MENU DE OPCIONES***" << endl;
    cout << "1.- Alta de articulos" << endl;
    cout << "2.- Modificacion de articulos" << endl;
    cout << "3.- Baja de articulos" << endl;
    cout << "4.- Lista de articulos" << endl;
    cout << "5.- Limpiar Pantalla" << endl;
    cout << "6.- Salir" << endl;
    cin >> opc;

    switch (opc)
    {
    case 1: // Alta de articulos
        //Cin.getline para agregar caracteres con espacios
        cout << "Ingrese el Numero del item" << endl;
        cin >> nITEM;
        //Cin.ignore evita que no tome en cuenta el cin proximo
        cin.ignore();
        cout << "Ingrese el Nombre del Articulo" << endl;
        cin.getline(Nom, 50, '\n');
        cout << "Ingrese la descripcion del articulo" << endl;
        cin.getline(Descripcion, 100, '\n');
        cout << "Ingrese el Genero" << endl;
        cin.getline(gen, 50, '\n');
        cout << "Ingrese la clasificacion por edades" << endl;
        cin.getline(clas, 50, '\n');
        cout << "¿Para que platarormas estara disponible?" << endl;
        cin.getline(consola, 50, '\n');
        cout << "Ingrese el Precio del Articulo" << endl << "(El IVA se agregara automaticamente)" << endl;
        cin >> Precio;
        IVA = Precio + (Precio * 0.16);
        cout << "¿Desea regresar al menu?" << endl << "1.- Si   2.- No" << endl;
        cin >> des;
        if (des == 1)
        {
            return main();
        }
        break;
        //Caso 2, 3 y 4 solo pregunta si quieres regresar al menu (Por ahora)
    case 2: // Modificacion
        cout << "¿Desea regresar al menu?" << endl << "1.- Si   2.- No" << endl;
        cin >> des;
        if (des == 1)
        {
            return main();
        }
        break;

    case 3: // Baja de articulos
        cout << "¿Desea regresar al menu?" << endl << "1.- Si   2.- No" << endl;
        cin >> des;
        if (des == 1)
        {
            return main();
        }
        break;

    case 4: // Lista de Articulos
        cout << "¿Desea regresar al menu?" << endl << "1.- Si   2.- No" << endl;
        cin >> des;
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
        cout << "Opcion incorrecta, vuelva a intentar" << endl;
        return main();
        break;
    }
}