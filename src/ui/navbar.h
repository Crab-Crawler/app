#pragma once

#include <QWidget>

class QToolButton;
class QLineEdit;

class NavBar : public QWidget
{
    Q_OBJECT

public:
    explicit NavBar(QWidget *parent = nullptr);

    QLineEdit *addressBar() const;

signals:
    void backClicked();
    void forwardClicked();
    void refreshClicked();
    void addressEntered(const QString &text);

private:
    QToolButton *m_back;
    QToolButton *m_forward;
    QToolButton *m_refresh;
    QLineEdit   *m_address;
};
