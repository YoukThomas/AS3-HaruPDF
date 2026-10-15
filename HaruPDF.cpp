#include "HaruPDF.h"
#include "hpdf.h"
#include <math.h>
#include <iostream>

HPDF_Doc  pdf;
HPDF_Page page;
HPDF_Font font;

HaruPDF::HaruPDF(){
    pdf = HPDF_New(NULL, NULL);
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_LANDSCAPE);
    HPDF_Page_BeginText (page);
}

double HaruPDF::getPageHeight(){
    return HPDF_Page_GetHeight(page);
}

HaruPDF::~HaruPDF(){
    HPDF_Page_EndText(page);
    HPDF_Free(pdf);
}

void HaruPDF::setFont(char fontName[256], float fontSize, int fontLeading){
    font = HPDF_GetFont(pdf, fontName, NULL);
    HPDF_Page_SetFontAndSize(page, font, fontSize);
    HPDF_Page_SetTextLeading (page, fontLeading);
}

void HaruPDF::placeCharacter(char character, double x, double y, double angleDegrees){
    char buf[2];
    HPDF_Page_SetTextMatrix(page, cos(angleDegrees), sin(angleDegrees), -sin(angleDegrees), cos(angleDegrees), x, y);
    buf[0] = character;
    buf[1] = 0;
    HPDF_Page_ShowText(page, buf);
}

void HaruPDF::saveToFile(char filename[256]){
    HPDF_SaveToFile(pdf, filename);
}