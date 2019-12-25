#include "mainwindow.h"
#include "util.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <iostream>
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
    QString editText = ui->mainEdit->toPlainText();
    string saveText = editText.toStdString();
    Util* util = new Util();
    util->save(saveText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

