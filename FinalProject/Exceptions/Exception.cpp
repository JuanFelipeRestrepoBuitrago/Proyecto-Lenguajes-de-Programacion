//
// Created by Usuario on 9/11/2022.
//

#include "Exception.h"
#include "../GUI/notifydialog.h"

const char *NoTextException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Input Error");
    dialog.setPlainText(QString::fromStdString("No text was entered, please try again"));
    dialog.setModal(true);
    dialog.exec();

    return "No text was entered, please try again";
}
