#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>// funcione new y delete
#include <vector>
#include <Windows.h>

using namespace std;

int n = 0;//Variable que sirve para identificar si ya existen los registros
//Definir las funciones
void Alta();
void Lista();
void archivo();
void Baja();
void Modificar();
void MostrarArchivo();

int numRegistro, * registro, * nITEM;
float* IVA, * Precio;
string* Nom, * Descripcion, * gen, * clas, * consola, * status;

int main()
{
	int opc;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Da las caracteristicas al programa de windows (La consola)
	SetConsoleTextAttribute(hConsole, 6);//Establece color "6" (amarillo)
	printf("=========================================\n");
	SetConsoleTextAttribute(hConsole, 4);//Establece color "4" (Rojo)
	printf("\t%c %c TIENDA DE VIDEOJUEGOS %c %c\n", 3, 6, 4, 5); // Caracteres especiales representando simbolos
	SetConsoleTextAttribute(hConsole, 6);//Establece color "6" (amarillo)
	printf("=========================================\n");
	SetConsoleTextAttribute(hConsole, 2);//Establece color "2" (Verde)
	printf("\t     %cMENU DE OPCIONES%c\n", 16, 17); // Caracteres especiales representando simbolos
	SetConsoleTextAttribute(hConsole, 6);//Establece color "6" (amarillo)
	printf("=========================================\n");
	SetConsoleTextAttribute(hConsole, 15);//Establece color "15" (Blanco) al resto del programa
	printf("1.- Alta de articulos\n");
	printf("2.- Lista de articulos\n");
	printf("3.- Limpiar Pantalla\n");
	printf("4.- Modificacion de articulos\n");
	printf("5.- Baja de articulos\n");
	printf("6.- Salir\n");
	scanf_s("%d", &opc); // Leer la opcion seleccionada por el usuario
	cin.ignore();

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		Lista();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		Modificar();
		return main();
		break;

	case 5:
		Baja();
		return main();
		break;

	case 6:
		archivo();
		system("cls");
		MostrarArchivo();
		exit(0);
		break;

	default:
		printf("Opcion incorrecta, vuelva a intentar\n");
		return main();
		break;
	}
}

void Alta()
{
	if (n == 0)//Variable que sirve para identificar si ya existen los registros (0=no existen)
	{
		printf("Ingrese la cantidad de articulos a dar de alta: ");
		scanf_s("%d", &numRegistro); // Leer la cantidad de articulos a dar de alta
		cin.ignore();
		//Asigna los arreglos
		nITEM = new int[numRegistro];
		IVA = new float[numRegistro];
		Precio = new float[numRegistro];
		Nom = new string[numRegistro];
		Descripcion = new string[numRegistro];
		gen = new string[numRegistro];
		clas = new string[numRegistro];
		consola = new string[numRegistro];
		status = new string[numRegistro];
		for (int i = 0; i < numRegistro; i++)
		{
			printf("Ingrese el Numero del item: ");
			scanf_s("%d", &nITEM[i]); // Leer el numero de articulo
			cin.ignore();
			printf("Ingrese el Nombre del Articulo: \n");
			getline(cin, Nom[i]); // Leer el nombre del articulo
			printf("Ingrese la descripcion del articulo: \n");
			getline(cin, Descripcion[i]); // Leer la descripcion del articulo
			printf("Ingrese el Genero: \n");
			getline(cin, gen[i]); // Leer el genero del articulo
			printf("Ingrese la clasificacion por edades: \n");
			getline(cin, clas[i]); // Leer la clasificacion por edades del articulo
			printf("¿Para que plataformas estara disponible?: \n");
			getline(cin, consola[i]); // Leer las plataformas disponibles para el articulo
			printf("Ingrese el Precio del Articulo (El IVA se agregara automaticamente): \n");
			scanf_s("%f", &Precio[i]); // Leer el precio del articulo
			cin.ignore();
			IVA[i] = Precio[i] + (Precio[i] * 0.16); // Calcular el IVA
			printf("\n-------------------------\n");
		}
		n = 1;//Variable que sirve para identificar si ya existen los registros (1=existen)
		printf("Articulos dados de alta con exito\n");
	}
	else
	{
		printf("Los articulos ya han sido dados de alta\n"); //n=0
	}
}

void Lista()
{
	if (n != 0)//mientras existan los registros
	{
		for (int i = 0; i < numRegistro; i++)//hasta la cantidad de registros proporcionada
		{
			if (status[i] == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO %d\n", i + 1);
				printf("\n-------------------------\n");
			}
			else
			{
				printf("--> Registro Numero: %d\n", i + 1);
				printf("Item Numero: %d\n", nITEM[i]);
				printf("%s\n", Nom[i].c_str());
				printf("Descripcion: %s\n", Descripcion[i].c_str());
				printf("Genero: %s\n", gen[i].c_str());
				printf("Clasificacion por edades: %s\n", clas[i].c_str());
				printf("Plataformas disponibles: %s\n", consola[i].c_str());
				printf("Precio Base: %.2f\n", Precio[i]);
				printf("IVA: %.2f\n", IVA[i] - Precio[i]);
				printf("Precio: %.2f\n(IVA incluido)\n", IVA[i]);
				printf("\n-------------------------\n");
			}
		}
	}
	else
	{
		printf("No ha dado de alta los articulos\n");
	}
}

void archivo()
{
	ofstream archivo; //Declaracion del archivo
	string inventario;
	int texto;
	string texto2;

	inventario = "Registros.txt";//Asignacion del nombre

	archivo.open(inventario.c_str(), ios::out);//abre el archivo

	if (archivo.fail())//Comprueba cualquier error de apertura
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}
	for (int i = 0; i < numRegistro; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";//Asigna el texto a la variable
			texto = i + 1;//Numero de registro actual (+1 porque inicia en 0)
			archivo << texto2 << texto << "\n";//añade al archivo el registro eliminado
			archivo << "-------------------------" << "\n";
		}
		else
		{
			//añadir al archivo los datos
			archivo << "--> Registro Numero: " << (i + 1) << endl;
			archivo << "Item Numero: " << nITEM[i] << endl;
			archivo << Nom[i] << endl;
			archivo << "Descripcion: " << Descripcion[i] << endl;
			archivo << "Genero: " << gen[i] << endl;
			archivo << "Clasificacion por edades: " << clas[i] << endl;
			archivo << "Plataformas disponibles: " << consola[i] << endl;
			archivo << "Precio Base: " << Precio[i] << endl;
			archivo << "IVA: " << (IVA[i] - Precio[i]) << endl;
			archivo << "Precio: " << IVA[i] << endl;
			archivo << "-------------------------" << endl;
		}
	}
	archivo.close();
}

void Baja()
{
	int j;
	if (n != 0)//mientras existan los registros
	{
		printf("Ingrese el registro a eliminar: ");
		scanf_s("%d", &j);

		if (j < 1 || j > numRegistro)//El numero debe estar entre las posibilidades de asignacion
		{
			printf("Registro no existe. Vuelva a intentar.\n");
			return;
		}
		else
		{
			if ((status[j - 1] == "ELIMINADO"))//comprueba si el registro numero j-1 esta eliminado (-1 porque se registraron a partir de 0)
			{
				printf("El registro seleccionado ya ha sido eliminado. Vuelva a intentar.\n");
				return;
			}
			else
			{
				j = j - 1;
				printf("Eliminando registro %d\n", j + 1);//+1 porque anteriormente se resto 1 para que encajara con la variable deseada
				//Eliminacion de datos
				status[j] = "ELIMINADO";
				nITEM[j] = 0;
				IVA[j] = 0;
				Precio[j] = 0;
				Nom[j] = "";
				Descripcion[j] = "";
				gen[j] = "";
				clas[j] = "";
				consola[j] = "";
				printf("Articulo dado de baja con exito\n");
			}
		}
	}
	else
	{
		printf("No ha dado de alta los articulos\n");
		return;
	}
}

void Modificar()
{
	int j, opcion, op2;
	if (n != 0)//mientras existan los registros
	{
		do
		{
			printf("Ingrese el numero de registro a modificar: ");
			scanf_s("%d", &j);
			j = j - 1;

			if (j < 0 || j >= numRegistro)//El numero debe estar entre las posibilidades de asignacion
			{
				printf("Registro no existe. Vuelva a intentar.\n");
				return;
			}
			else
			{
				if ((status[j] == "ELIMINADO"))
				{
					printf("El registro %d esta elimidano\n", j + 1);
					printf("Ingrese un registro valido.\n");
					op2 = 1;//Asignar op2 como 1
				}
				else
				{
					op2 = 2;//cambiar op2 a 2
				}
			}
		} while (op2 == 1);//Mientras la op2 sea 1 repetir

		//Seleccion de modificacion
		printf("Ingrese que desea modificar:\n");
		printf("1.- Numero de Item\n");
		printf("2.- Nombre\n");
		printf("3.- Descripcion\n");
		printf("4.- Genero:\n");
		printf("5.- Clasificacion por edades\n");
		printf("6.- Plataformas disponibles\n");
		printf("7.- Precio Base\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			printf("Ingrese el Numero del item: ");
			scanf_s("%d", &nITEM[j]); // Leer el nuevo numero de articulo
			cin.ignore();
			break;

		case 2:
			while (getchar() != '\n');
			printf("Ingrese el Nombre del Articulo: \n");
			getline(cin, Nom[j]); // Leer el nuevo nombre del articulo
			break;

		case 3:
			while (getchar() != '\n');
			printf("Ingrese la descripcion del articulo: \n");
			getline(cin, Descripcion[j]); // Leer la nueva descripción del articulo
			break;

		case 4:
			while (getchar() != '\n');
			printf("Ingrese el Genero: \n");
			getline(cin, gen[j]); // Leer el nuevo genero del articulo
			break;

		case 5:
			while (getchar() != '\n');
			printf("Ingrese la clasificacion por edades: \n");
			getline(cin, clas[j]); // Leer la nueva clasificacion por edades del articulo
			break;

		case 6:
			while (getchar() != '\n');
			printf("¿Para que plataformas estara disponible?: \n");
			getline(cin, consola[j]); // Leer las nuevas plataformas disponibles para el articulo
			break;

		case 7:
			printf("Ingrese el Precio del Articulo (El IVA se agregara automaticamente): \n");
			scanf_s("%f", &Precio[j]); // Leer el nuevo precio del articulo
			cin.ignore();
			IVA[j] = Precio[j] + (Precio[j] * 0.16); // Calcular el IVA
			break;

		default:
			printf("Opcion incorrecta, vuelva a intentar\n");
			return;
			break;
		}

		printf("Articulo modificado con exito\n");
	}
	else
	{
		printf("No ha dado de alta los articulos\n");
		return;
	}
}
void MostrarArchivo()
{
	ifstream archivo("Registros.txt");//Lectura del archivo
	if (archivo.is_open())//comprobar si abre
	{
		string linea;//asignar variable que almacena cada linea dentro de el archivo
		while (getline(archivo, linea))//// Lectura de cada línea del archivo
		{
			printf("%s\n", linea.c_str());//// Impresión de la línea en la consola
		}
		archivo.close();
	}
	else
	{
		printf("Error al abrir el archivo\n");
	}
}
