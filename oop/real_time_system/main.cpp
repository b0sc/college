#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sensor {
public:
    string name;
    Sensor(const string& name) : name(name) {}

    // Simulate reading data from a sensor
    int readData() {
        return 42;
    }

};

class RealTimeSystem {
public:
    vector<Sensor> sensors;
    RealTimeSystem() {
        sensors.push_back(Sensor("Temperature"));
        sensors.push_back(Sensor("Pressure"));
    }

    void processData() {
        for (auto& sensor : sensors) {
            int data = sensor.readData();
            cout << sensor.name << ": " << data << endl;
        }
    }

};

int main() {
    RealTimeSystem realTimeSystem;
    realTimeSystem.processData();
    return 0;
}
