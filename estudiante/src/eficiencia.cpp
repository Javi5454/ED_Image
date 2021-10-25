//
// Created by adrian on 22/10/21.
//

#include "iostream"
#include "image.h"
#include "chrono"
#include "cstdlib"


#include "fstream"



using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]){

    clock_t ti, tf;

    if (argc != 2){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: eficiencia <ruta a plots.py>\n";
        exit (1);
    }

    char *path_to_plots = argv[1];

    string command = path_to_plots;

    command = "python3 " + command;

    // Eficiencia por filas:

    ofstream rows_eficiency;
    string fname = "eficiencia2_rows.csv";
    rows_eficiency.open(fname);


    cout << "Eficiencia por filas:" << endl << endl;
    for (int filas = 100; filas <= 9973; filas+= 100) {

        Image image(filas, 500);

        auto start = high_resolution_clock::now();

        image.ShuffleRows();

        auto stop = high_resolution_clock::now();

        auto duration_sec = duration_cast<seconds>(stop - start);
        auto duration_micro = duration_cast<microseconds>(stop - start);
        double segs = duration_sec.count();
        double micro = duration_micro.count()*0.000001;
        segs = segs+micro;

        rows_eficiency << filas << ", " << segs << endl;

        cout << filas << "\t" << segs << " segs." << endl;
    }

    rows_eficiency.close();

    // Eficiencia por columnas:

    ofstream cols_eficiency;
    fname = "eficiencia2_cols.csv";
    cols_eficiency.open(fname);

    cout << endl << endl << "Eficiencia por columnas:" << endl << endl;

    for (int cols = 100; cols <= 10000; cols+= 100) {

        Image image(500, cols);

        auto start = high_resolution_clock::now();

        image.ShuffleRows();

        auto stop = high_resolution_clock::now();

        auto duration_sec = duration_cast<seconds>(stop - start);
        auto duration_micro = duration_cast<microseconds>(stop - start);
        double segs = duration_sec.count();
        double micro = duration_micro.count()*0.000001;
        segs = segs+micro;

        cols_eficiency << cols << ", " << segs << endl;

        cout << cols << "\t" << segs << " segs." << endl;
    }
    fname = "eficiencia2_cols.csv";
    cols_eficiency.open(fname);

    cout << endl << endl << "Eficiencia por columnas:" << endl << endl;

    for (int cols = 100; cols <= 10000; cols+= 100) {

        Image image(500, cols);

        auto start = high_resolution_clock::now();

        image.ShuffleRows();

        auto stop = high_resolution_clock::now();

        auto duration_sec = duration_cast<seconds>(stop - start);
        auto duration_micro = duration_cast<microseconds>(stop - start);
        double segs = duration_sec.count();
        double micro = duration_micro.count()*0.000001;
        segs = segs+micro;

        cols_eficiency << cols << ", " << segs << endl;

        cout << cols << "\t" << segs << " segs." << endl;
    }

    cols_eficiency.close();

    // Eficiencia por iteraciones

    ofstream iter_eficiency;
    fname = "eficiencia2_iter.csv";
    iter_eficiency.open(fname);

    cout << endl << endl << "Eficiencia por iteraciones:" << endl << endl;

    for (int it = 100; it <= 10000; it+= 100) {

        Image image(20, 20);

        auto start = high_resolution_clock::now();

        for (int i = 0; i < it; i+=10)
            image.ShuffleRows();

        auto stop = high_resolution_clock::now();

        auto duration_sec = duration_cast<seconds>(stop - start);
        auto duration_micro = duration_cast<microseconds>(stop - start);
        double segs = duration_sec.count();
        double micro = duration_micro.count()*0.000001;
        segs = segs+micro;

        iter_eficiency << it << ", " << segs << endl;

        cout << it << "\t" << segs << " segs." << endl;
    }

    iter_eficiency.close();


    system(command.c_str());

    return 0;
}
