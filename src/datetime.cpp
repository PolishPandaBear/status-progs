#include <iostream>
#include <locale>
#include <chrono>
#include <format>

auto main() -> int {
	using namespace std::chrono;

	auto const timedate = current_zone()->to_local(system_clock::now());
	std::cout << std::format("{:%F %X}", timedate);
}
