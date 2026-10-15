#ifndef HARUPDF_H
#define HARUPDF_H
    class HaruPDF{
        public:
        /// @brief A simple constructor that initializes the Page and Doc that this class will print to.
        HaruPDF();

        /// @brief A simple destructor that ends the text stream and frees the Doc this class will print to.
        ~HaruPDF();

        /// @brief Set the typeface, font size, and spacing for the displayed text.
        /// @param fontName A character array representing the name of the font to be used
        /// @param fontSize A float representing the size of the font
        /// @param fontLeading An int representing the spacing for the displayed text
        void setFont(char fontName[256], float fontSize, int fontLeading);

        /// @brief Retrieves the height of the page.
        /// @return A double representing the page height.
        double getPageHeight();

        /// @brief Prints a single character to the page.
        /// @param character The character to print.
        /// @param x The X location to print at.
        /// @param y The Y location to print at.
        /// @param angleDegrees The rotation to print the character at.
        void placeCharacter(char character, double x, double y, double angleDegrees);

        /// @brief Saves the pdf with a given name.
        /// @param filename The name of the file to save to.
        void saveToFile(char filename[256]);
    };
#endif