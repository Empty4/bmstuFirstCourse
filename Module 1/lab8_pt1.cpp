#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;
list<int> lst;
set<int> st;

void push_back_to_list(list<int> &lst, const int elem) {
    auto start = chrono::steady_clock::now();
    lst.push_back(elem);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout << "push back to list: " << duration << endl;
}

void add_to_set(set<int> &st, const int elem) {
    auto start = chrono::steady_clock::now();
    st.insert(elem);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout << "add to set: " << duration << endl;
}

bool search_in_list(list<int> &lst, const int elem) 
{
    auto start = chrono::steady_clock::now();
    if (find(lst.begin(), lst.end(), elem) != lst.end()) {
        return true;
    }
    else {
        return false;
    }
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout << "search in list: " << duration << endl;
}

bool search_in_set(set<int> &st, const int elem) {
    auto start = chrono::steady_clock::now();
    if (find(st.begin(), st.end(), elem) != st.end()) {
        return true;
    }
    else {
        return false;
    }
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout << "search in set: " << duration << endl;
}

void pop_front_from_list(list<int> &lst) {
    auto k = 0;
    for (size_t i = 0; i < 1000; i++) {
        auto start = chrono::steady_clock::now();
        lst.pop_front();
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        k += duration;
    }
    k = k/1000;
    cout << "pop from list: " << k << endl;
}

void pop_front_from_set(set<int> &st) {
    auto k = 0;
    for (size_t i = 0; i < 500; i++) {
        auto start = chrono::steady_clock::now();
        st.erase(st.begin());
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        k += duration;
    }
    k = k/500;
    cout << "pop from set: " << k << endl;
}


int main () {
    srand(time(NULL));
    for (size_t i = 0; i < 1000; i++) {
        int random = rand()%10 + 1;
        st.insert(random);
        lst.push_back(random);
    }
    //adding
    cout << "Last element in list: " << *lst.end() << endl;
    push_back_to_list(lst, 17);
    cout << "Last element in list: " << *lst.end() << endl;
    cout << "Last element in set: " << *st.end() << endl;
    add_to_set(st, 10000);
    cout << "Last element in set: " << *st.end() << endl;
    //searching
    int element;
    element = -15;
    if (search_in_list(lst, element)) {
        cout << "element was found" << endl;
    }
    else {
        cout << "element wasn't found" << endl;
    }
    if (search_in_set(st, element)) {
        cout << "element was found" << endl;
    }
    else {
        cout << "element wasn't found" << endl;
    }
    //deleting
    cout << "First element in list: " << *lst.begin() << endl;
    pop_front_from_list(lst);
    cout << "First element in list: " << *lst.begin() << endl;
    cout << "First element in set: " << *st.begin() << endl;
    pop_front_from_set(st);
    cout << "First element in set: " << *st.begin() << endl;
    return 0;
}