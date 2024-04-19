#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtGui>
#include "area.h"

class Window : public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;//кнопка выхода
public:
    Window();//конструктор
};
#endif
