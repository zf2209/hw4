// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
#include <math.h>
#include <stdexcept>
#include <utility>

namespace fms::black {

	//!!! Black put and call code goes here.
	//!!! Use the functions in fms_normal.h
	// Black put price function.
	inline double black_put(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + 0.5 * pow(sigma, 2) * t) / sigma / sqrt(t);
		double d2 = d1 - sigma * sqrt(t);
		double put_price = (k * fms::normal::cdf(-d2) - f * fms::normal::cdf(-d1));

		return put_price;
	}
	// Black call price function.
	inline double black_call(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + 0.5 * pow(sigma, 2) * t) / sigma / sqrt(t);
		double d2 = d1 - sigma * sqrt(t);
		double call_price = (f * fms::normal::cdf(d1) - k * fms::normal::cdf(d2));

		return call_price;
	}
} // fms::black