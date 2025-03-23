#include "PasswordLineEdit.hpp"

using namespace xaprier::Qt::Widgets;

PasswordLineEdit::PasswordLineEdit(bool showPassword, SwitchType type,
                                   const QIcon &hideIcon, const QIcon &showIcon,
                                   QWidget *parent)
    : QLineEdit(parent) {
    m_ShowPassword = showPassword;
    m_Type = type;

    // if the icons are not set, use the default icons
    m_HideIcon = hideIcon.isNull() ? style()->standardIcon(QStyle::SP_DialogCancelButton) : hideIcon;
    m_ShowIcon = showIcon.isNull() ? style()->standardIcon(QStyle::SP_DialogOkButton) : showIcon;

    QAction *action = addAction(m_ShowIcon, QLineEdit::TrailingPosition);
    m_Button = qobject_cast<QToolButton *>(action->associatedWidgets().last());

    if (m_ShowPassword) {
        setEchoMode(QLineEdit::Normal);
        m_Button->setIcon(m_HideIcon);
    } else {
        setEchoMode(QLineEdit::Password);
        m_Button->setIcon(m_ShowIcon);
    }

    m_Button->setCursor(QCursor(::Qt::PointingHandCursor));
    m_Button->setToolTip(QObject::tr("Show/Hide Password"));

    connect(m_Button, &QToolButton::pressed, this, &PasswordLineEdit::sl_OnPressed);
    connect(m_Button, &QToolButton::released, this, &PasswordLineEdit::sl_OnReleased);
}

void PasswordLineEdit::sl_OnPressed() {
    if (m_Type == SwitchType::Toggle) {
        m_ShowPassword = !m_ShowPassword;
    } else {
        m_ShowPassword = true;
    }

    if (m_ShowPassword) {
        m_Button->setIcon(m_HideIcon);
        setEchoMode(QLineEdit::Normal);
    } else {
        m_Button->setIcon(m_ShowIcon);
        setEchoMode(QLineEdit::Password);
    }
}

void PasswordLineEdit::sl_OnReleased() {
    if (m_Type == SwitchType::Show) {
        m_ShowPassword = false;
    }

    if (m_ShowPassword) {
        m_Button->setIcon(m_HideIcon);
        setEchoMode(QLineEdit::Normal);
    } else {
        m_Button->setIcon(m_ShowIcon);
        setEchoMode(QLineEdit::Password);
    }
}

void PasswordLineEdit::SetIcon(const QIcon &hide, const QIcon &show) {
    this->SetHideIcon(hide);
    this->SetShowIcon(show);
}

void PasswordLineEdit::SetHideIcon(const QIcon &icon) {
    m_HideIcon = icon;
    if (m_ShowPassword) {
        m_Button->setIcon(m_HideIcon);
    }
}

void PasswordLineEdit::SetShowIcon(const QIcon &icon) {
    m_ShowIcon = icon;
    if (!m_ShowPassword) {
        m_Button->setIcon(m_ShowIcon);
    }
}

void PasswordLineEdit::SetSwitchType(SwitchType type) {
    m_Type = type;
}

void PasswordLineEdit::SetShowPassword(bool show) {
    m_ShowPassword = show;
    if (m_ShowPassword) {
        m_Button->setIcon(m_HideIcon);
        setEchoMode(QLineEdit::Normal);
    } else {
        m_Button->setIcon(m_ShowIcon);
        setEchoMode(QLineEdit::Password);
    }
}
