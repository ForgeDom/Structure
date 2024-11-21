#include <iostream>
#include <string>
using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string gearboxType;

    void setValues(double l, double c, double ev, double ep, double wd, const string& col, const string& gt) {
        length = l;
        clearance = c;
        engineVolume = ev;
        enginePower = ep;
        wheelDiameter = wd;
        color = col;
        gearboxType = gt;
    }

    void display() const {
        cout << "Car Details: \n";
        cout << "Length: " << length << " meters\n";
        cout << "Clearance: " << clearance << " cm\n";
        cout << "Engine Volume: " << engineVolume << " liters\n";
        cout << "Engine Power: " << enginePower << " HP\n";
        cout << "Wheel Diameter: " << wheelDiameter << " inches\n";
        cout << "Color: " << color << endl;
        cout << "Gearbox Type: " << gearboxType << endl;
    }

    bool isGearboxType(const string& type) const {
        return gearboxType == type;
    }

    bool isColor(const string& col) const {
        return color == col;
    }

    bool isMorePowerfulThan(double power) const {
        return enginePower > power;
    }
};

int main() {
    Car car1, car2;

    car1.setValues(4.5, 16, 2.0, 150, 18, "Red", "Automatic");
    car2.setValues(4.2, 17, 1.8, 120, 17, "Blue", "Manual");

    car1.display();
    cout << endl;
    car2.display();
    cout << endl;

    if (car1.isGearboxType("Automatic")) {
        cout << "Car 1 has an automatic gearbox.\n";
    }

    if (car2.isColor("Blue")) {
        cout << "Car 2 is blue.\n";
    }

    if (car1.isMorePowerfulThan(140)) {
        cout << "Car 1 is more powerful than 140 HP.\n";
    }

    return 0;
}
