/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

#include "fileprocessor.h"

int main(int argc, char** argv){ // main method
    FileProcessor *fp = new FileProcessor(); // creates file processor object to be able to use methods from file processor class

    if(argc < 4) { //checks to see if correct amount of arguments were provided in command line
        cout << "whoops! sorry! There was an incorrect amount of arguments provided." << endl;
        cout << "Please run like: \"./assignment2.out englishfile.txt tutnesefile.txt\"" << endl;
        cout << "                               or                                     " << endl;
        cout << "Please run like: \"./assignment2.out englishfile.txt tutnesefile.txt E2T\"" << endl;
        cout << "                               or                                     " << endl;
        cout << "Please run like: \"./assignment2.out tutnesefile.txt englishfile.txt T2E\"" << endl;

        return -1;
    } 
    //first command line argument would be ./assignment2.out 
    string input = argv[1]; // takes the 2nd argument command line which is the input file 
    string output = argv[2]; // takes the 3rd argument command line which is the output file
    string translationPath = "";
    translationPath = argv[3]; // takes the 4th argument in command line which is which way to translate, E2T is English to Tutnese and T2E is Tutnese to English
    
    if(input.substr(input.length() - 4) != ".txt"){ //check if file has .txt extension
        cout << "please input a .txt file for the input" << endl;

        return -1;
    }else if (output.length() < 4){ //check if file has a .txt extension 
        cout << "please input a .txt file for the output" << endl;

        return -1;
    }

    if(output.substr(output.length() - 4) != ".txt") {
        cout << "please input a .txt file for the output" << endl;

        return -1;
    } else if (output.length() < 4){
        cout << "please input a .txt file for the output" << endl;

        return -1;
    }

    fp->processFile(input, output, translationPath); //translates file depending on translation path from english to tutnese or tutnese to english
    
    

    delete fp; //deletes file processor object now that we are done using it
    return 0;
}