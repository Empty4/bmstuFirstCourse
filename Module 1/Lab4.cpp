#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct Discipline
{
 string Name_Discipline;
 unsigned short Mark;
};

struct Student
{
 string Fam;
 string Name;
 string Otch;
 int Group;
 int Count_Disciplines;
 vector <Discipline> Disciplines;
};


int main()
{
 // расчетные параметры
 vector<int> Number_group;
 map<int, int> Group_Neud;
 int Gr = 1;

 setlocale(LC_ALL, "Russian");
 
 int n;
 cout << "Введите количество студентов: ";
 cin >> n;
 vector <Student> Stud(n);
 cout << "Введите все номера групп, из которых будут студенты (по окончание, введите '0'): ";
 cin >> Gr;
 while (Gr != 0)
 {
  Number_group.push_back(Gr);
  Group_Neud[Gr] = 0;
  cin >> Gr;
 }
 // Заполнение студента

 for (int i = 0; i < n; ++i)
 {
  cout << "Введите ФИО студента: ";
  cin >> Stud[i].Fam >> Stud[i].Name >> Stud[i].Otch;
  cout << "Введите номер группы: ";
  cin >> Stud[i].Group;
  cout << "Введите количество дисциплин студента: ";
  cin >> Stud[i].Count_Disciplines;
  if (Stud[i].Count_Disciplines > 0)
  {
   for (int j = 0; j < Stud[i].Count_Disciplines; ++j)
   {
    Stud[i].Disciplines.push_back(Discipline());
    cout << "Введите название дисциплины и оценку: ";
    cin >> Stud[i].Disciplines[j].Name_Discipline >> Stud[i].Disciplines[j].Mark;
   }
  }
 }

 // Вывод студента

 for (int i = 0; i < n; ++i)
 {
  cout << "\nСтудент " << Stud[i].Fam << " " << Stud[i].Name << " " << Stud[i].Otch;
  cout << "\nГруппа " << Stud[i].Group;
  cout << "\nСданные дисцмплины:";
  if (Stud[i].Count_Disciplines == 0)
  {
    cout << "\nСтудент не сдался.";
  }
  for (int j = 0; j < Stud[i].Count_Disciplines; ++j)
  {
   cout << "\n" << Stud[i].Disciplines[j].Name_Discipline << " " << Stud[i].Disciplines[j].Mark;

   if (Stud[i].Disciplines[j].Mark == 2) // расчет задания
   {
    ++Group_Neud[Stud[i].Group];
   }
  }
 }
 cout << "\n";
 // Вывод ответа
 for (int i = 0; i < Number_group.size(); ++i) 
 {
  cout << "Группа " << Number_group[i] << ". количество неудов.: " << Group_Neud[Number_group[i]] << "\n";
 }
 return 0;
}