#include "startup.hpp"
#include "mainview.hpp"
#include "utils.hpp"
#include <QDebug>
#include <QApplication>

Startup::Startup(QObject *parent) :
    QObject(parent),
    m_mainview{*new MainView}
{

    auto *parser = setupParser();
    QStringList colors;
    try {
        colors = processArgs(parser, *qApp);
    } catch( std::exception& e) {
            m_success=false;
            return;
    }
    qDebug() << "Colors:" << colors ;
    m_mainview.addColors(colors);
}

Startup::~Startup() {
    delete &m_mainview;
}

// TODO: move to model class

void Startup::show() {
    m_mainview.show();
}
