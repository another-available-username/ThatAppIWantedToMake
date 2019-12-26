#include "mainwindow.h"
#include "util.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <iostream>
#include <QFileDialog>
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
}

void MainWindow::save() {
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Address Book"), "",
            tr("Address Book (*.abk);;All Files (*)"));
    QString editText = ui->mainEdit->toPlainText();
    Util* util = new Util();
    util->save(fileName, editText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

