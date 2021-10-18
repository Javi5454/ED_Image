//
// Created by javi5454 on 2021-10-18.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

int main (int argc, char *argv[]){
    char *origen, *destino;

    origen  = argv[1];
    destino = argv[2];

    Image image, result;

    image.Load(origen);

    result = image;

    for (int i=1; i< image.get_rows(); i=i+2){
        for(int j=0; j < image.get_cols(); j++){
            result.set_pixel(i,j,0);
        }
    }

    /*for (int i = 0; i < image.get_rows(); i++){
        for (int j = 1; j < image.get_cols() ; j=j+2) {
            result.set_pixel(i,j,0);
        }
    }*/

    result.Save(destino);

    return 0;
}
