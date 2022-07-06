#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);
    QColor rellenoBarra1(255, 200, 158);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setBrush(rellenoBarra1);

    //Obtener datos para la primera barra
    int nota1 = ui->inNota1->value();
    int altoN1 = this->getAlto(nota1);
    int incYN1 = this-> incY(altoN1);

    // ############Dibujar primera barra#############################
    painter.drawRect(x+50, y+50+incYN1,100,altoN1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(193, 231, 161);
    // Crear otro objeto color para el borde
    QColor colorBorde(0,0,0);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    //Obtener datos para la segunda nota
    int nota2 = ui->inNota2->value();
    int altoN2 = getAlto(nota2);
    int incYN2 = this-> incY(altoN2);


    // ##########Dibujar segunda barra#########################
    painter.drawRect(x+170, y+50+incYN2, 100, altoN2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(109, 170, 244);
    QColor cBordeBarra3(0,0,0);

    // Estableciendo colores al pincel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Obtener datos para la tercera barra
    int nota3 = ui->inNota3->value();
    int altoN3 = getAlto(nota3);
    int incYN3 = this-> incY(altoN3);
    // #############Dibujar tercera barra######################
    painter.drawRect(x+290,y+50+incYN3,100,altoN3);

    //Dibujar linea horizontal de promedio
    painter.drawRect(x,450-(altoN1+altoN2+altoN3)/3,500,1);

    int notaA = ui->inNota1->value();
    int notaB = ui->inNota2 ->value();
    int notaC = ui->inNota3->value();
    int promedio = (notaA+notaB+notaC)/3;
    ui->outPromedio->setNum(promedio);

    //Barras laterales con números//
    QPen pincel2;
    pincel2.setWidth(5);
    pincel2.setColor(Qt::red);
    painter.setPen(pincel2);
    painter.drawLine(800,470,0,470);
    painter.drawText(90,487,"N1");
    painter.drawLine(30,0,30,800);
    painter.drawText(5,20,"100");
}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::incY(int alto)
{
    return 400 - alto;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}

