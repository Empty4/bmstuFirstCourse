#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

// Класс "Банковский вклад" (остается таким же, как в предыдущем ответе)
class Deposit {
public:
    // Конструктор по умолчанию
    Deposit() : name(""), amount(0.0), currency(""), interestRate(0.0) {}

    // Конструктор с параметрами
    Deposit(const string& n, double a, const string& c, double r) :
        name(n), amount(a), currency(c), interestRate(r) {}

    // Конструктор копирования
    Deposit(const Deposit& other) :
        name(other.name), amount(other.amount), currency(other.currency), interestRate(other.interestRate) {}

    // Конструктор перемещения
    Deposit(Deposit&& other) noexcept :
        name(std::move(other.name)), amount(std::move(other.amount)),
        currency(std::move(other.currency)), interestRate(std::move(other.interestRate)) {}

    // Операция присваивания с копированием
    Deposit& operator=(const Deposit& other) {
        if (this != &other) {
            name = other.name;
            amount = other.amount;
            currency = other.currency;
            interestRate = other.interestRate;
        }
        return this;
    }

    // Операция присваивания с перемещением
    Deposit& operator=(Deposit&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            amount = std::move(other.amount);
            currency = std::move(other.currency);
            interestRate = std::move(other.interestRate);
        }
        return this;
    }

    // Перегрузка оператора вставки в поток
    friend ostream& operator<<(ostream& os, const Deposit& deposit) {
        os << "Название: " << deposit.name << endl;
        os << "Сумма: " << deposit.amount << " " << deposit.currency << endl;
        os << "Ставка: " << deposit.interestRate << "%" << endl;
        return os;
    }

    // Методы получения данных
    string getName() const { return name; }
    double getAmount() const { return amount; }
    string getCurrency() const { return currency; }
    double getInterestRate() const { return interestRate; }

private:
    string name;
    double amount;
    string currency;
    double interestRate;
};

// Функция сравнения для сортировки по сумме вклада
bool compareDepositsByAmount(const Deposit& d1, const Deposit& d2) {
    return d1.getAmount() < d2.getAmount();
}

int main() {
    // Чтение данных из файла
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    vector<Deposit> deposits;
    string name, currency;
    double amount, interestRate;

    while (inputFile >> name >> amount >> currency >> interestRate) {
        deposits.push_back(Deposit(name, amount, currency, interestRate));
    }

    inputFile.close();

    // Создание и заполнение контейнера set
    set<Deposit, decltype(compareDepositsByAmount)> depositSet(compareDepositsByAmount);
    for (const Deposit& deposit : deposits) {
        depositSet.insert(deposit);
    }

    // Создание и заполнение контейнера unordered_set
    unordered_set<Deposit> depositUnorderedSet;
    for (const Deposit& deposit : deposits) {
        depositUnorderedSet.insert(deposit);
    }

    // Вывод контейнера set
    cout << "Контейнер set (отсортированный):" << endl;
    for (const Deposit& deposit : depositSet) {
        cout << deposit << endl;
    }

    // Вывод контейнера unordered_set
    cout << "Контейнер unordered_set (неотсортированный):" << endl;
    for (const Deposit& deposit : depositUnorderedSet) {
        cout << deposit << endl;
    }

    return 0;
}