#ifndef POPUP_H
#define POPUP_H

#include <QWidget>

namespace Ui {
class popup;
}

class popup : public QWidget
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = nullptr);
    ~popup();

private:
    Ui::popup *ui;
};

#endif // POPUP_H
