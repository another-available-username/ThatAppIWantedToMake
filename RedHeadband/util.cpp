#include "util.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>

using namespace std;

Util::Util()
{

}

void Util::save(string editText) {
    cout << "save() function called in util.cpp" << endl;
    ofstream myfile;
    myfile.open("Example.txt");
    myfile << editText;
    cout << "Saved: " << editText << endl;
    myfile.close();
}
