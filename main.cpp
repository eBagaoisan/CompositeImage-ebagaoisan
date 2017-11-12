#include "bitmap.h"
#include <iostream>
#include <vector>
#include <stream>

using namespace std;

//Prototypes
void validBMP(Bitmap);
void sizeImage(Bitmap);
vector< vector<Pixel> > convertBMP(Bitmap &);
vector< vector<Pixel> > greyScale(vector<vector<Pixel> >&);
vector< vector<pixel> > composite(vector<vector<Pixeel> >&);

int main()
{

    
    return 0;
}

/*Takes users image input and checks if user input is a valid BMP image, 
if not then asks user to access another file that
is valid.*/
bool validBMP(Bitmap bmp){
    image.open(bmp);
    bool realImage = image.isImage();
    if (realImage == false){
        
    }
    
}

//Converts valid image into a pixel matrix
vector< vector<Pixel> > convertBMP(Bitmap & image){
//toPixelmatrix
}

/*checks if new image is the same size as previous image
by checking and comparing pixel size of both images,
if invalid return to main function loop
*/
bool sizeImage(Bitmap size){

}

//Takes matrix of pixels and takes average values of all RGB components
vector<vector<Pixel> > greyScale(vector<vector<Pixel> >& imgMatrix){

}

//Takes values of matrices and gets the averages of all 10 images and processes each image into one matrix
vector<vector<Pixel> > composite(vector<vector<Pixel> >& matrix){

}
