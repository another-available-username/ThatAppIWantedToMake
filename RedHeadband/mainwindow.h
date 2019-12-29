#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class Console;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void initSlots();
    ~MainWindow();
public slots:
    void save();
    void load();
    void run();

private:
    Ui::MainWindow *ui;
    Ui::Console *cUi;
};
#endif // MAINWINDOW_H
