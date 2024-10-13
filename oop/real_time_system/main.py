class Sensor:
    def __init__(self, name):
        self.name = name

    def read_data(self):
        # Simulate reading data from a sensor
        return 42

class RealTimeSystem:
    def __init__(self):
        self.sensors = [Sensor("Temperature"), Sensor("Pressure")]

    def process_data(self):
        for sensor in self.sensors:
            data = sensor.read_data()
            print(f"{sensor.name}: {data}")

# Usage
real_time_system = RealTimeSystem()
real_time_system.process_data()