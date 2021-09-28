/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the logic for the Model class and translates single and double characters from english to tutnese
// and also contains methods to translate tutnese syllables to english characters

#include <iostream>

using namespace std;

//Model class translates single character from english to tutnese and double characters to tutnese with the correct prefix
class Model{

    public:
    Model(); // Constructor
    ~Model(); // Destructor 
    string translateSingleCharacter(char letter); //translateSingleCharacter Method takes in a character and translates it to its tutnese counterpart and returns it as a string
    string translateDoubleCharacter(char letter); //translateDoubleCharacter Method takes in a character that appears next to the same character in a word and translates it to its tutnese counterpart. OO becomes squato
    char translateSingleSyllables(string syllables); //translateSingleChracter Method takes in a tutnese syllable and translates it to an english character
    string translateDoubleSyllables(string syllables); //translateDoubleSyllable Method translates a tutnese syllable with squa or squat (indicates doubling) to the english double characters
};