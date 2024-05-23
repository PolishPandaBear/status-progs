#include <fstream>
#include <iostream>

auto main() -> int {
	auto temperature = 0;
	std::ifstream {"/sys/class/thermal/thermal_zone2/temp"} >> temperature;
	std::cout << temperature/1000 << "°C";
}
