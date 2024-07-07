#include "loginpage.h"
#include "ui_loginpage.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include <windows.h>
#include <QTimer>

loginpage::loginpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginpage)
{
    ui->setupUi(this);

    QPixmap pix(":/images/Resources/file.png");
    int w = ui->label_logo->width();
    int h = ui->label_logo->height();

    ui->label_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

loginpage::~loginpage()
{
    delete ui;
}

void loginpage::on_pushButton_clicked()
{


    if(ui->lineEdit->text()==("amoghraina")&&ui->lineEdit_2->text()==("1.618")){
        color(Qt::green);

        ui->label_status->setText("Success");
        QTimer::singleShot(2000, this, [this]() {
            this->hide();
            MainWindow *mainWindow = new MainWindow();
            mainWindow->setWindowTitle("Calculator");
            QIcon icon(":/images/Resources/file.ico");
            mainWindow->setWindowIcon(icon);
            mainWindow->show();
        });
    }
    else if(ui->lineEdit_2->text()==""&&ui->lineEdit->text()==""){
        ui->label_status->setText("Both fields are empty");
        color(Qt::yellow);

    }
    else if(ui->lineEdit->text()==""){
        color(Qt::yellow);

        ui->label_status->setText("Username is empty");
    }

    else if(ui->lineEdit_2->text()==""){
        color(Qt::yellow);

        ui->label_status->setText("Password is empty");
    }
        else{
        color(Qt::red);

        ui->label_status->setText("Wrong username/password");
        }
}

void loginpage::color(const QColor &color)
{

    QPalette palette;
    palette.setColor(QPalette::WindowText, color);
    ui->label_status->setPalette(palette);

}
