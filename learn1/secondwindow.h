#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
};

#endif // SECONDWINDOW_H
