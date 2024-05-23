#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <thread>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
auto values = std::array<int, 7> {};
auto sum = 0, idle = 0;

auto read_stats() {
	auto stats = std::ifstream {"/proc/stat"};

	stats.ignore(max_size, ' '); // ignore first column
	for (auto &val : values)
		stats >> val;

	sum = std::accumulate(values.begin(), values.end(), 0);
	idle = values[3];
	return std::pair {sum, idle};
}

auto main() -> int {
	using namespace std::chrono_literals;
	std::ios_base::sync_with_stdio(false);

	auto start = read_stats();
	std::this_thread::sleep_for(1000ms);
	auto end = read_stats();

	auto cpu_delta = start.first - end.first;
	auto cpu_idle = start.second - end.second;
	std::cout << 100 * (cpu_delta - cpu_idle) / cpu_delta << '%';
}

