#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

#include "ui/navbar.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(800, 500);

    auto *layout = new QVBoxLayout(&window);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    auto *navBar = new NavBar(&window);
    layout->addWidget(navBar);
    layout->addStretch();

    QObject::connect(navBar, &NavBar::addressEntered, [](const QString &text)
                     { qDebug() << "navigate to:" << text; });

    window.show();
    return app.exec();
}
