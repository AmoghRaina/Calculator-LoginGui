#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleSheet = "QMainWindow {"
                         "  border: 2px solid rgb(0, 0, 0);"
                         "  background-color: rgb(34, 34, 34);"
                         "}";

    setStyleSheet(styleSheet);

    QPushButton *buttons[] = {
        ui->pushButton_0,
        ui->pushButton,

        ui->pushButton_2,
        ui->pushButton_3,
        ui->pushButton_4,
        ui->pushButton_5,
        ui->pushButton_6,
        ui->pushButton_7,
        ui->pushButton_8,
        ui->pushButton_9,
        ui->pushButton_add,
        ui->pushButton_equals,
        ui->pushButton_minus,
        ui->pushButton_divide,
        ui->pushButton_multiply,
        ui->pushButton_clear,

        // Add more buttons as needed
    };
    int numButtons = sizeof(buttons) / sizeof(buttons[0]);

    // Apply stylesheet for hover effect and connect clicked signal
    for (int i = 0; i<numButtons; ++i) {
        QString styleSheet ;/*= "QPushButton:hover { background-color: rgb(141, 141, 141); } "
                             "QPushButton:pressed { background-color: rgb(50, 50, 50); }";
                                buttons[i]->setStyleSheet(styleSheet);*/
        if(buttons[i]==ui->pushButton_add||buttons[i]==ui->pushButton_minus||buttons[i]==ui->pushButton_divide||buttons[i]==ui->pushButton_multiply)
        {
                                    styleSheet =  "QPushButton{color:rgb(87, 197, 85);}";
        }
        else if(buttons[i]==ui->pushButton_equals){
            styleSheet = "QPushButton{color: rgb(255, 245, 108);}";
        }
        else if(buttons[i]==ui->pushButton_clear){
            styleSheet = "QPushButton{color: rgb(255, 23, 23);}";
        }
        else{
            styleSheet = /*"QPushButton:hover { background-color: rgb(141, 141, 141); } "*/
                "QPushButton:pressed { background-color: rgb(50, 50, 50); }";

        }
        buttons[i]->setStyleSheet(styleSheet);
        // connect(buttons[i], SIGNAL(clicked()), this, SLOT(digit_pressed()));
    }


    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(operator_pressed()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operator_pressed()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(operator_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(operator_pressed()));
    connect(ui->pushButton_equals,SIGNAL(clicked()),this,SLOT(equals()));
    connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(clear()));
    connect(ui->pushButton_point,SIGNAL(clicked()),this,SLOT(decimal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed(){

    QPushButton *button = static_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    QString currentText=ui->label->text();
    QString text = currentText+buttonText;

    ui->label->setText(text);

    if(ui->label_operator->text().isEmpty()){
         firstNum = text.toDouble();

    }
    else{
         secondNum = text.toDouble();
        second_true=true;
    }

}
void MainWindow::operator_pressed(){
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString buttonText = button->text();
    operator_storage = ui->label_operator->text();

    ui->label_operator->setText(buttonText);

    if(operator_storage=="+"&&equal_pressed==false){
        result = firstNum+secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);
    }
    if(operator_storage=="-"&&equal_pressed==false){
        result = firstNum-secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);
    }
    if(operator_storage=="*"&&equal_pressed==false){
        result = firstNum*secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);
    }
    if(operator_storage=="/"&&equal_pressed==false){
        result = firstNum/secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);
    }

    if(!ui->label_operator->text().isEmpty()){     /*to clear the number from the label*/
        ui->label_storage->setNum(firstNum);
        ui->label->clear();

    }
    equal_pressed=false;


}
void MainWindow::equals(){
    equal_pressed=true;

    if( ui->label_operator->text()=="+"&&second_true==true){

        result = firstNum+secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);


    }
    if( ui->label_operator->text()=="*"){
        result = firstNum*secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);


    }
    if( ui->label_operator->text()=="/"&&second_true==true){
        result = firstNum/secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);

    }
    if( ui->label_operator->text()=="-"&&second_true==true){
        result = firstNum-secondNum;
        firstNum=result;
        ui->label_storage->setNum(firstNum);

    }
    ui->label->setText(QString::number(result));


}
void MainWindow::clear(){
    ui->label->clear();
    ui->label_operator->clear();
    ui->label_storage->clear();
    firstNum=0;
    secondNum=0;
}
void MainWindow::decimal(){
    if (!ui->label->text().contains(".")) {
        ui->label->setText(ui->label->text() + ".");
    }
}

