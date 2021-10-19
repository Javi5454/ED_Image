//
// Created by adrian on 13/10/21.
//


#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    int nrow, ncol, tam;
    Image image, result;

    // Comprobar validez de la llamada
    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <fich_orig> <fich_rdo> <fila> <col> <lado>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    nrow = atoi(argv[3]);
    ncol = atoi(argv[4]);
    tam  = atoi(argv[5]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "Coordenadas de la imagen original donde se va a aplicar el zoom: " << nrow << "x" << ncol << endl;
    cout << "Tamaño de la original: " << tam << endl;

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
    if (0 > nrow || nrow >= image.get_rows()){
        cout << "Error: Coordenada inicial x incorrecta." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 2;
    }
    else if(0 > ncol || ncol >= image.get_cols()){
        cout << "Error: Coordenada inicial y incorrecta." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 3;
    }
    else if (0 > tam || tam >= image.get_rows() - nrow || tam >= image.get_cols() - ncol) {
        cout << "Error: Tamaño zoom incorrecto." << endl;
        cout << "Terminando la ejecucion del programa." << endl;
        return 4;
    }

    // Calcular el zoom
    result = image.Zoom2X(nrow, ncol, tam);

    // Guardar la imagen resultado en el fichero
    if (result.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}