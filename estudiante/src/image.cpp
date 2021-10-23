/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>

#include <image.h>
#include <imageIO.h>

using namespace std;

#define MAX_BYTE 255

/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    return img[0][k];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = img[0];
    return WritePGMImage(file_path, p, rows, cols);
}

void Image::Invert(){
    for (int i=0; i<size(); i++){
        set_pixel(i, 255-get_pixel(i));
    }
}

Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image result(height,width);

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            result.set_pixel(i, j, get_pixel(nrow+i, ncol+j));
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


//    Image orig(rows,cols * 2 - 1);

//    for (int i = 0; i < rows; i+=2) {
//        for (int j = 0; j < cols; j+=2) {
//
//            orig.set_pixel(i, 2 * j, get_pixel(i, j));
//
//            if(j < rows-1) {
//                byte mean = Mean(i,j, 1,2);
//
//                orig.set_pixel(i, 2 * j + 1, mean);
//            }
//
//        }
//        orig.set_pixel(i, 2 * (rows - 1), get_pixel(i, rows - 1));
//    }
//
//
//    Image result(rows*2-1, rows*2-1);
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < 2*rows-1; ++j) {
//            result.set_pixel(2 * i, j, orig.get_pixel(i, j));
//
//            byte mean = 0;
//
//            if(i < rows-1){
//                if(j%2 == 0){
//                    mean = orig.Mean(i,j,1,2);
//                }
//
//                result.set_pixel(2 * i + 1, j, mean);
//            }
//        }
//    }
//
//    for (int i = 0; i < 2 * rows - 1; ++i) {
//        for (int j = 0; j < 2 * rows - 1; ++j) {
//            if (i*j%2!=0)
//                result.set_pixel(i,j, Mean((i-1)/2, (j-1)/2, 2,2));
//        }
//    }
}

Image Image::Subsample(int factor) const {
    int icon_rows = get_rows()/factor;
    int icon_cols = get_cols()/factor;
    Image icon(icon_rows, icon_cols);

    int nf_secc = get_rows()/icon_rows;
    int nc_secc = get_cols()/icon_cols;

    for (int i = 0; i < icon_rows; ++i) {
        for (int j = 0; j < icon_cols; ++j) {
            int sum = 0;

            for (int k = nf_secc*i; k < nf_secc*(i+1) ; ++k) {
                for (int l = nc_secc*j; l < nc_secc*(j+1) ; ++l) {
                    sum = sum + get_pixel(k,l);
                }
            }

            sum = sum/(nf_secc*nc_secc);
            icon.set_pixel(i,j,sum);
        }
    }

    return icon;
}

void Image::ShuffleRows() {
    const int p = 9973;

    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p%rows;
        for (int c=0; c<cols;c++)
            temp.set_pixel(r,c,get_pixel(newr,c));
    }
    Copy(temp);
}

void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    for (int z = 0; z < rows*cols; ++z) {

        double temp = 0;

        if(get_pixel(z) < in1)
            temp = get_pixel(z) * out1*1.0/in1;
        else if (get_pixel(z) > in2)
            temp = out2 + (get_pixel(z)-in2)*(MAX_BYTE-out2)*1.0/(MAX_BYTE-in2);
        else
            temp = out1 + (out2-out1)*1.0/(in2-in1) * (get_pixel(z)-in1);

        if (temp - int(temp) >= 0.5) temp=int(temp)+1;

        set_pixel(z, temp);
    }
}

