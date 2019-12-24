#include "mainwindow.h"
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
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::save);
}

void MainWindow::save() {
    bool ok;
    QInputDialog::getText(this, "Input the number to change with",
                              "Number val: ", QLineEdit::Normal, "", &ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

