
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

struct Productos{
  string codigo;
  int minimo;
  int actual;
  string proveedor;
  float precio;
};

void agregar_producto(){
  Productos x;
  cout << "Ingrese código de producto"<< "\n";
  cin >> x.codigo;
  cout << "Ingrese el minimo del producto"<< "\n";
  cin >> x.minimo;
  cout << "Ingrese cantidad actual del producto"<< "\n";
  cin >> x.actual;
  cout << "Ingrese el proveedor del producto"<< "\n";
  cin >> x.proveedor;
  cout << "Ingrese precio del producto"<< "\n";
  cin >> x.precio;

    // grabamos producto en el archivo.
    ofstream miarchivo("stock.txt", std::ios_base::app);
    miarchivo << x.codigo << "\t" << x.minimo << "\t" << x.actual << "\t" << x.proveedor << "\t" << x.precio << endl;
    //Cerramos la escritura del archivo.
    miarchivo.close();
}

void leer_archivo(){
    //declaramos la variable para leer archivo
    ifstream miarchivo;
    
    //std::ifstream file("myfile", std::ios::binary | std::ios::ate);
    //abrimos archivo 
    miarchivo.open("stock.txt",ios::in);
    
    //declare string to hold each line of text
    string line;

    //loop through myinfile while line exist
    while(getline(miarchivo,line))
    {
        cout << line << endl;
        // grabo en memoria
        //en_memoria.push_back(line);
    }

    //make sure and close ifstream
    miarchivo.close();
    string empty;
    cin >> empty;
    return;
}


int main() {
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Productos" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Agregar Producto" <<endl;
        cout << "\t2 .- Leer archivo y mostrar minimos" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        agregar_producto();
        break;
 
			case '2':
        system("clear");
        leer_archivo();
        break;

      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
  
  return 0;
}
