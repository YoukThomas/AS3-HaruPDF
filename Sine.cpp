#include "Sine.h"
#include <iostream>
#include <cmath>

using std::ostream;
using std::cout;
using std::endl;



Sine::Sine(double amplitude, double wavelength, double angleIncrement) : amplitude(amplitude), wavelength(wavelength), angleIncrement(angleIncrement){
    //Set all provided values respectively, set internal angle to 0 to start with.
    this->amplitude = amplitude;
    this-> wavelength = wavelength;
    this-> angleIncrement = angleIncrement;
    angle = 0;
}

double Sine::currentAngle() {
    return angle;
}

double Sine::currentHeight(){
    //Uses the equation for a stationary sine wave to calculate the current "y" value (height).
    return amplitude * sin((2 * M_PI * angle) /wavelength);
}

Sine& Sine::operator++(){
    //Increase angle by the previously provided angle increment.
    angle += angleIncrement;
    return *this;
}

Sine Sine::operator++(int){
    //Make a copy of the Sine wave.
    Sine result(*this);
    //Increase the internal angle of the original Sine wave using the pre-fix operator.
    ++(*this);
    //Return the copy to operate with.
    return result;
}

ostream& operator<<(ostream& output, Sine sine){
    //Output the Sine wave's current angle and current height.
    output << sine.currentAngle() << ", " << sine.currentHeight();
    return output;
}

