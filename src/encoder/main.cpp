#include <iomanip>
#include <iostream>
#include <sstream>

#include "Encoder.h"

template <typename T>
std::string getHex(T number) {
	std::stringstream ss;
	ss << std::setw(2 * sizeof(T)) << std::setfill('0') << std::hex << static_cast<size_t>(number);
	return ss.str();
}

int main() {
	const char *image =
		" XXX X  X XXX  XXXX XXX\n"
		"X    X  X X  X X    X  X\n"
		"X    X  X X  X X    X  X\n"
		"X    XXXX XXX  XXX  XXX\n"
		"X     XX  X  X X    X  X\n"
		"X     XX  X  X X    X  X\n"
		" XXX  XX  XXX  XXXX X  X";
	const auto encoded = Chemion::encode(image);
	std::cout << "std::array<std::array<uint8_t, 20>, 4> msg_static {\n";
	for (const auto &array: encoded) {
		std::cout << "\t{";
		for (const auto byte: array)
			std::cout << "0x" << getHex(byte) << ", ";
		std::cout << "},\n";
	}
	std::cout << "};\n";
}
