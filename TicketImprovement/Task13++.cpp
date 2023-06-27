#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std;

template<typename T>
void append(T**& arr, int& n, T* element)
{
	try {
		int size = n + 1;
		T** tArr = new T * [size];
		for (int i = 0; i < n; i++)
		{
			tArr[i] = arr[i];
		}
		tArr[n] = element;
		n++;
		arr = new T * [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = tArr[i];
		}
		delete[] tArr;
	}
	catch (exception e) {
		cout << "Appending error " << e.what() << endl;
	}
}



class Ticket {
protected:
	string arrivalStation;
	string departureTime;
	string arrivalTime;
	int seatNumber;
	double costPerMinute;

public:

	Ticket() :arrivalStation(""), departureTime(""), arrivalTime(""),
		seatNumber(0), costPerMinute(0) {}

	Ticket(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute) :
		arrivalStation(ArrivalStation), departureTime(DepartureTime), arrivalTime(ArrivalTime),
		seatNumber(SeatNumber), costPerMinute(CostPerMinute) {}

	Ticket(const Ticket& tickt) :
		arrivalStation(tickt.arrivalStation), departureTime(tickt.departureTime), arrivalTime(tickt.arrivalTime),
		seatNumber(tickt.seatNumber), costPerMinute(tickt.costPerMinute) {}

	virtual void Create(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute)
	{
		arrivalStation = ArrivalStation;
		departureTime = DepartureTime;
		arrivalTime = ArrivalTime;
		seatNumber = SeatNumber;
		costPerMinute = CostPerMinute;
	}
	int TravelTime() {
		int departureHour = stoi(departureTime.substr(0, 2));
		int departureMinute = stoi(departureTime.substr(3, 2));
		int arrivalHour = stoi(arrivalTime.substr(0, 2));
		int arrivalMinute = stoi(arrivalTime.substr(3, 2));
		int departureTimeInMinutes = departureHour * 60 + departureMinute;
		int arrivalTimeInMinutes = arrivalHour * 60 + arrivalMinute;

		int travelTime = arrivalTimeInMinutes - departureTimeInMinutes;

		return travelTime;
	}

	double _Cost() {
		int travelTime = TravelTime();

		double cost = travelTime * costPerMinute;

		return cost;
	}
	virtual double Cost() {
		return _Cost();
	}
	virtual bool Discount() { return false; }
	void SetArrivalStation(string ArrivalStation) { arrivalStation = ArrivalStation; }
	void SetDepartureTime(string DepartureTime) { departureTime = DepartureTime; }
	void SetArrivalTime(string ArrivalTime) { arrivalTime = ArrivalTime; }
	void SetSeatNumber(int SeatNumber) { seatNumber = SeatNumber; }
	void SetCostPerMinute(double CostPerMinute) { costPerMinute = CostPerMinute; }



	string GetArrivalStation() { return arrivalStation; }
	string GetDepartureTime() { return departureTime; }
	string GetArrivalTime() { return arrivalTime; }
	int GetSeatNumber() { return seatNumber; }
	double GetCostPerMinute() { return costPerMinute; }
	int GetDepartureTimeInMinutes() {
		int departureHour = stoi(departureTime.substr(0, 2));
		int departureMinute = stoi(departureTime.substr(3, 2));

		int departureTimeInMinutes = departureHour * 60 + departureMinute;
		return departureTimeInMinutes;
	}
	int GetArrivalTimeInMinutes() {
		int arrivalHour = stoi(arrivalTime.substr(0, 2));
		int arrivalMinute = stoi(arrivalTime.substr(3, 2));
		int arrivalTimeInMinutes = arrivalHour * 60 + arrivalMinute;
		return arrivalTimeInMinutes;
	}


	virtual void PrintData() {
		cout << *this;
	}
	friend ostream& operator<<(ostream& os, Ticket& dt) {
		os << "Станція прибуття:  " << dt.arrivalStation << "  | ";
		os << "Час відправлення: " << dt.departureTime << " | ";
		os << "Час прибуття: " << dt.arrivalTime << " | ";
		os << "Місце: " << dt.seatNumber << " | ";
		os << "Ціна за хвилину: " << dt.costPerMinute << endl;
		os << "Тривалість поїздки: " << dt.TravelTime() << " хвилин | ";
		os << "Вартість квитка: " << dt.Cost() << " гривень." << std::endl;
		return os;
	}
	friend istream& operator>>(istream& is, Ticket& dt) {
		cout << "Введіть станцію прибуття: ";
		is >> dt.arrivalStation;
		cout << endl << "Введіть номер місця: ";
		is >> dt.seatNumber;
		cout << endl << "Введіть час відправлення у форматі Гг:Хх: ";
		is >> dt.departureTime;
		cout << endl << "Введіть час прибуття у форматі Гг:Хх: ";
		is >> dt.arrivalTime;
		cout << endl << "Введіть ціну за хвилину: ";
		is >> dt.costPerMinute;
		return is;
	}
	bool operator<(Ticket& t) {
		if (Cost() < t.Cost())
			return true;
		return false;
	}
	bool operator>(Ticket& t) {
		if (Cost() > t.Cost())
			return true;
		return false;
	}
	Ticket operator=(Ticket& t) {

		arrivalStation = t.arrivalStation;
		departureTime = t.departureTime;
		arrivalTime = t.arrivalTime;
		seatNumber = t.seatNumber;
		costPerMinute = t.costPerMinute;
		return *this;
	}
	string to_str() {
		string retval;
		retval += "Станція прибуття: " + arrivalStation + " ";
		retval += "Час відправлення: " + departureTime + " ";
		retval += "Час прибуття: " + arrivalTime + " ";
		retval += "Місце: " + to_string(seatNumber) + " ";
		retval += "Ціна за хвилину: " + to_string(costPerMinute) + "\n";
		retval += "Тривалість поїздки: " + to_string(TravelTime()) + " хвилин" + "\n";
		retval += "Вартість квитка: " + to_string(Cost()) + " гривень." + "\n";
		return retval;
	}
};


class InternationalTicket :public Ticket
{
	string surname;
	bool previouslyBooked = false;
	double discountForBooking = 5;
public:
	double Cost() {
		if (!previouslyBooked)
			return _Cost();
		double startPrice = _Cost();
		double discount = startPrice / 100 * discountForBooking;
		return startPrice - discount;
	}

	virtual void Create(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute, bool PreviouslyBooked)
	{
		arrivalStation = ArrivalStation;
		departureTime = DepartureTime;
		arrivalTime = ArrivalTime;
		seatNumber = SeatNumber;
		costPerMinute = CostPerMinute;
		previouslyBooked = PreviouslyBooked;
	}
	virtual void Create(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute, int PreviouslyBooked, int discount)
	{
		arrivalStation = ArrivalStation;
		departureTime = DepartureTime;
		arrivalTime = ArrivalTime;
		seatNumber = SeatNumber;
		costPerMinute = CostPerMinute;
		switch (PreviouslyBooked)
		{
		case 1:
			previouslyBooked = true;
			break;
		case 0:
			previouslyBooked = false;
			break;
		default:
			break;
		}
		discountForBooking = discount;
	}
	void PrintData() {
		cout << static_cast<Ticket&>(*this);
		cout << "Знижка за завчасне бронювання 5% (1 - так, 0 - ні): " << previouslyBooked << endl << endl;
	}
	void readData() {
		cin >> static_cast<Ticket&>(*this);
		cout << "Введіть тип квитка (попередньо заброньований - 1, якщо ні - 0): ";
		int tType;
		try
		{
			cin >> tType;
			switch (tType)
			{
			case 1:
				previouslyBooked = true;
				break;
			case 0:
				previouslyBooked = false;
				break;
			default:
				cout << "Встановлено тип попередньо не заброньований" << endl;
				previouslyBooked = false;
				break;
			}
		}
		catch (const exception&)
		{
			cout << "Не розумію " << endl;
		}
		cout << endl;
	}
};
class LocalTicket :public Ticket
{
public:
	bool Discount() {
		if (activeType != звичайний)
			return true;
		return false;
	}
	enum type
	{
		звичайний = 0,
		дитячий = 50,
		пенсійний = 30,
		інваліди1групи = 100
	};
protected:type activeType = звичайний;
public:
	double Cost() {


		double startPrice = _Cost();
		double discount = startPrice / 100 * activeType;
		return startPrice - discount;
	}

	virtual void Create(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute, type ActiveType)
	{
		arrivalStation = ArrivalStation;
		departureTime = DepartureTime;
		arrivalTime = ArrivalTime;
		seatNumber = SeatNumber;
		costPerMinute = CostPerMinute;
		activeType = ActiveType;
	}
	virtual void Create(string ArrivalStation, string DepartureTime, string ArrivalTime, int SeatNumber, double CostPerMinute, int type1)
	{
		arrivalStation = ArrivalStation;
		departureTime = DepartureTime;
		arrivalTime = ArrivalTime;
		seatNumber = SeatNumber;
		costPerMinute = CostPerMinute;

		switch (type1)
		{
		case 1:
			activeType = звичайний;
			break;
		case 2:
			activeType = дитячий;
			break;
		case 3:
			activeType = пенсійний;
			break;
		case 4:
			activeType = інваліди1групи;
			break;
		default:
			activeType = звичайний;
			break;
		}
	}
	void PrintData() {
		cout << static_cast<Ticket&>(*this);
		cout << "Знижка(звичайний = 0, дитячий = 50, пенсійний = 30, інваліди1групи = 100): " << activeType << "%" << endl << endl;
	}
	void readData() {
		cin >> static_cast<Ticket&>(*this);

		cout << "Введіть тип квитка (звичайний - 1, дитячий - 2, пенсійний - 3, інваліди 1 групи - 4): ";
		int tType;
		try
		{
			cin >> tType;
			switch (tType)
			{
			case 1:
				activeType = звичайний;
				break;
			case 2:
				activeType = дитячий;
				break;
			case 3:
				activeType = пенсійний;
				break;
			case 4:
				activeType = інваліди1групи;
				break;
			default:
				cout << "Встановлено тип 'звичайний'" << endl;
				activeType = звичайний;
				break;
			}
		}
		catch (const exception&)
		{
			cout << "Не розумію що це (-_-')" << endl;
		}
		cout << endl;
	}
};


class Route {
	string name;
	int number;

	int numberOfTickets;

	int type;
	double costPerMin;
	string DepTime; string ArrTime;

	int numberOfSoldTickets;
	Ticket** SoldTickets;
public:
	Route(string Name, int RouteNumber, int RouteType, int NumberOfTickets, double CostPerMin, string DepartureTime, string ArrivalTime) {
		name = Name;
		number = RouteNumber;
		numberOfTickets = NumberOfTickets;
		type = RouteType;
		numberOfSoldTickets = 0;
		SoldTickets = new Ticket * [numberOfSoldTickets];
		costPerMin = CostPerMin;
		DepTime = DepartureTime;
		ArrTime = ArrivalTime;
	}
	int GetNumberOfSoldTickets() {
		return numberOfSoldTickets;
	}
	int GetNumberOfTickets() {
		return numberOfTickets;
	}
	Ticket** GetSoldTickets() {
		return SoldTickets;
	}
	int getNumberOfRoute()
	{
		return number;
	}
	Ticket* Buy(int typeOfT)//typeOfT: if international 1=booked, 0=not booked, if local 1=звичайний, 2=дитячий, 3=пенсійний, 4=інваліди 1 групи
	{
		string arriv = name.substr(name.find('-') + 1);
		if (type == 1)
		{
			LocalTicket* rTckt = new LocalTicket();
			rTckt->Create(arriv, DepTime, ArrTime, numberOfSoldTickets, costPerMin, typeOfT);
			append<Ticket>(SoldTickets, numberOfSoldTickets, rTckt);

			return rTckt;
		}
		else
		{
			InternationalTicket* rTckt = new InternationalTicket();
			rTckt->Create(arriv, DepTime, ArrTime, numberOfSoldTickets, costPerMin, typeOfT == 1 ? true : false);
			append<Ticket>(SoldTickets, numberOfSoldTickets, rTckt);
			return rTckt;
		}

	}
	void Print()
	{
		cout << "Назва: " << name << " Продано квитків: " << numberOfTickets << endl;
	}
};
class cashRegister
{
	string address;

	int n = 0;
	Ticket** arr = new Ticket * [n];//sold tickets-rewr

	int N = 0;
	Route** Routes = NULL;

public:
	void Append(Route* route) {

		append<Route>(Routes, N, route);
	}

	Ticket* Sell(int routeNumber, int typeOfT)//typeOfT: if international 1=booked, 0=not booked, if local 1=звичайний, 2=дитячий, 3=пенсійний, 4=інваліди 1 групи
	{

		for (int i = 0; i < N; i++)
		{
			Route* currR = Routes[i];
			if (currR->getNumberOfRoute() == routeNumber)
			{
				cout << "Продано квиток: " << endl;
				Ticket* retT = currR->Buy(typeOfT);
				retT->PrintData();
				return retT;
			}
		}
		cout << "no such route №";
	}

	Ticket** GetAllSoldTickets()
	{
		Ticket** retTickets = NULL;
		int n = 0;
		for (int i = 0; i < N; i++)
		{
			Ticket** ticketsFromRoute = Routes[i]->GetSoldTickets();
			for (int j = 0; j < Routes[i]->GetNumberOfSoldTickets(); j++)
			{

				append<Ticket>(retTickets, n, ticketsFromRoute[j]);
			}

		}
		return retTickets;
	}
	int GetNumberOfSoldTickets() {
		int n = 0;
		for (int i = 0; i < N; i++)
			n += Routes[i]->GetNumberOfSoldTickets();
		return n;
	}

	Route** PrintRoutesWihtAllTicketsBought() {
		Route** retR = NULL;
		int tn = 0;
		for (int i = 0; i < N; i++)
		{
			auto bt = Routes[i]->GetNumberOfSoldTickets();
			auto ot = Routes[i]->GetNumberOfTickets();

			if (bt == ot)
			{
				cout << bt << '/' << ot << "  ";
				Routes[i]->Print();
				append<Route>(retR, tn, Routes[i]);
			}
		}
		return retR;
	}

	int PrintLocalTicketsWithDiscount()
	{
		int tn = 0;
		Ticket** Tickets = GetAllSoldTickets();
		for (int i = 0; i < GetNumberOfSoldTickets(); i++)
		{
			if (dynamic_cast<LocalTicket*>(Tickets[i]))
				if (Tickets[i]->Discount())
					tn++;
		}
		cout << tn << endl;
		return tn;
	}

	void ReadRoutesFromFile(string nameOfFile)//WRITE 
	{
		ifstream file;
		try {
			file.open(nameOfFile);
		}
		catch (...)
		{
			cout << "Invalid file name" << endl;
			exit(0);
		}

		string name;
		int routeNumber;
		int routeType; //1-local, evr else - international
		int numberOfTickets;
		double costPerMinute;
		string DepTime;
		string ArrTime;

		string arrivalStation = name.substr(name.find('-') + 1);;

		if (file.is_open())
			while (!file.eof()) {
				try {
					file >> name;
					file >> routeNumber;
					file >> routeType;
					file >> numberOfTickets;
					file >> costPerMinute;
					file >> DepTime;
					file >> ArrTime;
					Route* r = new Route(name, routeNumber, routeType, numberOfTickets, costPerMinute, DepTime, ArrTime);
					Append(r);
				}
				catch (exception e) {
					cout << e.what() << endl;
				}
			}
		else {
			cout << "Invalid file name" << endl;
			exit(0);
		}
	}
};



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cashRegister C;


	//Додати маршрут

	Route r1("Львів-Тернопіль", 4, 1, 4, 1, "10:00", "13:00");
	C.Append(&r1);
	Route r2("Львів-Київ", 5, 1, 4, 0, "10:00", "13:00");
	C.Append(&r2);
	Route r3("Львів-Прага", 6, 1, 3, 0, "00:00", "20:45");
	C.Append(&r3);
	Route r4("Львів-ІваноФранківськ", 7, 0, 0, 1, "15:00", "23:00");
	C.Append(&r4);
	Route r5("Львів-Житомир", 8, 1, 1, 1, "09:00", "19:30");
	C.Append(&r5);



	//Продати квиток
	C.Sell(5, 3);
	C.Sell(6, 0);
	C.Sell(7, 1);
	C.Sell(8, 2);
	C.Sell(4, 3);



	cout << endl << "Кількість проданих квитків: " << C.GetNumberOfSoldTickets() << endl << endl;

	cout << "Рейси на які продано усі квитки: " << endl;
	C.PrintRoutesWihtAllTicketsBought();
	
	cout << endl << "Кількість проданих пільгових квитків: ";
	C.PrintLocalTicketsWithDiscount();
}