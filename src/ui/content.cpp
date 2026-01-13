#include "content.h"

#include <QVBoxLayout>
#include <QDebug>

Content::Content(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    display = new QTextEdit(this);
    display->setReadOnly(true);

    layout->addWidget(display);
}

void Content::parseCrabcontent(const QString &input)
{
    QStringList lines = input.split('\n', Qt::SkipEmptyParts);
    QString result;

    for (const QString &line : lines)
    {
        if (line.startsWith("text:"))
        {
            result += "<p>" + line.mid(5).trimmed() + "</p>\n";
        }
    }

    display->setHtml(result);
}
