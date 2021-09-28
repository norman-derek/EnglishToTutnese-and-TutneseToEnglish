/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the basic structure of the Translator class. The Translator class translates english sentence or word to a tutnese sentence or word
// The translator class also can translate a tutnese word or sentence to a english word or sentence 

#include "translator.h"
#include "model.h"

Translator::Translator(){ //Constructor

}

Translator::~Translator(){ //Destructor 

}

/*
 * This method is called translateEnglishWord
 * This method returns a string called tutneseword that represents the tutnese translation of the english word
 * This method has a single parameter that takes in a string called word that represents an english word 
*/
string Translator::translateEnglishWord(string word){
    Model *m = new Model(); // Creates Model object to use methods from Model class
    string tutneseword = ""; //initializes string for tutnese word where tutnese translations will be added to 
    for(int i = 0; i < word.length(); ++i){ // loops through the word and translates each character to its tutnese translation 
        if ((i < word.length()) && (tolower(word[i]) == tolower(word [i+1]))) {
            tutneseword += m->translateDoubleCharacter(word[i]); //translates the first character of the double character and turns it into the prefix for the second character of double character and treats second character as a single character
        } else {
        tutneseword += m->translateSingleCharacter(word[i]); //translates single characters to tutnese
        }
    }
    delete m;
    return tutneseword;
}

/*
* This method is called translateEnglishSentence
* This method returns a string called tutnesesentence which represents the tutnese translation of an english sentence
* This method takes a single parameter which is a string called sentence representing an english sentence
*/
string Translator::translateEnglishSentence(string sentence){
    string word = "";
    string tutnesesentence = "";
    for(int i = 0; i < sentence.length(); ++i){ 
        if (i == sentence.length() - 1) { //since there is no whitespace after the last word this accounts for the last word in the sentence
            word += sentence[i]; //adds the last character of the string to the word  
            tutnesesentence += translateEnglishWord(word); //translates word to tutnese and adds it to string tutnese sentence
        } else if (!isspace(sentence[i])){ // while there is no whitespace it will add the characters of the word to a string called word
            word += sentence[i];
        } else if (isspace(sentence[i])){ //once there is a whitespace it translates the english word to tutnese and adds it to the tutnese sentence
            tutnesesentence += translateEnglishWord(word) + " "; //translates english word to tutnese and adds space after it 
            word = ""; // resets word to being empty for the next word in the sentence
        } 
    }

    return tutnesesentence; 
}

/*
* This method is called translateTutneseWord
* This method returns a string called englishword which represents the english translation of a tutnese word
* This method takes a single parameter which is a string called word representing the tutnese word 
*/
string Translator::translateTutneseWord(string word){
    Model *m = new Model();
    string tutnesesyllables = "";
    string englishword = "";
    if(word.length() == 1){ //if word is one letter then return the letter as the english word
        englishword = word;
        return englishword;
    } else {
        for (int i = 0; i < word.length(); ++i){
            if(tutnesesyllables.length() == 1 && ispunct(tutnesesyllables[0])){ //checks for punctation if there is to just add the punctation and move on to next letter
                englishword += tutnesesyllables;
                tutnesesyllables = word[i];
            } else if(tutnesesyllables.length() == 5 && (tutnesesyllables == "squat" || tutnesesyllables == "Squat" || tutnesesyllables == "SquaT" || tutnesesyllables == "squaT")){ //acounts for double vowels with squat in front of the letter and different configurations it could be in
                tutnesesyllables += word[i];
                i += 1; // increments i because we added a letter to tutnesesyllables
                if(tolower(tutnesesyllables[tutnesesyllables.length() - 1]) == 'u' && tolower(word[i]) == 't'){ //accounts for sqauatut
                    tutnesesyllables += word[i];
                    i += 1; //increments i because we added the another letter to tutnesesyllables and dont want to reuse it
                    englishword += m->translateDoubleSyllables(tutnesesyllables); //translates double syllables
                } else {
                    englishword += m->translateDoubleSyllables(tutnesesyllables);
                }
                tutnesesyllables = word[i]; //adds the beginning of the next syllable to tutnesesyllable and erases past syllable
            } else if(tutnesesyllables.length() == 7 && (tutnesesyllables.substr(0, 4) == "squa" || tutnesesyllables.substr(0, 4) == "Squa")){ //accounts for double syllables that are not vowels
                if(tolower(tutnesesyllables[4]) == 'c' || tolower(tutnesesyllables[4]) == 'h' || tolower(tutnesesyllables[4]) == 'k' || tolower(tutnesesyllables[4]) == 'q' || tolower(tutnesesyllables[4]) == 'w'){ //if it is one of the tutnese syllables with four letters then add the last letter and translate
                    tutnesesyllables += word[i];
                    i += 1;
                    englishword += m->translateDoubleSyllables(tutnesesyllables);
                } else {
                    englishword += m->translateDoubleSyllables(tutnesesyllables);
                }
                
                tutnesesyllables = word[i];
            } else if (tutnesesyllables.length() == 2 && tolower(tutnesesyllables[0]) == 'e' && (tolower(tutnesesyllables[1]) == 'x' )) { // accounts for the syllables ex which is the letter x in english
                englishword += m->translateSingleSyllables(tutnesesyllables);
                tutnesesyllables = word[i];
            } else if(tutnesesyllables.length() == 1 && tolower(word[i] != 'x') && (tolower(tutnesesyllables[0]) == 'a' || tolower(tutnesesyllables[0]) == 'e' || tolower(tutnesesyllables[0]) == 'i' || tolower(tutnesesyllables[0]) == 'o' || tolower(tutnesesyllables[0]) == 'u') ){ //accounts for translating vowels to english which are the same in english as tutnese and checks for ex syllable and if no x is after e then treats e as a vowel and translates
                englishword += tutnesesyllables;
                tutnesesyllables = word[i];
            } else if ((tutnesesyllables.length() == 3) && (tolower(tutnesesyllables[0] != 'c')) && (tolower(tutnesesyllables[0] != 'h')) && (tolower(tutnesesyllables[0] != 'k')) && (tolower(tutnesesyllables[0] != 'q')) && (tolower(tutnesesyllables[0] != 'w')) && (tolower(tutnesesyllables[0] != 'e')) && (tutnesesyllables != "squ") && (tutnesesyllables != "Squ")){ //makes sure that we are not beginning translation of double letter and if we are not then checks we are not going to be translating 4 letter syllable and if both are false then translates 3 letter syllable
                englishword += m->translateSingleSyllables(tutnesesyllables);
                tutnesesyllables = word[i];
            } else if ((tutnesesyllables.length() == 4) && (tutnesesyllables != "squa") && (tutnesesyllables != "Squa")) { // translates 4 letter syllables to english letter
                englishword += m->translateSingleSyllables(tutnesesyllables);
                tutnesesyllables = word[i];
            } 
            else { 
                tutnesesyllables += word[i]; //adds letters to words until one of the conditionals above is met
            }
        }
    }
    
    englishword += m->translateSingleSyllables(tutnesesyllables); //translates the last syllable after adding last letter to syllable at end of word

    delete m; //deletes model object
    return englishword;
}

/*
* This method is called translateTutneseSentence
* This method returns a string called englishsentence which represents the english translation of a tutnese sentence
* This method takes a single parameter which is a string called sentence representing a sentence in tutnese
*/
string Translator::translateTutneseSentence(string sentence){
    string tutneseword = "";
    string englishsentence = "";

    for(int i = 0; i < sentence.length(); ++i){ 
        if (i == sentence.length() - 1) { //since there is no whitespace after the last word this accounts for the last word in the sentence
            tutneseword += sentence[i]; //adds the last character of the string to the word  
            englishsentence += translateTutneseWord(tutneseword); //translates tutnese word to english and adds it to string englishsentence
        } else if (!isspace(sentence[i])){ // while there is no whitespace it will add the characters of the word to a string called tutneseword
            tutneseword += sentence[i];
        } else if (isspace(sentence[i])){ //once there is a whitespace it translates the tutnese word to english and adds it to the tutnese sentence
            englishsentence += translateTutneseWord(tutneseword) + " "; //translates tutnese word to english and adds space after it 
            tutneseword = ""; // resets word to being empty for the next word in the sentence
        } 
    }

    return englishsentence;
}