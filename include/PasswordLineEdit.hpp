#ifndef PASSWORDLINEEDIT_HPP
#define PASSWORDLINEEDIT_HPP

#include <QAction>
#include <QIcon>
#include <QLineEdit>
#include <QToolButton>

namespace xaprier {
namespace Qt {
namespace Widgets {

class PasswordLineEdit : public QLineEdit {
    Q_OBJECT
  public:
    enum SwitchType {
        Toggle,
        Show,
    };

    PasswordLineEdit(bool showPassword = false, SwitchType type = Toggle, const QIcon &hideIcon = QIcon(":/icons/eyeOff.png"),
                     const QIcon &showIcon = QIcon(":/icons/eyeOn.png"), QWidget *parent = nullptr);

    void SetIcon(const QIcon &hide, const QIcon &show);
    void SetHideIcon(const QIcon &icon);
    void SetShowIcon(const QIcon &icon);

    void SetSwitchType(SwitchType type);
    void SetShowPassword(bool show);

  private slots:
    void sl_OnReleased();
    void sl_OnPressed();

  private:
    QToolButton *m_Button;
    bool m_ShowPassword;
    SwitchType m_Type;
    QIcon m_HideIcon, m_ShowIcon;
};

}  // namespace Widgets
}  // namespace Qt
}  // namespace xaprier

#endif  // PASSWORDLINEEDIT_HPP