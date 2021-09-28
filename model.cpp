/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the logic for the Model class and translates single and double characters from english to tutnese
// and also contains methods to translate tutnese syllables to english characters

#include "model.h"

Model::Model(){

}

Model::~Model(){

}

/*
* This is the translateSingleCharacter method
* This method returns a string representing the tutnese translation of the english character
* This method takes in a single parameter of char type representing the a character in the english language
*/
string Model::translateSingleCharacter(char letter){
    string tutnese = "";
    if (letter == 'B'){ // Capitalization is preserved for all capital letters
        tutnese = "Bub";
    } else if (letter == 'b'){
        tutnese = "bub";
    } else if (letter == 'C') {
        tutnese = "Cash";
    } else if (letter == 'c') {
        tutnese = "cash";
    } else if (letter == 'D') {
        tutnese = "Dud";
    } else if (letter == 'd') {
        tutnese = "dud";
    } else if (letter == 'F') {
        tutnese = "Fuf";
    } else if (letter == 'f') {
        tutnese = "fuf";
    } else if (letter == 'G') {
        tutnese = "Gug";
    } else if (letter == 'g') {
        tutnese = "gug";
    } else if (letter == 'H') {
        tutnese = "Hash";
    } else if (letter == 'h') {
        tutnese = "hash";
    } else if (letter == 'J') {
        tutnese = "Jay";
    } else if (letter == 'j') {
        tutnese = "jay";
    } else if (letter == 'K') {
        tutnese = "Kuck";
    } else if (letter == 'k') {
        tutnese = "kuck";
    } else if (letter == 'L') {
        tutnese = "Lul";
    } else if (letter == 'l') {
        tutnese = "lul";
    } else if (letter == 'M') {
        tutnese = "Mum";
    } else if (letter == 'm') {
        tutnese = "mum";
    } else if (letter == 'N') {
        tutnese = "Nun";
    } else if (letter == 'n') {
        tutnese = "nun";
    } else if (letter == 'P') {
        tutnese = "Pub";
    } else if (letter == 'p') {
        tutnese = "pub";
    } else if (letter == 'Q') {
        tutnese = "Quack";
    } else if (letter == 'q') {
        tutnese = "quack";
    } else if (letter == 'R') {
        tutnese = "Rug";
    } else if (letter == 'r') {
        tutnese = "rug";
    } else if (letter == 'S') {
        tutnese = "Sus";
    } else if (letter == 's') {
        tutnese = "sus";
    } else if (letter == 'T') {
        tutnese = "Tut";
    } else if (letter == 't') {
        tutnese = "tut";
    } else if (letter == 'V') {
        tutnese = "Vuv";
    } else if (letter == 'v') {
        tutnese = "vuv";
    } else if (letter == 'W') {
        tutnese = "Wack";
    } else if (letter == 'w') {
        tutnese = "wack";
    } else if (letter == 'X') {
        tutnese = "Ex";
    }else if (letter == 'x') {
        tutnese = "ex";
    } else if (letter == 'Y') {
        tutnese = "Yub";
    } else if (letter == 'y') {
        tutnese = "yub";
    } else if (letter == 'Z') {
        tutnese = "Zub";
    } else if (letter == 'z') {
        tutnese = "zub";
    } else {
        tutnese = letter;
    }

    return tutnese;
}

/*
* This is the translateDoubleCharacter method
* This method returns a string representing the tutnese translation of a english character that appeared twice in a row. 
* This method has a single parameter of char called letter that represents an english character that appeared twice in a row 
*/
string Model::translateDoubleCharacter(char letter){
    string tutnese = "";
    //only need squat because first letter of the double character will be transformed to squat and the
    //second letter of the double character will be added to that. so in oo the first o will become squat
    //and become the prefix for the second o and become squato in translator class
    if (letter == 'a'){  
        tutnese = "squat";
    } else if (letter == 'e') {
        tutnese = "squat";
    } else if (letter == 'i') {
        tutnese = "squat";
    } else if (letter == 'o') {
        tutnese = "squat";
    } else if (letter == 'u') {
        tutnese = "squat";
    } else if (letter == 'A'){ 
        tutnese = "Squat";
    } else if (letter == 'E') {
        tutnese = "Squat";
    } else if (letter == 'I') {
        tutnese = "Squat";
    } else if (letter == 'O') {
        tutnese = "Squat";
    } else if (letter == 'U') {
        tutnese = "Squat";
    } else if (isupper(letter)){
        tutnese = "Squa";
    } else {
        tutnese = "squa";
    }

    return tutnese;
}

/*
* This is the translateSingleSyllables method
* This method returns a character representing the translation of tutnese syllables
* This method has a single parameter of string called syllables, syllables represents tutnese syllables
*/
char Model::translateSingleSyllables(string syllables){
    char english;

    if (syllables == "Bub"){
        english = 'B';
    } else if (syllables == "bub"){
        english = 'b';
    } else if (syllables == "Cash"){
        english = 'C';
    } else if (syllables == "cash"){
        english = 'c';
    } else if (syllables == "Dud"){
        english = 'D';
    } else if (syllables == "dud"){
        english = 'd';
    } else if (syllables == "Fuf"){
        english = 'F';
    } else if (syllables == "fuf"){
        english = 'f';
    } else if (syllables == "Gug"){
        english = 'G';
    } else if (syllables == "gug"){
        english = 'g';
    } else if (syllables == "Hash"){
        english = 'H';
    } else if (syllables == "hash"){
        english = 'h';
    } else if (syllables == "Jay"){
        english = 'J';
    } else if (syllables == "jay"){
        english = 'j';
    } else if (syllables == "Kuck"){
        english = 'K';
    } else if (syllables == "kuck"){
        english = 'k';
    } else if (syllables == "Lul"){
        english = 'L';
    } else if (syllables == "lul"){
        english = 'l';
    } else if (syllables == "Mum"){
        english = 'M';
    } else if (syllables == "mum"){
        english = 'm';
    } else if (syllables == "Nun"){
        english = 'N';
    } else if (syllables == "nun"){
        english = 'n';
    } else if (syllables == "Pub"){
        english = 'P';
    } else if (syllables == "pub"){
        english = 'p';
    } else if (syllables == "Quack"){
        english = 'Q';
    } else if (syllables == "quack"){
        english = 'q';
    } else if (syllables == "Rug"){
        english = 'R';
    } else if (syllables == "rug"){
        english = 'r';
    } else if (syllables == "Sus"){
        english = 'S';
    } else if (syllables == "sus"){
        english = 's';
    } else if (syllables == "Tut"){
        english = 'T';
    } else if (syllables == "tut"){
        english = 't';
    } else if (syllables == "Vuv"){
        english = 'V';
    } else if (syllables == "vuv"){
        english = 'v';
    } else if (syllables == "Wack"){
        english = 'W';
    } else if (syllables == "wack"){
        english = 'w';
    } else if (syllables == "Ex"){
        english = 'X';
    } else if (syllables == "ex"){
        english = 'x';
    } else if (syllables == "Yub"){
        english = 'Y';
    } else if (syllables == "yub"){
        english = 'y';
    } else if (syllables == "Zub"){
        english = 'Z';
    } else if (syllables == "zub"){
        english = 'z';
    } else {
        english = syllables[0];
    }
    

    return english;
}

/*
* This is the translateDoubleSyllables method
* This method returns a string representing the english translation of a tutnese syllable that was indicated as a double syllable
* This method has a single parameter of string called syllables, representing the tutnese syllables that was indicated as doubled
*/
string Model::translateDoubleSyllables(string syllables){
    string english = "";

    if(syllables == "squatut"){
        char c = translateSingleSyllables(syllables.substr(4, syllables.length()));
        english += c;
        english += c; 
    } else if(syllables == "Squatut"){
        char c = translateSingleSyllables(syllables.substr(4, syllables.length()));
        english += toupper(c);
        english += c;
    } else if (syllables == "squaTut") {
        char c = translateSingleSyllables(syllables.substr(4, syllables.length()));
        english += tolower(c); //lowercase the first character since squa is lowercase
        english += c;
    } else if (syllables.substr(0, 5) == "squat"){
        char c = syllables[5];
        english += c;
        english += c;   
    } else if (syllables.substr(0, 5) == "Squat" ){
        char c = translateSingleSyllables(syllables.substr(5, syllables.length()));
        english += toupper(c);
        english += c; 
    } else if(syllables.substr(0, 4) == "squa"){
        char c = translateSingleSyllables(syllables.substr(4, syllables.length()));
        english += c;
        english += c; 
    } else if (syllables.substr(0, 4) == "Squa"){
        char c = translateSingleSyllables(syllables.substr(4, syllables.length()));
        english += toupper(c);
        english += c; 
    } 
    
    
    return english;
}

