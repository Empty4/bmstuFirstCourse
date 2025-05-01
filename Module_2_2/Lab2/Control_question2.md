# Перегрузка операторов в C++  

## 1. Способы перегрузки операций в C++  

Перегрузка операторов позволяет определить поведение операторов (+, -, =, <<, >> и др.) для пользовательских типов (классов).  

### Способы перегрузки:  
1. Как метод класса  
   - Оператор вызывается для объекта класса.  
   - Левый операнд — сам объект (this).  
   - Пример: obj1 + obj2 → obj1.operator+(obj2).  

2. **Как дружественная функция (friend)**  
   - Позволяет работать с приватными полями.  
   - Может принимать оба операнда как параметры.  
   - Пример: operator+(obj1, obj2).  
Как обычная функция (редко, если не требуется доступ к приватным полям)м)**  

### **Пример перегрузки + как метода класса:**  
class Vector {
public:
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}

    // Перегрузка + как метода класса
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
};

int main() {
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2;  // v1.operator+(v2)
    cout << v3.x << " " << v3.y;  // 4 6
}
2. Перегрузка бинарной операции, когда первый операнд не является объектом классакласса**  

Если первый опне объект классакласса** (например, int + obj), то **перегрузка возможна только через дружественную или обычную функцию**.  

### **Пример (int + Vector):**  
class Vector {
public:
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}

    // Дружественная функция для перегрузки (int + Vector)
    friend Vector operator+(int num, const Vector& v);
};

Vector operator+(int num, const Vector& v) {
    return Vector(num + v.x, num + v.y);
}

int main() {
    Vector v(1, 2);
    Vector result = 5 + v;  // operator+(5, v)
    cout << result.x << " " << result.y;  // 6 7
}
---

## **3. Перегрузка операции с помощью дружественной функции класса**  

Дружественные функции (friend)приватным полям **приватнымне являются методами классася методами класса**.  

### **Пример (<< для вывода в cout):**  
class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    // Дружественная функция для перегрузки <<
    friend ostream& operator<<(ostream& os, const Person& p);
};

ostream& operator<<(ostream& os, const Person& p) {
    os << "Name: " << p.name << ", Age: " << p.age;
    return os;
}

int main() {
    Person p("Alice", 25);
    cout << p;  // Name: Alice, Age: 25
}
---

## **4. Операции, для которых оператор-функция должна быть методом класне могут быть перегружены как дружественные функции как дружественные функции**, тол= (присваивание)а:  

- **= (присваивание)**  
- **[] (индексация)**  
- **() (вызов функции, функтор)**  
- **->(type) (приведение типа)**  
- **(type) (приведение типа)**  

### **Пример ([] для индексации):**  
class Array {
private:
    int data[10];
public:
    int& operator[](int index) {
        return data[index];
    }
};

int main() {
    Array arr;
    arr[3] = 42;  // arr.operator[](3) = 42
    cout << arr[3];  // 42
}
---

## **5. Перегрузка ++ и -- (префиксная и постфиксная формы)**  

- **Префиксная форма (++obj)** — возвращает изменённое значение.  
- **Постфиксная форма (obj++)** — возвращает старое значение.  

### **Пример:**  
class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}

    // Префиксный ++ (возвращает ссылку)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Постфиксный ++ (возвращает копию)
    Counter operator++(int) {  // int — фиктивный параметр
        Counter temp = *this;
        ++count;
        return temp;
    }

    void print() { cout << count << endl; }
};

int main() {
    Counter c(5);
    Counter c1 = ++c;  // c1 = 6, c = 6
    Counter c2 = c++;  // c2 = 6, c = 7
    c.print();  // 7
}
---

## **6. Использование const в методах класса**  

Методы, помеченные const, **не могут изменять поля класса** (кроме mutable).

### Пример:  
class Math {
private:
    mutable int callCount = 0;  // mutable можно изменять даже в const-методе
public:
    int square(int x) const {  // const-метод
        callCount++;  // OK, так как mutable
        return x * x;
    }
    // int modify() { x = 10; }  // Ошибка, если метод const
};
---

## **7. Перегрузка операторов присваивания (=) и перемещения (=&&)**  

1. Оператор присваивания (=)**  
- Должен быть методом класса.  
- Должен проверсамоприсваиваниеие** (a = a).  

class String {
private:
    char* str;
public:
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Оператор присваивания (копирование)
    String& operator=(const String& other) {
        if (this != &other) {  // Проверка на самоприсваивание
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    ~String() { delete[] str; }
};
### **2. Оператор перемещения (=&&)** (C++11)  
- Используеперемещения ресурсовсурсов** (без копирования).  
- Применrvalue-ссылками (&&)и (&&)**.  

class String {
    // ... (как выше)
public:
    // Оператор перемещения
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;  // Перемещаем указатель
            other.str = nullptr;  // Обнуляем исходный
        }
        return *this;
    }
};

int main() {
    String s1("Hello");
    String s2;
    s2 = std::move(s1);  // Вызов оператора перемещения
}
-Итог:*Итог:**  
- Перегрузка операторов позволяет удобно работать с классами.  
- Операторы =, [], (), -> **должны быть методами класса**.  
- const-методы не изменяют объект (кроме mutable).  
- Перемещающее присваивание (=&&) эффективно для динамических ресурсов.