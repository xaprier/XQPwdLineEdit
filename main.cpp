#include <QApplication>

#include "PasswordLineEdit.hpp"

using namespace xaprier::Qt::Widgets;

void TestNormal() {
    auto *passwordLineEdit = new PasswordLineEdit();
    passwordLineEdit->setWindowTitle("PasswordLineEdit with toggle");
    passwordLineEdit->show();
}

void TestShow() {
    auto *passwordLineEdit = new PasswordLineEdit(false, PasswordLineEdit::SwitchType::Show);
    passwordLineEdit->setWindowTitle("PasswordLineEdit with show");
    passwordLineEdit->show();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TestShow();
    TestNormal();

    return app.exec();
}