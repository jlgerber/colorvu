#include "mainview.hpp"
#include "ui_mainview.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <QColor>
#include <QBrush>
#include <QStringList>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::addColors(const QStringList& colors) {
    // clear the table
    ui->twColors->clearContents();
    ui->twColors->setRowCount(colors.size());
    qDebug() << "Start table population"<< endl;;
    for(auto r=0;r<colors.size(); r++) {
        auto row_color = colors[r];

        auto* item = new QTableWidgetItem(row_color);
        ui->twColors->setItem(r,0,item );

        item = new QTableWidgetItem("");
        auto color = QColor(row_color);
        auto brush = QBrush(color);
        item->setBackground(brush);
        ui->twColors->setItem(r,1,item );

    }
    //ui->twJoke->resizeColumnsToContents();
    ui->twColors->resizeRowsToContents();
    qDebug() << "End table population"<< endl;;
}
