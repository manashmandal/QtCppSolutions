#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QLabel>
#include <QListWidgetItem>
#include <QListWidget>
#include <QVBoxLayout>
#include <QtGui>
#include <QPushButton>
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;

    QLabel* title = new QLabel("Custom widgets on a QListWidget");
    title->setAlignment(Qt::AlignHCenter);

    QListWidget* list = new QListWidget;
    list->addItem("foo");


    for (int i = 0; i < 5; i++){
        QListWidgetItem* item;
        item = new QListWidgetItem(list);
        list->addItem(item);
//        QPushButton* button = new QPushButton("hey");
        Form *f = new Form;
        item->setSizeHint(f->minimumSizeHint());
        list->setItemWidget(item, f);
    }
    list->addItem("bar");

    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(title);
    layout->addWidget(list);
    window.setLayout(layout);

    window.show();

    return a.exec();
}
