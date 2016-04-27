//Danny Dang
//Final Project
//Hoenigman

#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//menu function
void menu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Find a word" << endl;
    cout << "2. Delete a word" << endl;
    cout << "3. Print the Dictionary" << endl;
    cout << "4. Quit" << endl;
}

int main(int argc, char **argv)
{
    //declare variables
    int choice;
    //list of all of the word types in the  360000 line dictionary
    string wTypes[] = {"adj.","—adj.","n.","—n.","n.pl.","v.","—v.","gram.",
    "adv.","Adv.","—adv.","prep.","predic.","symb.","abbr.","Abbr.","prefix","suffix",
    "pl.", "see","int.","comb.","contr.","conj.","attrib.","1st","var.","(brit.",
    "pron.","—pron.","past","—n.pl.","v.aux.","archaic","etc.","N.","compar.","superl.",
    "sing.","poss.","Int.","—interrog.","pres.","(pl.","Pl.","—prep.","objective"};
    Dictionary d;
    string word;
    string str;
    string data;
    ifstream inFile(argv[1]);

    //testing if infile works
    if(!inFile){
        cout<<"File not found."<<endl;
        return -1;
    }
    //reading file
    while(getline(inFile, data)){
        //cout<<data<<endl<<endl;
        stringstream ss(data);
        string word = "", type, definition = "";
        bool wordFinish = false;
        while(!wordFinish){
            ss >> str;
            if(str == "Usage"){
                break;
            }
            //checking word types
            for(int i = 0; i < 47; i++){
                if(str == wTypes[i]){
                    type = str;
                    wordFinish = true;
                    break;
                }
            }
            if(!wordFinish){
                word += " "+str;
            }
        }
        while(ss>> str){
            definition += " "+str;
        }
        //adding dictionary
        d.addDictionaryNode(word,type,definition);
        //used for testing textfile
        //cout<<"Type: "<<type<<endl<< "word: "<<word<<endl<<"definition: "<<definition<<endl<<endl;
        //string tmp;
        //cin>>tmp;
    }
    while(choice != 4){
        menu();
        cin >>choice;
        //switch runs all methods
        switch(choice){
            case 1:
                cout << "Enter word:" << endl;
                cin.ignore();
                getline(cin,word);
                word = " "+word;
                d.findWord(word);
                break;
            case 2:
                cout << "Enter Word:" << endl;
                cin.ignore();
                getline(cin,word);
                word = " "+word;
                d.deleteWord(word);
                break;
            case 3:
                d.printDictionary();
                break;
            case 4:
                break;
            default:
                //error check
                cout<<"Error, try again."<<endl;
                break;
        }
    }
    cout<<"Goodbye!"<<endl;
    inFile.close();
    return 0;
}
