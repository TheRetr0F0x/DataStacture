#include <iostream>
#include "Automata.h"
#include "DataStructures.h"
#include "DsHomework.h"
#include <fstream>
using namespace std;



void deleteProduct(Product products[], int& numProducts, const string& name, Stack& undoStack)
{
    Homework ds;
    int index = ds.findProduct(products, numProducts, name);
    if (index != -1) {
        undoStack.push(products[index]);
        for (int i = index; i < numProducts - 1; i++) {
            products[i] = products[i + 1];
        }
        numProducts--;
        cout << "Product deleted" << endl;
    }
    else {
        cout << "Product not found" << endl;
    }
}

void undoDelete(Product products[], int& numProducts, Stack& undoStack) {
    if (!undoStack.empty()) {
        Product p = undoStack.top();
        undoStack.pop();
        products[numProducts] = p;
        numProducts++;
        cout << "Undo successful: " << p.name << endl;
    }
    else {
        cout << "Nothing to undo" << endl;
    }
}

void DisplayArray(string arr[], int size, bool is2D)  // Clear
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}
void Display2dArray(string arr[][25], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{ 
    DataStracture ds;
    Automata autom;
    Homework hw;

    autom.FileSearch("MyFile.txt");
    string word;
    cout << "Language L which: L = {x01y : x,y < {0,1}* }.\n";
    cout << "Enter your word: ";
    getline(std::cin, word);
    autom.nextState(word);
}