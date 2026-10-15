/*
    Thomas Youk cs3505 A3
    An implementation of the HaruPDF library using the Sine class from a previous assignment to
    display a string of text in the form of a sine wave.
*/

#include "Sine.h"
#include "HaruPDF.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv){
    char filename[256] = "sinePDF.pdf";
    char fontName[256] = "Courier-Bold";
    char* inputText;
    const int startX = 10;
    const int fontSize = 20;
    const int fontLeading = 15;
    unsigned int i;
    
    HaruPDF haruPDF = HaruPDF();
    const int startingHeight = haruPDF.getPageHeight() / 2;
    //Set up the sine wave to draw along
    Sine sine = Sine(30, 100, 10);


    
    if(!(inputText = argv[1])){
        cout << "No string found. Please provide a string to print.";
        return 0;
    }
    haruPDF.setFont(fontName, fontSize, fontLeading);
    for (i = 0; i < strlen (inputText); i++){
        haruPDF.placeCharacter(inputText[i], startX + (fontLeading * i), startingHeight + sine.currentHeight(), 0);
        sine++;
    }
    haruPDF.saveToFile(filename);
}