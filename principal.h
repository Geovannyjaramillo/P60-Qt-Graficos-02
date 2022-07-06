#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_actionGuardar_triggered();

    void on_inNota1_valueChanged(int arg1);

    void on_inNota2_valueChanged(int arg1);

    void on_inNota3_valueChanged(int arg1);

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar();
    int getAlto(int valor);
    int incY(int alto); //incremento en Y
};
#endif // PRINCIPAL_H
