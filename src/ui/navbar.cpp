#include "navbar.h"

#include <QToolButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QStyle>

NavBar::NavBar(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(6, 6, 6, 6);
    layout->setSpacing(6);

    m_back = new QToolButton(this);
    m_back->setIcon(style()->standardIcon(QStyle::SP_ArrowBack));
    m_back->setAutoRaise(true);

    m_forward = new QToolButton(this);
    m_forward->setIcon(style()->standardIcon(QStyle::SP_ArrowForward));
    m_forward->setAutoRaise(true);

    m_refresh = new QToolButton(this);
    m_refresh->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    m_refresh->setAutoRaise(true);

    m_address = new QLineEdit(this);
    m_address->setPlaceholderText("Enter a URL");
    m_address->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    layout->addWidget(m_back);
    layout->addWidget(m_forward);
    layout->addWidget(m_refresh);
    layout->addWidget(m_address);

    connect(m_back, &QToolButton::clicked, this, &NavBar::backClicked);
    connect(m_forward, &QToolButton::clicked, this, &NavBar::forwardClicked);
    connect(m_refresh, &QToolButton::clicked, this, &NavBar::refreshClicked);

    connect(m_address, &QLineEdit::returnPressed, this, [this] {
        emit addressEntered(m_address->text());
    });
}

QLineEdit *NavBar::addressBar() const
{
    return m_address;
}
