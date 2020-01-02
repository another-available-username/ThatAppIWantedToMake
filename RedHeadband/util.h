#ifndef UTIL_H
#define UTIL_H

#include <QString>

using namespace std;

class Util
{
public:
    Util();
    void save(QString path, QString editText);
    QString getFileName(QString mainEdit);
};

#endif // UTIL_H
