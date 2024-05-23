#include <fstream>
#include <iostream>
#include <limits>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

auto main() -> int {
	auto stats = std::ifstream {"/proc/meminfo"};
	stats.ignore(max_size, ':');
	auto total_mem = 0;
	stats >> total_mem;

	stats.ignore(max_size, '\n');
	stats.ignore(max_size, '\n');
	stats.ignore(max_size, ':');
	auto available_mem = 0;
	stats >> available_mem;

	std::cout << 100 * (total_mem - available_mem) / total_mem << '%';
}
