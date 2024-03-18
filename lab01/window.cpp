#include "window.h"
#include <QPushButton>
#include <QVBoxLayout>

Window::Window()
{
//codec = QTextCodec::codecForName("Windows-1251");
this->setWindowTitle("Обработка событий");
area = new Area( this );
btn = new QPushButton("Завершить");
QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(area);
layout->addWidget(btn);
connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};
