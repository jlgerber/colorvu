#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <QMainWindow>

namespace Ui {
    class MainView;
    }

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

    void addColors(const QStringList &colors);
private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_HPP
