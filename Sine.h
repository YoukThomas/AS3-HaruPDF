//Thomas Youk CS3505 Assignment 2: Making a Class

#ifndef SINE_H
#define SINE_H
#include <ostream>

/// @brief A Class that represents a Sine wave. Holds an angleIncrement, amplitude, wavelength, and angle data member.
class Sine {
private:
    double angleIncrement;
    double amplitude;
    double wavelength;
    double angle;
public:
    /// @brief A constructor for a Sine object
    /// @param amplitude The aplitude of the sine wave (The distance from the mid-point to the top of a wave))
    /// @param wavelength The wavelength of the sine wave (How long each wave is)
    /// @param angleIncrement The angle increment for the sine wave (How many degrees the sine wave will increase for each iteration)
    Sine(double amplitude, double wavelength, double angleIncrement);

    /// @brief A method which returns the current angle value of the Sine wave
    /// @return A double that measures the current angle of the wave
    double currentAngle();

    /// @brief A method which returns the current height value of the Sine wave
    /// @return A double that measures the current height of the sine wave
    double currentHeight();

    /// @brief An overloaded operator that changes the pre-fix incrementation. This increases the internal angle value by the angle increment value.
    /// @return A Sine& of the newly changed Sine object.
    Sine& operator++();

    /// @brief An overloaded operator that changes the post-fix incrementation. This uses the overloaded pre-fix incrementation to increase the internal angle value by the angle increment value.
    /// @param  Placeholder to distinguish the pre-fix and post-fix operator overloaders.
    /// @return A Sine object copy holding values from before the pre-fix operation was conducted.
    Sine operator++(int);

    /// @brief An overloaded operator that changes the insertion operator. 
    /// @param output The stream to insert a Sine object into
    /// @param sine The Sine object to insert into a stream
    /// @return An output string that reads the current angle and height of a sine wave in the format "[Current Angle], [Current Height]".
    friend std::ostream& operator<<(std::ostream& o, Sine s);
};
    
#endif