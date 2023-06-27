#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ticket {
private:
    string station_of_arrival;
    string time_of_arrival_and_departure;
    int number;
    double cost;
    int total_cost;

public:
    Ticket();
    Ticket(const string& station, const string& time, int num, double c);

    string get_station_of_arrival() const;
    string get_time_of_arrival_and_departure() const;
    int get_number() const;
    double get_cost() const;
    int get_trip_duration() const;
    int calc_total_cost() const;
    void compare_tickets(const Ticket& t1, const Ticket& t2);
    

    void set_station_of_arrival(const string& station);
    void set_time_of_arrival_and_departure(const string& time);
    void set_number(int num);
    void set_cost(double c);
};

