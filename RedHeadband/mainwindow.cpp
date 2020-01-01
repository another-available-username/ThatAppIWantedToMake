#include "mainwindow.h"
#include "util.h"
#include "ui_mainwindow.h"
#include "ui_output.h"

#include <QDebug>
#include <QInputDialog>
#include <iostream>
#include <QFileDialog>
#include <stdlib.h>
#include <QProcess>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSlots();
}

void MainWindow::initSlots() {
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::save);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::load);
    connect(ui->runButton, &QPushButton::clicked, this, &MainWindow::run);
}

void MainWindow::save() {
    // Was previously trying to use the QFileDialog in util.cpp,
    // but the first parameter needed QWidget, which is the MainWindow.
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Address Book"), "",
            tr("Address Book (*.abk);;All Files (*)"));
    QString editText = ui->mainEdit->toPlainText();
    Util* util = new Util();
    util->save(fileName, editText);
}

void MainWindow::load() {
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "",
            tr("Text files (*.java *.txt *.cpp *.h)"));
    qDebug() << "fileName at: " << fileName << endl;
    QFile file;
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        return;
    } else {
        QTextStream in(&file);
        QString fileInput = in.readAll();
        qDebug() << fileInput;
        file.close();
        ui->mainEdit->clear();
        ui->mainEdit->append(fileInput);
    }
}

void MainWindow::run() {
    QProcess javaExec;
    QString exec = "java HelloWorld";
    javaExec.start(exec);
    javaExec.waitForFinished();
    QString output(javaExec.readAllStandardOutput());
    qDebug() << output << endl;

    QWidget *wdg = new QWidget;
    Ui::Console consoleUi;
    consoleUi.setupUi(wdg);
    consoleUi.ConsoleOutput->setText(output);
    wdg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

