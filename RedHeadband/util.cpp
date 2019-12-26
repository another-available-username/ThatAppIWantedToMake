#include "util.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QByteArray>
#include <QTextStream>

using namespace std;

Util::Util()
{

}

void Util::save(QString path, QString editText) {
    cout << "save() function called in util.cpp" << endl;
    QFile file(path);
    if ( file.open(QIODevice::ReadWrite) ) {
        QTextStream stream(&file);
        stream << editText << endl;
        stream.flush();
    }
    file.close();
}
