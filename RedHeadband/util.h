#ifndef UTIL_H
#define UTIL_H

#include <QRunnable>
#include <QString>

using namespace std;

class Util : public QRunnable
{
    QString className;
    QString mainEdit;

    public:
        Util();
        Util(QString mainEdit, QString className) {
            this->mainEdit = mainEdit;
            this->className = className;
        }
        void save(QString path, QString editText);
        void run() override;
        QString getFileName(QString mainEdit);
};

#endif // UTIL_H
