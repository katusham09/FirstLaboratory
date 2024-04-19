#include "figura.h"
#include <math.h>

void Figura::move(float Alpha,QPainter *Painter)//отвечает за вращение фигуры на заданный угол Alpha и отрисовку её после вращения
{
    //Здесь dx - это смещение по оси X
    //Это позволяет определить, насколько нужно сместить фигуру по оси X после вращения.
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);//dy - это смещение по оси Y
    draw(Painter);//отрисовка фигуры в новом положении
    //Это делается с использованием объекта Painter, который передается в метод move.
    //draw будет вызывать соответствующую функцию отрисовки в зависимости от типа фигуры (линия или квадрата), что позволит отобразить вращенную фигуру на экране.
}

void MyLine::draw(QPainter *Painter)//метод для рисования линии
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//вызываем функцию drawLine объекта Painter, чтобы нарисовать линию между двумя точками.
}

void MyRect::draw(QPainter *Painter)//метод для рисования квадрата
{
    //вызываем функцию drawLine объекта Painter, которая рисует одну из линий квадрата
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
