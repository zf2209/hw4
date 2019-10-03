// xll_black.cpp

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

#include "fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace fms::black;
using namespace xll;

static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the forward price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the constant volatility of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the put option.")
	.Arg(XLL_DOUBLE, L"t", L"is the time (denoted by year) till option expiration.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the price of the European put option provided the parameters by Black model.")
	.Documentation(L"This function computes the price of an European put option by Black model.")
);
double WINAPI xll_black_put(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	double put_price = black_put(f, sigma, k, t);

	return put_price;
}

#ifdef _DEBUG

test test_black_put([] {
	ensure(double(round(xll_black_put(100, 0.2, 100, 0.25) * 1000) / 1000) == 3.988);

	});

#endif

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the forward price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the constant volatility of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the call option.")
	.Arg(XLL_DOUBLE, L"t", L"is the time (denoted by year) till option expiration.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the price of the European call option provided the parameters by Black model.")
	.Documentation(L"This function computes the price of an European call option by Black model.")
);
double WINAPI xll_black_call(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	double call_price = black_call(f, sigma, k, t);

	return call_price;
}

#ifdef _DEBUG

test test_black_call([] {
	ensure(double(round(xll_black_call(100, 0.2, 100, 0.25) * 1000) / 1000) == 3.988);

	});

#endif