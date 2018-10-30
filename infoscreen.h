#ifndef INFOSCREEN_H
#define INFOSCREEN_H

#include <QWidget>

namespace Ui {
class infoScreen;
}

class infoScreen : public QWidget
{
    Q_OBJECT

public:
    explicit infoScreen(QWidget *parent = nullptr);
    ~infoScreen();

private:
    Ui::infoScreen *ui;
};

#endif // INFOSCREEN_H
