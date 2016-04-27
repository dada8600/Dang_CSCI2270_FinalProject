#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
using namespace std;

struct DictionaryNode{
    string word, type, definition;
    DictionaryNode *parent;
    DictionaryNode *leftChild;
    DictionaryNode *rightChild;

    DictionaryNode(){};

    DictionaryNode(string in_word, string in_type, string in_definition)
    {
        word = in_word;
        type = in_type;
        definition = in_definition;
        parent =NULL;
        leftChild =NULL;
        rightChild = NULL;
    }

};

class Dictionary
{
    public:
        Dictionary();
        ~Dictionary();
        void printDictionary();
        void printDictionary(DictionaryNode * node);
        void addDictionaryNode(string word, string type, string definition);
        void findWord(string word);
        void deleteWord(string word);
    protected:
    private:
        DictionaryNode *root;
        DictionaryNode *treeMin(DictionaryNode *root);
};

#endif // DICTIONARY_H
