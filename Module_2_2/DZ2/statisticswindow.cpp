#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QMessageBox>

statisticswindow::statisticswindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::statisticswindow)
{
    ui->setupUi(this);
}

statisticswindow::~statisticswindow()
{
    delete ui;
}

void statisticswindow::on_pushButton_clicked()
{
    QDate selectedDate = ui->dateEdit->date();

    QFile file("pressure_data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        displayError("Файл с данными не найден");
        return;
    }

    int count = 0;
    double sumSystolic = 0, sumDiastolic = 0, sumPulse = 0;

    QTextStream in(&file);
    while(!in.atEnd()) {
        QDate recordDate;
        int systolic, diastolic, pulse;

        if(parseFileLine(in.readLine(), recordDate, systolic, diastolic, pulse)) {
            if(recordDate >= selectedDate) {      //Проверка соответствия дате (если указана)
                sumSystolic += systolic;
                sumDiastolic += diastolic;
                sumPulse += pulse;
                count++;
            }
        }
    }
    file.close();

    if(count > 0) {
        double avgSystolic = sumSystolic / count;
        double avgDiastolic = sumDiastolic / count;
        double avgPulse = sumPulse / count;
        displayAverages(avgSystolic, avgDiastolic, avgPulse);
    } else {
        displayError("Нет данных для анализа");
    }
}

bool statisticswindow::parseFileLine(const QString &line, QDate &date, int &systolic, int &diastolic, int &pulse) {
    QStringList parts = line.split(';');
    if(parts.size() != 4) return false;

    QDateTime dt = QDateTime::fromString(parts[0], "dd.MM.yyyy hh:mm");
    if(!dt.isValid()) return false;

    date = dt.date();

    bool ok;
    systolic = parts[1].toInt(&ok);
    if(!ok) return false;

    diastolic = parts[2].toInt(&ok);
    if(!ok) return false;

    pulse = parts[3].toInt(&ok);
    return ok;
}

void statisticswindow::displayAverages(double avgSystolic, double avgDiastolic, double avgPulse) {
    ui->textEdit->setText(QString::number(avgSystolic, 'f', 1));
    ui->textEdit_2->setText(QString::number(avgDiastolic, 'f', 1));
    ui->textEdit_3->setText(QString::number(avgPulse, 'f', 1));
}

void statisticswindow::displayError(const QString &message) {
    ui->textEdit->setText(message);
    ui->textEdit_2->setText(message);
    ui->textEdit_3->setText(message);
}

void statisticswindow::on_pushButton_2_clicked()
{
    this->close(); //*this.close()
}

