
#pragma once
#include <QObject>

class MainView;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent=0);
    void show();
    ~Startup();
    bool isValid() const {return m_success;}

private:
    MainView& m_mainview;
    bool m_success=true;
    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;

};



