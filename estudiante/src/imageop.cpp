/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

#define MAX_BYTE 255

void Image::Invert(){
    for (int i=0; i<size(); i++){
        set_pixel(i, 255-get_pixel(i));
    }
}

Image Image::Crop(int nrow, int ncol, int height, int width) const{

    Image result(height,width);

    for(int i=nrow; i<nrow+height; i++){
        for(int j=ncol; j<ncol+width; j++) {
            result.set_pixel(i-nrow, j-ncol, get_pixel(i,j));
        }
    }
    return result;
}

double Image::Mean(int i, int j, int height, int width) const {
    double result = 0;

    for (int k = i; k < i+height  ; ++k) {
        for (int l = j; l < j+width ; ++l) {
            result += get_pixel(k,l);
        }
    }

    result /= (height*width);

    if(result - floor(result) >= 0.5) return floor(result+1);

    return floor(result);
}

Image Image::Zoom2X() const {

    int rows_res = rows*2-1, cols_res = cols*2-1;

    Image result(rows_res, cols_res);

    for (int i = 0; i < rows_res; ++i) {
        for (int j = 0; j < cols_res; ++j) {
            if(i%2==0 && j%2==0)
                result.set_pixel(i,j, get_pixel(i/2,j/2));
            if(i%2==0 && j%2!=0)
                result.set_pixel(i,j, Mean(i/2,j/2,1,2));
            if(i%2!=0 && j%2==0)
                result.set_pixel(i,j, Mean(i/2,j/2,2,1));
            if(i*j%2!=0)
                result.set_pixel(i,j, Mean(i/2,j/2,2,2));
        }
    }

    return result;
}

Image Image::Subsample(int factor) const {
    int icon_rows = get_rows()/factor;
    int icon_cols = get_cols()/factor;
    Image icon(icon_rows, icon_cols);

    for (int i = 0; i < rows/factor; ++i) {
        for (int j = 0; j < cols/factor; ++j) {
            icon.set_pixel(i,j, round(Mean(i*factor,j*factor,factor,factor)));
        }
    }

    return icon;
}

void Image::ShuffleRows() {
    const int p = 9973;                     // O(1)
    int newr;                               // O(1)

    byte *aux[rows];                        // O(1)

    for (int r=0; r<rows; r++) {            // O(1)     // O(rows)
        newr = r * p % rows;                // O(1)     //
        aux[r] = img[newr];                 // O(1)     //
    }

    for (int r=0; r<rows; r++)              // O(rows)
        img[r] = aux[r];                    // O(1)
}                                           // resultado ---> O(rows)

void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {

    for (int z = 0; z < rows*cols; ++z) {

        double temp = 0;

        if(get_pixel(z) < in1)
            temp = get_pixel(z) * out1*1.0/in1;
        else if (get_pixel(z) > in2)
            temp = out2 + (get_pixel(z)-in2)*(MAX_BYTE-out2)*1.0/(MAX_BYTE-in2);
        else
            temp = out1 + (out2-out1)*1.0/(in2-in1) * (get_pixel(z)-in1);

        temp = round(temp);

        set_pixel(z, temp);
    }
}
