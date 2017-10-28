#include <QCoreApplication>
#include <AppActivity.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AppActivity activity;
    return a.exec();
}
