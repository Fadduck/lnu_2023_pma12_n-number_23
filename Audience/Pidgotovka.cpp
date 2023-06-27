#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <sstream> 
#include <ostream> 
#include <fstream> 
using namespace std; 
 
template <typename T> 
class Audience { 
protected: 
    int number; 
    T area; 
    int twop; 
    int threep; 
 
public: 
    Audience() : number(0), area(0), twop(0), threep(0) {} 
    Audience(int num, int a, int two, int three) 
        : number(num), area(a), twop(two), threep(three) {} 
    int getTwop() { 
        return twop; 
    } 
    int getThreep() { 
        return threep; 
    } 
    int Allplaces() { 
        return twop * 2 + threep * 3; 
    } 
    int GetArea() { 
        return area; 
    } 
    virtual int TakeFloor() { 
        int floorNumber = number / 100; 
        return floorNumber; 
    } 
    friend ostream& operator<<(ostream& os, Audience<T>& audience) { 
        int floorNumber = audience.number / 100; 
 
        os << "Number of audience: " << audience.number << endl; 
        os << "Floor number: " << floorNumber << endl; 
        os << "Number of places: " << audience.Allplaces() << endl; 
        os << "Area of audience: " << audience.area << endl; 
        return os; 
    } 
 
    friend istream& operator>>(istream& is, Audience<T>& audience) { 
        cout << "Number of audience: "; 
        is >> audience.number; 
        cout << "Double desks: "; 
        is >> audience.twop; 
        cout << "Three seats desks: "; 
        is >> audience.threep; 
        cout << "Area: "; 
        is >> audience.area; 
 
        return is; 
    } 
}; 
 
template <typename T> 
class MultimediaAudience : public Audience<T> { 
private: 
    int numbermult; 
    vector<string> devices; 
 
public: 
    MultimediaAudience() : numbermult(0) {} 
    MultimediaAudience(int number,int area,int twop,int threep, const vector<T>& devices, int num) 
        : Audience<T>(number, area, twop,threep), numbermult(num){} 
    int getArea() { 
        return this->area; 
    } 
    int TakeFloor() override { 
        int floorNumber = this->number / 100; 
        return floorNumber; 
    } 
    int Allplacess()  { 
        return this->twop * 2 + this->threep * 3; 
    } 
    friend ostream& operator<<(ostream& os, MultimediaAudience<T>& audience) { 
        int floorNumber = audience.number / 100; 
 
        os << "Number of audience: " << audience.number << endl; 
        os << "Floor number: " << floorNumber << endl; 
        os << "Number of places: " << audience.Allplaces() << endl; 
        os << "Area of audience: " << audience.area << endl; 
 
        os << "Devices: "; 
        for (int i = 0; i < audience.devices.size(); i++) { 
            os << "device number " << i + 1 << ": " << audience.devices[i] << endl; 
        } 
        os << endl; 
 
        return os; 
    } 
 
    friend istream& operator>>(istream& is, MultimediaAudience<T>& audience) { 
        cout << "Number of audience: "; 
        is >> audience.number; 
        cout << "Double desks: "; 
        is >> audience.twop; 
        cout << "Three seats desks: "; 
        is >> audience.threep; 
        cout << "Enter number of devices: "; 
        is >> audience.numbermult; 
 
        cout << "Enter devices: "; 
        for (int i = 0; i < audience.numbermult; i++) { 
            string dev; 
            cout << "Device " << i + 1 << ": "; 
            is >> dev; 
            audience.devices.push_back(dev); 
        } 
 
        cout << "Area: "; 
        is >> audience.area; 
 
        return is; 
    } 
}; 
 
int main() { 
    int numProducts; 
    cout << "Enter number of products: "; 
    cin >> numProducts; 
 
    Audience<double>* products = new Audience<double>[numProducts]; 
 
    for (int i = 0; i < numProducts; i++) { 
        cin >> products[i]; 
    } 
 
    cout << "--------" << endl; 
    for
(int i = 0; i < numProducts; i++) {
	        cout << products[i] << endl; 
	    } 
	 
	    int numProductswithdev; 
	    cout << "Enter number of products with devices: "; 
	    cin >> numProductswithdev; 
	 
	    MultimediaAudience<double>* productswithdev = new MultimediaAudience<double>[numProductswithdev]; 
	 
	    for (int i = 0; i < numProductswithdev; i++) { 
	        cin >> productswithdev[i]; 
	    } 
	 
	    cout << "--------" << endl; 
	    for (int i = 0; i < numProductswithdev; i++) { 
	        cout << productswithdev[i] << endl; 
	    } 
	    int s=0; 
	    for (int i = 0; i < numProducts; i++) { 
	        if (products[i].TakeFloor() == 2) { 
	            s += products[i].Allplaces(); 
	        } 
	    } 
	    for (int i = 0; i < numProductswithdev; i++) { 
	        if (productswithdev[i].TakeFloor() == 2) { 
	            s += productswithdev[i].Allplacess(); 
	        } 
	    } 
	 
	    cout << "Total places on first floor: " << s<<endl; 
	    int biggestRegular = products[0].GetArea(); 
	    int biggestMultimedia = productswithdev[0].GetArea(); 
	    int kRegular = 0; 
	    int kMultimedia = 0; 
	 
	    for (int i = 0; i < numProducts; i++) { 
	        if (biggestRegular < products[i].GetArea()) { 
	            biggestRegular = products[i].GetArea(); 
	            kRegular = i; 
	        } 
	    } 
	 
	    for (int i = 0; i < numProductswithdev; i++) { 
	        if (biggestMultimedia < productswithdev[i].GetArea()) { 
	            biggestMultimedia = productswithdev[i].GetArea(); 
	            kMultimedia = i; 
	        } 
	    } 
	    cout << "The biggest audience: " << endl; 
	    if (products[kRegular].GetArea()< productswithdev[kMultimedia].GetArea()) 
	    { 
	        cout << productswithdev[kMultimedia] << endl; 
	    } 
	    else { 
	        cout << products[kRegular] << endl; 
	    } 
	    int maxCapacityRegular = products[0].Allplaces(); 
	    int maxCapacityMultimedia = productswithdev[0].Allplacess(); 
	    int kRegular1 = 0; 
	    int kMultimedia1 = 0; 
	 
	    for (int i = 0; i < numProducts; i++) { 
	        if (maxCapacityRegular < products[i].Allplaces()) { 
	            maxCapacityRegular = products[i].Allplaces(); 
	            kRegular1 = i; 
	        } 
	    } 
	 
	    for (int i = 0; i < numProductswithdev; i++) { 
	        if (maxCapacityMultimedia < productswithdev[i].Allplacess()) { 
	            maxCapacityMultimedia = productswithdev[i].Allplacess(); 
	            kMultimedia1 = i; 
	        } 
	    } 
	 
	    cout << "The auditorium with the maximum capacity: " << endl; 
	    if (maxCapacityRegular < maxCapacityMultimedia) { 
	        cout << productswithdev[kMultimedia1] << endl; 
	    } 
	    else { 
	        cout << products[kRegular1] << endl; 
	    } 
	 
	    delete[] products; 
	    delete[] productswithdev; 
	 
	    return 0; 
	}