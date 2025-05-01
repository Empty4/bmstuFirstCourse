#include <vector>
#include <iostream>
#include <string>
#include <fstream>

struct bankDeposit {
    std::string name;
    int amount;
    std::string type;
    std::string interestRate;
};

class Node {
public:
    bankDeposit data;
    Node* p_prev, * p_next;
public:
    Node(bankDeposit data){
        this->data = data;
        this->p_prev = this->p_next = NULL;
    }

};

class LinkedList {
public:
    Node* head, * tail;

public:
    LinkedList(){
        head = tail = NULL;
    }

    ~LinkedList(){
        while(head != NULL){
            pop_front();
        }
    }

    Node* push_front(bankDeposit data) {//добавляем в начало новый объект
        Node *ptr = new Node(data);
        ptr->p_next = head;
        if (head != NULL){
            head->p_prev = ptr;
        }
        if (tail == NULL){
            tail = ptr;
        }
        head = ptr;
        return ptr;
    }

    Node* push_back(bankDeposit data) {//добавляем в конец новый объект
        Node *ptr = new Node(data);
        ptr->p_prev = tail;//объект ведёт на предыдущий
        if (tail != NULL){
            tail->p_next = ptr;//предыдущий объект ссылается на следующий
        }
        if (head == NULL){//обнуляем предыдущий хед
            head = ptr;//объект птр теперь новый хед
        }
        tail = ptr;
        return ptr;
    }

    void pop_front() {
        if (head == NULL) {
            return;
        }
        Node* ptr = head->p_next;//птр след объект после хед
        if (ptr != NULL){
            ptr->p_prev = NULL;
        }
        else{
            tail = ptr = NULL;//вып если это единственный объект
        }
        delete head;
        head = ptr;
    }

    void pop_back() {
        if (tail == NULL){ 
            return;
        }
        Node* ptr = tail->p_prev;//tail после птр
        if (ptr != NULL){
            ptr->p_next = NULL;//объект после птр = NULL = tail
        }
        else{
            head = ptr = NULL;
        }
        delete tail;
        tail = ptr;//новый хвост это птр
    }

    Node* getAt(int index) {
        Node* ptr = head;
        int n = 0;
        while(n!=index){
            if(ptr == NULL) {
                return ptr;
            }
            ptr = ptr->p_next;
            n++;
        }
        return ptr;
    }

    Node* operator [](int index){
        return getAt(index);
    }

    /*Node insert(int index, bankDeposit data){
        Node* right = getAt(index);
        if (right == NULL) return push_back(data);//если новый объект в конец

        Node* left = right->p_prev;
        if (left == NULL) return push_front(data);//если новый объект в начало

        Node* ptr = new Node(data);//создаём новый объект и перезаписываем связи с учётом нового объекта

        ptr->p_prev = left;
        ptr->p_next = right;
        left->p_next = ptr;
        right->p_prev = ptr;

        return ptr;//возвращаем указатель на нов объект
    }*/

    void earse(int index){//удаление промежут объекта
        Node* ptr = getAt(index);
        if (ptr == NULL) return;

        if (ptr->p_prev == NULL) {
            pop_front();
        }

        if (ptr->p_next == NULL){
            pop_back();
        }
        Node* left = ptr->p_prev;
        Node* right = ptr->p_next;
        left->p_next = right;
        right->p_prev = left;

        delete ptr;
    }
};

bool compareamounts(const bankDeposit&am1, const bankDeposit&am2){
    return am1.amount<am2.amount;
}

void sortamount(std::vector<bankDeposit>& amounts) {
bool swapped;
int n = amounts.size();
for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
        if (compareamounts(amounts[j], amounts[j + 1])) {
            std::swap(amounts[j], amounts[j + 1]);
            swapped = true;
        }
    }
    if (!swapped) {
        break;
    }
    }   
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "usage: ./program <input_file>\n";
        return 1;
    }

    std::ifstream inputfile(argv[1]);
    if (!inputfile) {
        std::cout << "error opening file.\n";
        return 1;
    }

    std::vector<bankDeposit> amounts;

    // считываем данные из файла в список вкладов
    std::string line;
    while (std::getline(inputfile, line)) {
        bankDeposit am;
        std::string name, type, interestRate;
        float amount;
        size_t pos = 0, lastPos = 0;
        pos = line.find(' ', lastPos);
        name = line.substr(lastPos, pos - lastPos);
        lastPos = pos + 1;
        pos = line.find(' ', lastPos);
        type = line.substr(lastPos, pos - lastPos);
        lastPos = pos + 1;
        pos = line.find(' ', lastPos);
        interestRate = line.substr(lastPos, pos - lastPos);
        lastPos = pos + 1;
        amount = std::stof(line.substr(lastPos, line.length() - lastPos));
        am.name = name;
        am.type = type;
        am.interestRate = interestRate;
        am.amount = amount;
        amounts.push_back(am);
    }

    inputfile.close();

    // выводим список до сортировки
    std::cout << "список до сортировки:\n";
    for (const auto& am : amounts) {
        std::cout << am.name << " " << am.type << " " << am.interestRate << " " << am.amount << "\n";
    }

    // сортируем список вкладов
    sortamount(amounts);

    // выводим список после сортировки
    std::cout << "After sort:\n";
    for (const auto& am : amounts) {
    std::cout << am.name << " " << am.type << " " << am.interestRate << " " << am.amount << "\n";
    }
    std::cout << "finish!" << std::endl;
    return 0;
}