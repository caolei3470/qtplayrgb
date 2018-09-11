#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"D:\\rgb");
            if(!fileName.isEmpty())
            {
                QFile file(fileName);
                file.open(QIODevice::ReadOnly);
                QByteArray by = file.readAll();
                QImage image((uchar *)by.data(),752,1334,QImage::Format_ARGB32);
                QImage img=image.scaled(ui->imagelabel->width(),ui->imagelabel->height(),Qt::KeepAspectRatio);

                ui->imagelabel->setPixmap(QPixmap::fromImage(img));
            }

}

