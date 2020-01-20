#include "util.h"
#include "mainwindow.h"
#include "ui_output.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>
#include <QProcess>

using namespace std;

Util::Util()
{

}

void Util::run(){
    QFile file(className + ".java");
    file.open(QIODevice::ReadWrite);
    qDebug() << "In MainWindow::run(), file name at: " << file.fileName();

    QTextStream stream(&file);
    stream << mainEdit;
    stream.flush();
    file.seek(0);
    qDebug() << "In MainWindow::run(), file contents at: " << file.readAll();

    QProcess javacExec;
    QString compile = "javac " + file.fileName();
    javacExec.start(compile);
    javacExec.waitForFinished(); // This is super convenient.
    QString compileResult(javacExec.readAllStandardOutput());
    qDebug() << "In MainWindow::run(), compile result at: " << compileResult;

    QProcess javaExec;
    QString exec = "java " + file.fileName().remove(".java");
    javaExec.start(exec);
    javaExec.waitForFinished();
    QString output(javaExec.readAllStandardOutput());
    qDebug() << "In MainWindow::run(), ouput at: " << output << endl;

    QWidget *wdg = new QWidget;
    Ui::Console consoleUi;
    consoleUi.setupUi(wdg); // Sets up the user interface for specified widget, which intializes all the forms within the Ui.
    consoleUi.ConsoleOutput->setText(output);
    wdg->show();
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
