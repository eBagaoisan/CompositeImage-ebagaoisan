#include "bitmap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Prototypes
bool validBMP(string);
bool sizeImage(vector<Bitmap>, vector<Bitmap>);
vector< vector<Pixel> > composite(vector<Bitmap> &);


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
    }
    while(i < MAX_BMP);
    i++;
    
    //Composite image
    image.fromPixelMatrix(composite(pictures));
    image.save("composite-ebagaoisan.bmp");
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

/*
bool sizeImage(vector<Bitmap> image1, vector<Bitmap> image2){
    if(image1.size() == image2.size()){
        if(image1[0].size() == image2[0].size()){
            return true;
        }
    }
    return false;
}
*/

//Takes values of matrices and gets the averages of all 10 images and processes each image into one matrix
vector<vector<Pixel> > composite(vector<Bitmap>& matrix){
    vector<vector<Pixel> > bmp;
    vector<vector<Pixel> > tempBmp;
    Pixel rgb;
    int tempAvg = matrix.size();

    bmp = matrix[0].toPixelMatrix();


    for (int x = 0; x<matrix.size(); x++){
        tempBmp = matrix[x].toPixelMatrix();
        for (int r = 0; r<tempBmp.size(); r++){
            for (int c = 0; c<tempBmp[r].size(); r++){
                rgb = tempBmp[r][c];
                rgb.red = rgb.red/tempAvg;
                rgb.green = rgb.green/tempAvg;
                rgb.blue = rgb.blue/tempAvg;
                tempBmp[r][c] = rgb;
            }
        }
    }
    for (int r = 0; r<bmp.size(); r++){
        for (int c = 0; c<bmp[r].size(); c++){
            bmp[r][c] = tempBmp[r][c];
        }
    }
    return bmp;
}
