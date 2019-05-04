#include "pch.h"
#include "CppUnitTest.h"
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/prefix.hpp>
#include <boost/preprocessor/list/for_each_product.hpp>
#define SI_UNITS (meter_t, (ampere_t, (candela_t, (kelvin_t, (kilogram_t, (mol_t, (second_t, BOOST_PP_NIL)))))))
#define SI_PREFIXES (pico, (nano, (micro, (milli, (centi, (deci, (deca, (hecto, (kilo, (mega, (giga, (tera, BOOST_PP_NIL))))))))))))
#define INVALID_CONSTRUCT_TEST_GENERATE(r, product) \
		TEST_METHOD(MY_TEST_NAME product) \
		{ \
			Assert::IsTrue(IS_INVALID_EXPR(quantity<DECLTYPE(1)> { std::declval<quantity<DECLTYPE(0)>>() })product || MY_IS_SAME_V product); \
		}
#define MY_TEST_NAME(TO, FROM) TO ## FROM
#define MY_IS_SAME_V(T, U) std::is_same_v<T, U>
#define VALID_CONSTRUCT_TEST_GENERATE(r, product) \
		TEST_METHOD(BOOST_PP_CAT(construct_, BOOST_PP_CAT product)) \
		{ \
			VALID_CONSTRUCT_TEST_BODY product \
		}
#define VALID_CONSTRUCT_TEST_BODY(type, prefix) \
	quantity<type, double> a(1.0); \
	Assert::AreEqual(1.0, a.value(), 1.0E-6); \
	quantity<scaled_unit_t<type, std::prefix>, double> b = a; \
	if constexpr (std::prefix::den == 1) \
		Assert::AreEqual( 1.0 / static_cast<double>(std::prefix::num), b.value(), 1.0E-6); \
	else \
		Assert::AreEqual( static_cast<double>(std::prefix::den), b.value(), 1.0E-6);

#include <test_util.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mitama;
using namespace mitama::si;

namespace BasicTest
{
	TEST_CLASS(ConstructorTest)
	{
	public:
		BOOST_PP_LIST_FOR_EACH_PRODUCT(VALID_CONSTRUCT_TEST_GENERATE, 2, (SI_UNITS, SI_PREFIXES))
		BOOST_PP_LIST_FOR_EACH_PRODUCT(INVALID_CONSTRUCT_TEST_GENERATE, 2, (SI_UNITS, SI_UNITS))
	};
}
