#include <iostream>
#include "Ticket.h"
#include "Windows.h"
using namespace std;
void create_tickets(Ticket* tickets, int num_tickets);
void compare_tickets(const Ticket& t1, const Ticket& t2);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть кількість квитків: ";
    cin >> n;
    cin.ignore();
    Ticket* tickets;
    tickets = new Ticket[n];
    create_tickets(tickets, n);

    for (int i = 0; i < n; i++) {
        int duration = tickets[i].get_trip_duration();
        int total_cost = tickets[i].calc_total_cost();
        cout << "Номер квитка #" << i + 1 << ":" << endl;
        cout << "Станція прибуття: " << tickets[i].get_station_of_arrival() << endl;
        cout << "Час відправки і прибуття: " << tickets[i].get_time_of_arrival_and_departure() << endl;
        cout << "Номер: " << tickets[i].get_number() << endl;
        cout << "Ціна за хвилину: " << tickets[i].get_cost() << endl;
        cout << "Час: " << duration << " в хвилинах" << endl;
        cout << "Загальна ціна квитка: " << total_cost << endl;
        cout << endl;
    }
    cout << "Введіть номери квитків, які ви хочете порівняти за загальною ціною: " << endl;
    int i_t1, i_t2;
    cin >> i_t1;
    cin >> i_t2;
    compare_tickets(tickets[i_t1], tickets[i_t2]);
    cout << endl;
    return 0;
}


