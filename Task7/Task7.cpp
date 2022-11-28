#include <iostream>
#include <string>
using namespace std;
struct student
{
    string second_name;
    string name;
    string sex; // стать задається 1 буквою "M"(чоловік) чи "F"(жінка)
    int height;
};

void input_student(student& x)
{
    cout << "Enter secondname: " << endl;
    if (cin.peek() == '\n')
        cin.ignore();
    getline(cin, x.second_name);

    cout << "Enter name: " << endl;
    if (cin.peek() == '\n')
        cin.ignore();
    getline(cin, x.name); 

    cout << "Enter sex: " << endl;
    cin >> x.sex;

    cout << "Enter height: " << endl;
    cin >> x.height;
}
void input_group(student* list, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        input_student(list[i]);
    }
}
void output_group(student* list, int n)
{
    cout << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << list[i].second_name << " " << list[i].name << " " << list[i].sex << " " << list[i].height << " " << endl;
    }
}
student highest_man(student* list, int n)
{
    string M = "M";
    student highest_man = list[0];
    for (size_t i = 0; i < n; i++)
    {
        if (list[i].sex == M)
        {
            if (list[i].height > highest_man.height)
            {
                highest_man = list[i];
            }
        }
    }
    return highest_man;
};
student lowest_woman(student* list, int n)
{
    string F = "F";
    student lowest_woman = list[0];
    for (size_t i = 0; i < n; i++)
    {
        if (list[i].sex == F)
        {
            if (list[i].height < lowest_woman.height)
            {
                lowest_woman = list[i];
            }
        }
    }
    return lowest_woman;
};
void sort_in_alphabetical_order(student* list, int& k);
int main()
{
    student* group;
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    group = new student[n];
    input_group(group, n);
    output_group(group, n);
    cout << endl;
    student H_M = highest_man(group, n);
    cout << "The Highest male student: " << H_M.second_name << " " << H_M.name << endl;
    cout << endl;
    student L_F = lowest_woman(group, n);
    cout << "The Lowest female student: " << L_F.second_name << " " << L_F.name << endl;
    cout << endl;
    sort_in_alphabetical_order(group, n);
}
void sort_in_alphabetical_order(student* list, int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (list[i].second_name > list[j].second_name)
            {
                swap(list[i].second_name, list[j].second_name);
                swap(list[i].name, list[j].name);
                swap(list[i].sex, list[j].sex);
                swap(list[i].height, list[j].height);
            }
        }
    }
    cout << "Sorted in alphabetik order:" << endl;
    for (int i = 0; i <n; i++)
    {
        cout << list[i].second_name << " " << list[i].name << " " << list[i].sex << " " << list[i].height << " " << endl;
    }
};