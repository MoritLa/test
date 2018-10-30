#ifndef COCKPITSCREEN_H
#define COCKPITSCREEN_H

#include <QWidget>

namespace Ui {
class CockpitScreen;
}

class CockpitScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CockpitScreen(QWidget *parent = nullptr);
    ~CockpitScreen();

private:
    Ui::CockpitScreen *ui;
};

#endif // COCKPITSCREEN_H
