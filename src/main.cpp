#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

#include "ui/navbar.h"
#include "ui/content.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");

    QWidget window;
    window.setWindowTitle("Crab Crawler");
    window.setMinimumSize(800, 600);
    window.resize(800, 600);

    auto *layout = new QVBoxLayout(&window);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    auto *navBar = new NavBar(&window);
    layout->addWidget(navBar);

    auto *content = new Content(&window);
    layout->addWidget(content, 1);

    QObject::connect(navBar, &NavBar::addressEntered, [content](const QString &text)
                     { qDebug() << "navigate to:" << text; });

    window.show();
    return app.exec();
}
