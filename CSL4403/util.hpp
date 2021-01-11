// Already in CPP_Util, copied from there

#include <algorithm>
#include <vector>
#include <random>

template<typename T, typename RANDOM_GEN_OR_ENGINE = std::minstd_rand >
std::vector<T> get_random_sequence(int length) {
	static_assert(std::is_integral_v<T>,
		"Currently random sequences are only supported for integral types");

	std::vector<T> v(length);

	std::generate(v.begin(), v.end(), RANDOM_GEN_OR_ENGINE{});

	return v;	// expected that compiler does return value optimisation, since we shouldn't return xvalue to local variable
}
