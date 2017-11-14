#include "bitmap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Prototypes
bool validBMP(string);
bool sizeImage(Bitmap);
vector< vector<Pixel> > greyScale(vector<vector<Pixel> >&);
vector< vector<Pixel> > composite(vector<vector<Pixel> >&);


//variables
int MAX_BMP = 10;
string file;
Bitmap image;
vector<Bitmap> pictures;

int main()
{
    int i=0;

    //Loop asks user for bmp files and stores them into vector of type Bitmap
    do {
        cout<<"Please input a bmp file or \"DONE\": ";
        cin>>file;
        if (file == "DONE"){
            if(pictures.size() > 1){
                break;
            }
            else{
                cout<<"Not enough files entered."<<endl;
                i--;
            }
        }
        else if (validBMP(file) == false){
            while(validBMP(file) == false){
                cout<<"ERROR:Invalid entry, please enter a bmp file: ";
                cin>>file;
                validBMP(file);
            }
        }
        else if(validBMP(file) == true){
            image.open(file);
            pictures.push_back(image);
        }
        else{
            cout<<"Invalid entry!"<<endl;
            i--;
        }

    }
    while(i < MAX_BMP);
    i++;
    

    return 0;
}

/*Takes users image input and checks if user input is a valid BMP image, 
if not then asks user to access another file that
is valid.*/
bool validBMP(string bmp){ 
    Bitmap image;
    image.open(bmp);
    bool realImage = image.isImage();
    if (realImage == false){
        return false;
    }
    else{
        return true;
    }
}


/*checks if new image is the same size as previous image
by checking and comparing pixel size of both images,
if invalid return to main function loop
*/
bool sizeImage(Bitmap size){

}

//Takes matrix of pixels and takes average values of all RGB components
vector<vector<Pixel> > greyScale(vector<vector<Pixel> >& imgMatrix){
    Pixel rgb;
    int rgbAvg;
    for(int r = 0; r<imgMatrix.size(); r++){
        for(int c = 0; c<imgMatrix[r].size(); c++){
            rgb = imgMatrix[r][c];
            rgbAvg = (rgb.red + rgb.green + rgb.blue)/3;
            rgb.red = rgbAvg;
            rgb.green = rgbAvg;
            rgb.blue = rgbAvg;
            imgMatrix[r][c] = rgb;
        }
    }
}

//Takes values of matrices and gets the averages of all 10 images and processes each image into one matrix
vector<vector<Pixel> > composite(vector<vector<Pixel> >& matrix){

}
