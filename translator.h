/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the basic structure of the Translator class. The Translator class translates english sentence or word to a tutnese sentence or word
// The translator class also can translate a tutnese word or sentence to a english word or sentence 
#include <iostream>

using namespace std;

//Translator class that will be used to translate the english sentence to tutnese
class Translator{

    public:
    Translator(); //Constructor
    ~Translator(); //Destructor
    string translateEnglishWord(string word); //translates and english word to its tutnese counterpart
    string translateEnglishSentence(string sentence); //translates an english sentence and returns its as a sentence in tutnese
    string translateTutneseWord(string word); //Translates a tutnese word to english and returns the englihs word
    string translateTutneseSentence(string sentence); //translates a sentence of tutnese words to english and returns the english sentence

};