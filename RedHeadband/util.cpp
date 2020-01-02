#include "util.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>

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

QString Util::getFileName(QString mainEdit) {
    QRegExp classHeaderPattern("class\\s+[a-zA-Z]+");
    classHeaderPattern.indexIn(mainEdit);
    QString classHeader = classHeaderPattern.capturedTexts().at(0);

    qDebug() << "In Uti::getFileName(), classHeader is: " << classHeader;

    return classHeader.mid(6, classHeader.length() - 1);
}
