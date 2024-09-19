#ifndef AAAAWINDOW_H
#define AAAAWINDOW_H

#include <QMainWindow>

namespace Ui {
class aaaaWindow;
}

class aaaaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit aaaaWindow(QWidget *parent = nullptr);
    ~aaaaWindow();

private:
    Ui::aaaaWindow *ui;
};

#endif // AAAAWINDOW_H
