#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QMainWindow> //осн класс для создания глав окон

namespace Ui {
class statisticswindow;
}

class statisticswindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit statisticswindow(QWidget *parent = nullptr);
    ~statisticswindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::statisticswindow *ui;
    bool parseFileLine(const QString &line, QDate &date, int &systolic, int &diastolic, int &pulse);
    void displayAverages(double avgSystolic, double avgDiastolic, double avgPulse);
    void displayError(const QString &message);
};

#endif
