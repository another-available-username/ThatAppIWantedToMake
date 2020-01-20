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
#include <QTemporaryFile>
#include <QDir>
#include <QStringList>
#include <QThreadPool>
#include <QRunnable>
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
    Util* util = new Util();
    QString mainEdit = ui->mainEdit->toPlainText();
    QString className = util->getFileName(mainEdit);
    qDebug() << "In MainWindow::run(), className at: " << className;

    // Will delete the task immediately after it's finished.
    // QThreadPool has functions like setMaxThreadCount() and setExpiryTimerout().
    QThreadPool::globalInstance() -> start(new Util(mainEdit, className));
}

MainWindow::~MainWindow()
{
    delete ui;
}

