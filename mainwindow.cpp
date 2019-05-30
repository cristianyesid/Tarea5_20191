#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include <QTimer>
Particula *particle = new Particula(3,300,15,10,5);  //Declarando un objeto grafico de la clase Particula
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);

    ui->setupUi(this);
    this->resize(600,700);
    this->setFixedSize(600,700);

    escena = new QGraphicsScene;
    ui->fondo->setScene(escena);

    escena->setSceneRect(0,0,500,500);
    timer->stop();


    escena->addItem(particle); //Agregando el objeto grafico a la escena
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::actualizarEscena()
{

    particle->moverParticula(1, 500);
    particle->colisionParticula(500,500);


}

void MainWindow::on_pushButton_clicked()
{
    timer->start(50);
}
