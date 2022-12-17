#ifndef SPRPOLZOVAT_H
#define SPRPOLZOVAT_H
#include <QDialog>

namespace Ui {
class SPRPOLZOVAT;
}

class SPRPOLZOVAT : public QDialog
{
    Q_OBJECT

public:
    explicit SPRPOLZOVAT(QWidget *parent = nullptr);
    ~SPRPOLZOVAT();


private:
    Ui::SPRPOLZOVAT *ui;
};

#endif // SPRPOLZOVAT_H
