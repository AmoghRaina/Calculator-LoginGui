#include <QApplication>
#include "loginpage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    loginpage loginpage;
    loginpage.setWindowTitle("Login Page");
    QIcon icon(":/images/Resources/file.ico");

    // Set the window icon
    loginpage.setWindowIcon(icon);
    loginpage.show();

    return a.exec();
}
