#include "pch.h"
#include "CppUnitTest.h"
#include "../CSL4403/functions.hpp"
#include "../CSL4403/util.hpp"

#include <algorithm>
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AssignTest
{
	TEST_CLASS(UnitTest)
	{
		minstd_rand random_engine;
	public:
		TEST_METHOD(get_random_sequence_int) {
			std::vector<size_t> sizes{ 0,1, 4, 10, 45, 100 };
			for (size_t& size : sizes)
			{
				std::vector<int> tmp_vec{ get_random_sequence<int>(size) };
				Assert::AreEqual(size, tmp_vec.size());
					//, "Sequence didn't generate vector of required length");
			}
		}
		TEST_METHOD(binary_search_test)
		{
			auto size = 6;
			std::vector<int> v{ get_random_sequence<int>(size) };

			std::sort(v.begin(), v.end());
			for (auto i = 0; i < v.size(); i++)
			{
				auto index = binary_search(v, v[i]);
				Assert::AreEqual(index, i);
			}

			std::vector<int> non_existent_numbers(size);

			std::generate(non_existent_numbers.begin(), non_existent_numbers.end(), [&]() {
					int val = this->random_engine();
					while (std::find(v.begin(), v.end(), val) != v.end()) {	// `val` MUST NOT be in the vector
						val = this->random_engine();
					}
					return val;
				});

			std::sort(non_existent_numbers.begin(), non_existent_numbers.end());
			for (auto i = 0; i < non_existent_numbers.size(); i++)
			{
				auto index = binary_search(non_existent_numbers, non_existent_numbers[i]);
				Assert::AreEqual(index, i);
			}

		}
		TEST_METHOD(quick_sort_test)
		{
			std::vector<int> v{ get_random_sequence<int>(6) };

			quick_sort(v, 0, v.size() - 1);

			Assert::IsTrue(std::is_sorted(v.begin(), v.end()));
		}

		TEST_METHOD(merge_sort_test)
		{
			std::vector<int> v{ get_random_sequence<int>(6) };

			merge_sort(v, 0, v.size() - 1);

			Assert::IsTrue(std::is_sorted(v.begin(), v.end()));
		}
};
}
