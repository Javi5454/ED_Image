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

    ofstream myfile;

    string fname = "out.txt";

    myfile.open("../"+fname);

    for (int n_datos = 500; n_datos <= 9973; n_datos+= 500) {

        Image image(n_datos, n_datos);

        auto start = high_resolution_clock::now();
        image.ShuffleRows();
        auto stop = high_resolution_clock::now();

        auto duration_sec = duration_cast<seconds>(stop - start);
        auto duration_micro = duration_cast<microseconds>(stop - start);

        double segs = duration_sec.count();

        double micro = duration_micro.count()*0.000001;

        segs = segs+micro;


        myfile << n_datos << " " << segs << endl;

        cout << n_datos << "\t" << segs << " segs." << endl;
    }

    return 0;
}
