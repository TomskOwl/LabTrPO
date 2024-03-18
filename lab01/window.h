#ifndef window_h
#define window_h

#include <QWidget>
#include <QtGui>
#include "area.h"
class QPushButton;
class Window : public QWidget
{
protected:
//    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
    public:
    Window();
    };

#endif // WINDOW_H
