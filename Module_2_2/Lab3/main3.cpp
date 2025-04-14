#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    int max_speed;  //protected для доступа в производ классах
    
private:
    string model;

public:
    Car(const string& model_name, int speed) : model(model_name), max_speed(speed) {} //вызов конструктора базового класса+инициализация поля производного класса
    virtual void printParameters() const { //динам полиморфизм
        cout << "Модель: " << model << endl;
        cout << "Максимальная скорость: " << max_speed << " км/ч" << endl;
    }
    virtual ~Car() {} // Виртуальный деструктор (важно для корректного удаления объектов через указатель на базовый класс)
};

class BigCar : public Car {
private:
    double big_car_weight;  //грузоподъемность в тоннах

public:
    BigCar(const string& model_name, int speed, double weight) : Car(model_name, speed), big_car_weight(weight) {} //вызов конструктора базового класса+инициализация поля производного класса
    void printParameters() const override { //стат полиморфизм
        Car::printParameters();  //вызов функции базового класса
        cout << "Грузоподъемность: " << big_car_weight << " тонн" << endl;
    }
};

int main() {
    cout << "Статический полиморфизм:" << endl;

    Car car("Toyota Camry", 220);
    car.printParameters();  //вызов метода базового класса

    cout << endl;
    
    BigCar bigcar("Volvo FH16", 120, 20.5);
    bigcar.printParameters();  //вызов переопределенного метода производного класса
    
    cout << endl;
    
    cout << "Динамический полиморфизм:" << endl;

    Car* auto1 = new Car("Ford Focus", 200);//указат на баз класс, содержащий объект баз класса
    auto1->printParameters();  //вызов метода баз класса
    delete auto1;
    
    cout << endl;
    
    Car* auto2 = new BigCar("MAN TGX", 110, 18.0);//указат на баз класс, содержащий объект производ класса
    auto2->printParameters();  //вызов метода производ класса через указатель на баз
    delete auto2;
    
    return 0;
}