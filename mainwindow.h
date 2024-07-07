#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void decimal();
    void digit_pressed();
    void operator_pressed();
    void equals();
    void clear();
private:
    Ui::MainWindow *ui;
    double firstNum;    // Member variables to store first and second numbers
    double secondNum;
    double result = 0;
    bool second_true=false;
    QString operator_storage;
    QVector<int> numbers;
    QVector<QString> operators;
    bool equal_pressed=false;
};

#endif // MAINWINDOW_H
