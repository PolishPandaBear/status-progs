#include <fstream>
#include <iostream>

auto main() -> int {
	auto capacity = 0;
	std::ifstream {"/sys/class/power_supply/BAT0/capacity"} >> capacity;

	std::cout << capacity << '%';
}
