#include "mainwindow.h"
#include "ui_mainwindow.h" //Здесь уже полное определение Ui::MainWindow

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //Настройка интерфейса
    statsWindow = new statisticswindow(this); //Создает новое стат окно с этим окном в качестве родителя(закроют родителя->закроется стат окно)
}

MainWindow::~MainWindow()
{
    delete ui;
    delete statsWindow; //перестраховка
}

void MainWindow::on_pushButton_clicked()
{
    QString systolicText = ui->lineEdit->text();
    QString diastolicText = ui->lineEdit_2->text();
    QString pulseText = ui->lineEdit_3->text();

    if(systolicText.isEmpty() || diastolicText.isEmpty() || pulseText.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля");
        return;
    }

    bool ok1, ok2, ok3;
    int systolic = systolicText.toInt(&ok1); //Преобразуем в числа
    int diastolic = diastolicText.toInt(&ok2);
    int pulse = pulseText.toInt(&ok3);

    if(!ok1 || !ok2 || !ok3){
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите числовые значения");
        return;
    }

    if (systolic < 50 || systolic > 250 || diastolic < 30 || diastolic > 150 || pulse < 30 || pulse > 200) {
        QMessageBox::warning(this, "Ошибка", "Введите корректное значение");
        return;
    }

    saveToFile(systolic, diastolic, pulse);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    QMessageBox::information(this, "Успех", "Данные успешно сохранены");
}

void MainWindow::on_pushButton_2_clicked()
{
    statsWindow->show();
}

void MainWindow::saveToFile(int systolic, int diastolic, int pulse){
    QFile file("/Users/annatucina/projects/study/DZ2/pressure_data.txt");
    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);//получение адреса
        QDateTime currentDateTime = QDateTime::currentDateTime();
        stream << currentDateTime.toString("dd.MM.yyyy hh:mm") << ";" << systolic << ";" << diastolic << ";" << pulse << "\n";
        file.close();
    } else{
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для записи");
    }
}
