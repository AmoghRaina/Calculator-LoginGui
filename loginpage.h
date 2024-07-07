#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include <QLabel>
#include <QDialog>
namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    ~loginpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginpage *ui;
    void color(const QColor &color);
};

#endif // LOGINPAGE_H
