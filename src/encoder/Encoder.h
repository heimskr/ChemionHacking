#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace Chemion {
	std::array<std::array<uint8_t, 20>, 4> encode(const std::array<char, 168> &);
	std::array<std::array<uint8_t, 20>, 4> encode(std::string_view);
}
