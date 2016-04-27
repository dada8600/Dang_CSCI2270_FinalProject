#include "Dictionary.h"

Dictionary::Dictionary()
{
    //ctor
    root = NULL;
}

Dictionary::~Dictionary()
{
    //dtor
}
void Dictionary::addDictionaryNode(string word, string type, string definition){
    //node declarations
    DictionaryNode *tmp = root;
    DictionaryNode *parent = NULL;
    DictionaryNode *node = new DictionaryNode(word, type, definition);
    while(tmp != NULL){
        parent = tmp;
        //compares to show alphabetical order
        if(node->word.compare(tmp->word) < 0){
            tmp = tmp->leftChild;
        }
        else{
            tmp = tmp->rightChild;
        }
    }
    if(parent == NULL){
        root = node;
    }
    else if(node->word.compare(parent->word) < 0){
        parent->leftChild = node;
        node->parent = parent;
        //cout << "inserted: " << node->word << " left child of: " << parent->word <<endl;
    }
    else{
        parent->rightChild = node;
        node->parent = parent;
        //cout << "inserted: " << node->word << " right child of: " << parent->word <<endl;
    }
}
void Dictionary::findWord(string word){
    DictionaryNode *tmp = root;
    while(tmp != NULL){
        //check if inserted value = existing value
        if(tmp->word == word){
            cout << tmp->word <<" : "<< endl;
            cout << tmp->type <<" : " << tmp->definition<<endl;
        return;
        }
        if(word.compare(tmp->word) < 0){
            tmp = tmp->leftChild;
        }
        else{
            tmp = tmp->rightChild;
        }
    }
    cout << "Word not found." << endl;
}

DictionaryNode *Dictionary::treeMin(DictionaryNode *root){
    DictionaryNode *tmp = root;
    while(tmp ->leftChild !=NULL){
        tmp = tmp->leftChild;
    }
    return tmp;

}
void Dictionary::deleteWord(string word){
    DictionaryNode *tmp = root;
    DictionaryNode *tmp2;
    while(tmp != NULL){
        //check if inserted value = existing value

        if(tmp->word == word){
            //cases for empty conditions
            if(tmp->leftChild == NULL && tmp ->rightChild == NULL){
                if(tmp->parent == NULL){
                    delete tmp;
                    root = NULL;
                    return;
                }
                tmp = tmp->parent;
                if(tmp->leftChild->word == word){
                    delete tmp->leftChild;
                    tmp ->leftChild = NULL;
                    return;
                }
                else{
                    delete tmp->rightChild;
                    tmp->rightChild = NULL;
                    return;
                }
            }
            //case for left child not empty
            else if(tmp->leftChild != NULL && tmp->rightChild == NULL){
                if(tmp->parent == NULL){
                    root = tmp->leftChild;
                    delete tmp;
                    root->parent = NULL;
                    return;
                }
                tmp2 = tmp->parent;
                if(tmp2->leftChild!= NULL && tmp2->leftChild->word == word){
                    tmp2->leftChild = tmp->leftChild;

                }
                else{
                    tmp2->rightChild = tmp->leftChild;
                }
                tmp = tmp->leftChild;
                delete tmp->parent;
                //reconnect tree
                tmp->parent = tmp2;
                return;
            }
            //right child not empty
            else if(tmp->rightChild != NULL && tmp->leftChild == NULL){
                 if(tmp->parent == NULL){
                    root = tmp->rightChild;
                    delete tmp;
                    root->parent = NULL;
                    return;
                }
                tmp2 = tmp->parent;
                if(tmp2->leftChild!= NULL && tmp2->leftChild->word == word){
                    tmp2->leftChild = tmp->rightChild;

                }
                else{
                    tmp2->rightChild = tmp->rightChild;
                }
                tmp = tmp->rightChild;
                delete tmp->parent;
                //reconnect tree
                tmp->parent = tmp2;
                return;
            }
            //both child not empty
            else if(tmp->rightChild != NULL && tmp->leftChild != NULL){
                DictionaryNode *right = tmp->rightChild;
                DictionaryNode *left = tmp->leftChild;
                tmp2 = tmp->parent;             //parent
                tmp = treeMin(tmp->rightChild); //minimum
                if(tmp2 == NULL){
                    delete root;
                    root = tmp;
                }
                //check if input value is equal to left child
                else if(tmp2->leftChild->word == word){
                    //left of parent is the min value
                    tmp2->leftChild = tmp;
                }
                else{
                    //right of parent is min value
                    tmp2->rightChild = tmp;
                }
                //check right of min value is not empty
                if(tmp->rightChild != NULL){
                    tmp->parent->leftChild = tmp->rightChild;
                    tmp->rightChild->parent = tmp->parent;
                }
                else{
                    tmp->parent->leftChild = NULL;
                }
                if(tmp!=root){
                    delete tmp->parent;
                }
                //connect back values
                tmp->parent = tmp2;
                tmp->leftChild = left;
                left->parent = tmp;
                if(right!=tmp){
                    right->parent = tmp;
                    tmp->rightChild = right;
                }
                return;
            }
        }
        if(word.compare(tmp->word) < 0){
            tmp = tmp->leftChild;
        }
        else{
            tmp = tmp->rightChild;
        }
    }
cout << "Word not found." << endl;
}
void Dictionary::printDictionary(){
    printDictionary(root);//starts recursion
}
void Dictionary::printDictionary(DictionaryNode *node){
    //recursive method
    if(node->leftChild !=NULL){
        printDictionary(node->leftChild);
    }
    cout<<"Word: "<<node->word<<endl;
    cout<<"Word type: " <<node->type<<endl;
    cout<<"Definition: "<<node->definition<<endl<<endl;

    if(node->rightChild!=NULL){
        printDictionary(node->rightChild);
    }
}

