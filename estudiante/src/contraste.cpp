//
// Created by adrian on 20/10/21.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    int e1, e2, s1, s2;
    Image image, result;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: contraste <fich_orig> <fich_rdo> <e1> <e2> <s1> <s2>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    e1 = atoi(argv[3]);
    e2 = atoi(argv[4]);
    s1 = atoi(argv[5]);
    s2 = atoi(argv[6]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "Parametros usados:" << endl << "e1: " << e1 << ", e2: " << e2 << ", s1: " << s1 << ", s2: " << s2 << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }


    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    //Comprobamos las precondiciones
    if (0 > e1 || e1 >= 256){
        cout << "Error: parametro <e1> incorrecto." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 2;
    }
    if (0 > e2 || e2 >= 256){
        cout << "Error: parametro <e2> incorrecto." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 3;
    }
    if (0 > s1 || s1 >= 256){
        cout << "Error: parametro <s1> incorrecto." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 4;
    }
    if (0 > s2 || s2 >= 256){
        cout << "Error: parametro <s2> incorrecto." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 5;
    }

    // Calcular el zoom
    image.AdjustContrast(e1, e2, s1, s2);

    // Guardar la imagen resultado en el fichero
    if (image.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}