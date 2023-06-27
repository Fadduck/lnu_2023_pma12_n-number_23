#include "Ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket() : station_of_arrival(""), time_of_arrival_and_departure(""), number(0), cost(0.0) {}

Ticket::Ticket(const string& station, const string& time, int num, double c)
    : station_of_arrival(station), time_of_arrival_and_departure(time), number(num), cost(c) {}

string Ticket::get_station_of_arrival() const { return station_of_arrival; }

string Ticket::get_time_of_arrival_and_departure() const { return time_of_arrival_and_departure; }

int Ticket::get_number() const { return number; }

double Ticket::get_cost() const { return cost; }

int Ticket::get_trip_duration() const {
    string start_time_str = time_of_arrival_and_departure.substr(0, 5);
    string end_time_str = time_of_arrival_and_departure.substr(6, 5);

    int start_hour = stoi(start_time_str.substr(0, 2));
    int start_minute = stoi(start_time_str.substr(3, 2));
    int end_hour = stoi(end_time_str.substr(0, 2));
    int end_minute = stoi(end_time_str.substr(3, 2));

    int duration = (end_hour - start_hour) * 60 + (end_minute - start_minute);
    return duration;
}

int Ticket::calc_total_cost() const
{
    int duration = get_trip_duration();
    int total_cost = duration * cost;
    return total_cost;
}
//int Cityride_ticket::calc_total_cost_for_city_type() const
//{
//    string privilege = get_privilege();
//    if (privilege == "children_p")
//    {
//        int duration = get_trip_duration();
//        int cost = get_cost();
//        int total_cost = duration * cost * 0.7;
//    }
//    else if (privilege == "elder_p")
//    {
//        int duration = get_trip_duration();
//        int cost = get_cost();
//        int total_cost = duration * cost * 0.5;
//    }
//    else if (privilege == "invalid_p")
//    {
//        int duration = get_trip_duration();
//        int cost = get_cost();
//        int total_cost = 0;
//    }
//    else
//    {
//        int duration = get_trip_duration();
//        int cost = get_cost();
//        int total_cost = duration * cost;
//    }
//}

void compare_tickets(const Ticket& t1, const Ticket& t2) {
    if (t1.calc_total_cost() > t2.calc_total_cost()) {
        cout << "Квиток он має більше ціну: $" << t1.calc_total_cost() << endl;
        cout << "Станція прибуття: " << t1.get_station_of_arrival() << endl;
        cout << "Час прибуття і відправлення: " << t1.get_time_of_arrival_and_departure() << endl;
        cout << "Номер: " << t1.get_number() << endl;
        cout << "Ціна за хвилину поїздки: $" << t1.get_cost() << endl;
    }
    else if (t1.calc_total_cost() < t2.calc_total_cost()) {
        cout << "Другий квиток має бульшу ціну: $" << t2.calc_total_cost() << endl;
        cout << "Станція прибуття: " << t2.get_station_of_arrival() << endl;
        cout << "Час прибуття і відправлення: " << t2.get_time_of_arrival_and_departure() << endl;
        cout << "Номер: " << t2.get_number() << endl;
        cout << "Ціна за хвилину поїздки: $" << t2.get_cost() << endl;
    }
    else {
        cout << "Квитки мають одинакову ціну$" << endl;
    }
}

bool operator>(const Ticket& t1, const Ticket& t2) {
    return t1.calc_total_cost() > t2.calc_total_cost();
}



void create_tickets(Ticket* tickets, int num_tickets) {
    for (int i = 0; i < num_tickets; i++) {
        string station, time;
        int number;
        double cost;

        cout << "Введіть станцію прибуття для білету " << i + 1 << ": ";
        getline(cin, station);

        cout << "Введіть час прибуття і відправлення для білету " << i + 1 << ": ";
        getline(cin, time);

        cout << "Введіть номер для білету " << i + 1 << ": ";
        cin >> number;

        cout << "Введіть ціну за хвилину для білету " << i + 1 << ": $";
        cin >> cost;

        cin.ignore();

        Ticket t(station, time, number, cost);
        tickets[i] = t;

        cout << endl;
    }
}
void Ticket::set_station_of_arrival(const string& station) { station_of_arrival = station; }

void Ticket::set_time_of_arrival_and_departure(const string& time) { time_of_arrival_and_departure = time; }

void Ticket::set_number(int num) { number = num; }

void Ticket::set_cost(double c) { cost = c; }



