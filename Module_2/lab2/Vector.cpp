#include "class.h"

Vector::Vector() {
    n = 0;
    ptr = new int[0]; 
}
Vector::Vector(int n, int* arr) {
    this->n = n;
    ptr = new int[n];
    for (int i = 0; i < n; ++i) {
        ptr[i] = arr[i]; 
    }
}
Vector::Vector(Vector& dub) {
n = dub.n;
ptr = new int[n];
for (int i = 0; i < n; ++i) {
ptr[i] = dub[i]; }
}
Vector::Vector(Vector&& moved) {
ptr = moved.ptr;
n = moved.n; moved.ptr = nullptr; moved.n = 0;
} Vector::~Vector() {
delete [] ptr; }
int Vector::get_size() {
return n; }

int* Vector::get_ptr() {
return ptr; }
int Vector::operator[](int i) {
return ptr[i]; }
Vector Vector::operator=(const Vector& copy) {
if (this != &copy) {
this->n = copy.n; this->ptr = new int[n]; for (int i = 0; i < n; i++) {
this->ptr[i] = copy.ptr[i]; }
}
return *this; }
Vector Vector::operator=(Vector&& moved) {
if (ptr != moved.ptr) {
this->ptr = moved.ptr; this->n = moved.n; moved.ptr = nullptr; moved.n = 0;
}
return *this; }
bool findValue(const std::vector<int>& data, int value) {
auto result = std::find(begin(data), end(data), value) ; if (result == end(data))
{

return false; }
else
{
return true;
} }
Vector operator^(Vector &obj1, Vector& obj2) {
std::vector<int> Nvec; std::vector<int> pov;
std::vector<int> v1; std::vector<int> v2;
for (int i = 0; i < obj1.n; i++) {
v1.push_back(obj1[i]); }
for (int i = 0; i < obj2.n; i++) {
v2.push_back(obj2[i]); }
int iter = 0; do
{
if (!findValue(v2, v1[iter])) {
Nvec.push_back(v1[iter]); }
else
{
pov.push_back(v1[iter]);
}
iter++;
} while (iter < v1.size());
iter = 0;
do

{
if (!findValue(v1, v2[iter])) {
Nvec.push_back(v2[iter]); }
else
{
if (!findValue(pov, v2[iter])) {
pov.push_back(v2[iter]); }
}
iter++;
} while (iter < v2.size());
for (int i = 0; i < pov.size(); i++) {
v1.erase(std::remove(v1.begin(), v1.end(), pov[i]), v1.end());
v2.erase(std::remove(v2.begin(), v2.end(), pov[i]), v2.end()); }
int* nv1 = new int[v1.size()]; for (int i = 0; i < v1.size(); i++) {
nv1[i] = v1[i]; }
obj1 = Vector(v1.size(), nv1); delete[] nv1;
int* nv2 = new int[v2.size()]; for (int i = 0; i < v2.size(); i++) {
nv2[i] = v2[i]; }
;
obj2 = Vector(v2.size(), nv2); delete[] nv2;
int* NewVector = new int[Nvec.size()];

for (int i = 0; i < Nvec.size(); i++) {
NewVector[i] = Nvec[i]; }
return Vector(Nvec.size(), NewVector); }
std::ostream& operator<<(std::ostream& ostr, Vector& vec) {
std::string str;
for (int i = 0; i < vec.get_size(); ++i) {
str += std::to_string(vec[i]) + " "; }
return ostr << str; }
std::istream& operator>>(std::istream& istr, Vector& vec) {
if (vec.ptr != nullptr) { delete[] vec.ptr;
}
std::vector<int> vec2; int x;
while (istr) {
istr >> x;
vec2.push_back(x); }
vec2.pop_back();
vec.n = vec2.size();
vec.ptr = new int[vec2.size()]; for (int i = 0; i < vec.n; ++i) {
vec.ptr[i] = vec2[i]; }
return istr; }
Vector& Vector::operator++() // префиксный инкремент

{
int* arr = new int[(*this).n]; for (int i = 0; i < (*this).n; ++i) {
arr[i] = (*this)[i] + 1; }
*this = Vector((*this).n, arr); delete[] arr;
return *this;
}
Vector Vector::operator++(int k) // постфиксный инкремент {
Vector temp = *this; ++*this;
return temp;
}
/*
#include "Vector.h"

// Конструктор без параметров
Vector::Vector() : data(nullptr), size(0) {}

// Конструктор из массива
Vector::Vector(const int arr, int n) : size(n) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = arr[i];
    }
}

// Конструктор копирования
Vector::Vector(const Vector& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Конструктор перемещения
Vector::Vector(Vector&& other) noexcept : size(other.size), data(other.data) {
    other.data = nullptr;
    other.size = 0;
}

// Деструктор
Vector::~Vector() {
    delete[] data;
}

// Перегрузка операции постфиксного декремента
Vector Vector::operator--(int) {
    Vector temp(this);
    for (int i = 0; i < size; ++i) {
        data[i]--;
    }
    return temp;
}

// Операция присваивания с копированием
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return this;
}

// Операция присваивания с перемещением
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
    }
    return this;
}

// Метод для вывода вектора
void Vector::print() const {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
*/