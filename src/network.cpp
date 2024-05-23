#include <iostream>
#include <string>
#include <sstream>

#include <ifaddrs.h>
#include <netdb.h>

auto main() -> int {
	struct ifaddrs *ifaddr;
	getifaddrs(&ifaddr);

	auto loopback = std::string {"lo"};
	auto ss = std::stringstream {};

	for (struct ifaddrs *ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr == nullptr || !loopback.compare(ifa->ifa_name))
			continue;
		if (ifa->ifa_addr->sa_family == AF_INET && ifa->ifa_name) {
			char host[16];
			getnameinfo(ifa->ifa_addr, 16, host, 16, nullptr, 0, 0);
			ss << host;
			break;
		}
	}

	if (ss.seekg(0, ss.end) && ss.tellg() > 0)
		std::cout << ss.str();
}

