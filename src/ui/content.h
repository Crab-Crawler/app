#pragma once

#include <QWidget>
#include <QString>
#include <QTextEdit>

class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);

    void parseCrabcontent(const QString &input);

private:
    QTextEdit *display;
};
