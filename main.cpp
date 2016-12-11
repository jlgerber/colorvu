#include "startup.hpp"
#include "utils.hpp"
#include <QApplication>
#include <QDebug>
//#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationVersion("0.1.0");
    QApplication::setOrganizationName("GERBERINC");
    Startup startup;
    if(!startup.isValid()) {
        qDebug() << "ERROR on startup" << endl;
        return 1;
    }
    startup.show();

    return a.exec();
}
