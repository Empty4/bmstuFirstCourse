#ifndef MAINWINDOW_H //if MAINWINDOW_H dont work->do nothing
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include "statisticswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { //включает метод setupUi который настраивает интерфейс
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //macros for slot's working

public:
    MainWindow(QWidget *parent = nullptr); //если parent != nullptr то виджет надо удалять самостоятельно в диструкторе
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; // Указатель на сгенерированный UI
    statisticswindow *statsWindow; // Указатель на окно статистики
    void saveToFile(int systolic, int diastolic, int pulse);
};
#endif
