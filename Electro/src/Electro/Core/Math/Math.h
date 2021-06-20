#pragma once
#include <math.h>
#include <cstdint>
namespace Math
{
	#define EPSILON 0.00001
	#define EPSILON2 (CMP_EPSILON * CMP_EPSILON)


	#define SQRT12 0.7071067811865475244008443621048490
	#define SQRT2 1.4142135623730950488016887242
	#define TAU 6.2831853071795864769252867666
	#define PI 3.1415926535897932384626433833
	#define Math_INF INFINITY
	#define Math_NAN NAN
	
	double Sin(double p_x) { return sin(p_x); }
	float Sin(float p_x) { return sinf(p_x); }

	double Cos(double p_x) { return cos(p_x); }
	float Cos(float p_x) { return cosf(p_x); }

	double Tan(double p_x) { return tan(p_x); }
	float Tan(float p_x) { return tanf(p_x); }

	double ASin(double p_x) { return asin(p_x); }
	float ASin(float p_x) { return asinf(p_x); }

	double ACos(double p_x) { return acos(p_x); }
	float ACos(float p_x) { return acosf(p_x); }

	double ATan(double p_x) { return atan(p_x); }
	float ATan(float p_x) { return atanf(p_x); }

	double ATan2(double p_y, double p_x) { return atan2(p_y, p_x); }
	float ATan2(float p_y, float p_x) { return atan2f(p_y, p_x); }

	double Sin(double p_x) { return sin(p_x); }
	float Sin(float p_x) { return sinf(p_x); }

	double SinH(double p_x) { return sinh(p_x); }
	float SinH(float p_x) { return sinhf(p_x); }
	
	double CosH(double p_x) { return cosh(p_x); }
	float CosH(float p_x) { return coshf(p_x); }
	
	double TanH(double p_x) { return tanh(p_x); }
	float TanH(float p_x) { return tanhf(p_x); }

	double Sqrt(double p_x) { return sqrt(p_x); }
	float Sqrt(float p_x) { return sqrtf(p_x); }

	double RSqrt(double p_x) { return 1 / sqrt(p_x); }
	float RSqrt(float p_x) { return 1 / sqrtf(p_x); }

	double FMod(double p_x, double p_y) { return fmod(p_x, p_y); }
	float FMod(float p_x, float p_y) { return fmodf(p_x, p_y); }

	 double Floor(double p_x) { return floor(p_x); }
	 float Floor(float p_x) { return floorf(p_x); }

	 double Ceil(double p_x) { return ceil(p_x); }
	 float Ceil(float p_x) { return ceilf(p_x); }

	 double Pow(double p_x, double p_y) { return pow(p_x, p_y); }
	 float Pow(float p_x, float p_y) { return powf(p_x, p_y); }

	 double Log(double p_x) { return log(p_x); }
	 float Logf(float p_x) { return logf(p_x); }

	 double Log2(double p_x) { return log2(p_x); }
	 float Log2(float p_x) { return log2f(p_x); }

	 double Ex(double p_x) { return exp(p_x); }
	 float Expf(float p_x) { return expf(p_x); }

	 double Abs(double g) { return abs(g); }
	 float Abs(float g) { return abs(g); }
	 int Abs(int g) { return g > 0 ? g : -g; }

	 int Sign(float p_val)
	 {
		 if (signbit(p_val)) return -1;
		 return 1;
	 }

	 double FPosMod(double p_x, double p_y) 
	 {
		double value = FMod(p_x, p_y);
		if ((value < 0 && p_y > 0) || (value > 0 && p_y < 0)) {
			value += p_y;
		}
		value += 0.0;
		return value;
	}
	 float  FPosMod(float p_x, float p_y)
	 {
		float value = FMod(p_x, p_y);
		if ((value < 0 && p_y > 0) || (value > 0 && p_y < 0)) {
			value += p_y;
		}
		value += 0.0;
		return value;
	}
	 float FPosModp(float p_x, float p_y)
	 {
		float value = FMod(p_x, p_y);
		if (value < 0) {
			value += p_y;
		}
		value += 0.0;
		return value;
	}
	 double FPosModp(double p_x, double p_y) 
	 {
		double value = FMod(p_x, p_y);
		if (value < 0) {
			value += p_y;
		}
		value += 0.0;
		return value;
	}

	 int64_t PosMod(int64_t p_x, int64_t p_y) 
	 {
		int64_t value = p_x % p_y;
		if ((value < 0 && p_y > 0) || (value > 0 && p_y < 0)) {
			value += p_y;
		}
		return value;
	}

	 double Deg2Rad(double p_y) { return p_y * (PI / 180.0); }
	 float Deg2rad(float p_y) { return p_y * (PI / 180.0); }

	 double Rad2deg(double p_y) { return p_y * (180.0 / PI); }
	 float Rad2deg(float p_y) { return p_y * (180.0 / PI); }

	 double Lerp(double p_from, double p_to, double p_t) { return p_from + (p_to - p_from) * p_t; }
	 float Lerp(float p_from, float p_to, float p_t) { return ( 1.f - p_t ) * p_from + p_t * p_to; }

	 double LerpAngle(double p_from, double p_to, double p_weight) {
		double difference = fmod(p_to - p_from, TAU);
		double distance = fmod(2.0 * difference, TAU) - difference;
		return p_from + distance * p_weight;
	}
	 
	float LerpAngle(float p_from, float p_to, float p_weight) {
		float difference = FMod(p_to - p_from, (float)TAU);
		float distance = FMod(2.0f * difference, (float)TAU) - difference;
		return p_from + distance * p_weight;
	}

	 double InverseLerp(double p_from, double p_to, double p_value) { return (p_value - p_from) / (p_to - p_from); }
	 float InverseLerp(float p_from, float p_to, float p_value) { return (p_value - p_from) / (p_to - p_from); }

	 double RangeLerp(double p_value, double p_istart, double p_istop, double p_ostart, double p_ostop) { return Lerp(p_ostart, p_ostop, InverseLerp(p_istart, p_istop, p_value)); }
	 float RangeLerp(float p_value, float p_istart, float p_istop, float p_ostart, float p_ostop) { return Lerp(p_ostart, p_ostop,  InverseLerp(p_istart, p_istop, p_value)); }

	 float MoveTowards(float p_current, float p_target, float p_maxdelta)
	 {
		 if (Abs(p_target - p_current) <= p_maxdelta)
			 return p_target;

		 return p_current + Sign(p_target - p_current) * p_maxdelta;
	 }


	 double Round(double p_val) { return (p_val >= 0) ? Floor(p_val + 0.5) : -Floor(-p_val + 0.5); }
	 float Round(float p_val) { return (p_val >= 0) ? Floor(p_val + 0.5) : -Floor(-p_val + 0.5); }



	 float Clamp(float p_val, float p_min, float p_max)
	 {
		 if (p_val < p_min)
			 p_val = p_min;
		 if (p_val > p_max)
			 p_val = p_max;
			 return p_val;
	 }

	 float ClampInt(int p_val, int p_min, int p_max)
	 {
		 if (p_val < p_min)
			 p_val = p_min;
		 if (p_val > p_max)
			 p_val = p_max;
		 return p_val;
	 }

	float ClampNeg1to1(float value) {
		 if (value < -1.f) value = -1.f;
		 if (value > 1.f) value = 1.f;
		 return value;
	 }

	 uint32_t HalfbitsToFloatbits(uint16_t h) {
		uint16_t h_exp, h_sig;
		uint32_t f_sgn, f_exp, f_sig;

		h_exp = (h & 0x7c00u);
		f_sgn = ((uint32_t)h & 0x8000u) << 16;
		switch (h_exp) {
		case 0x0000u: /* 0 or subnormal */
			h_sig = (h & 0x03ffu);
			/* Signed zero */
			if (h_sig == 0) {
				return f_sgn;
			}
			/* Subnormal */
			h_sig <<= 1;
			while ((h_sig & 0x0400u) == 0) {
				h_sig <<= 1;
				h_exp++;
			}
			f_exp = ((uint32_t)(127 - 15 - h_exp)) << 23;
			f_sig = ((uint32_t)(h_sig & 0x03ffu)) << 13;
			return f_sgn + f_exp + f_sig;
		case 0x7c00u: /* inf or NaN */
			/* All-ones exponent and a copy of the significand */
			return f_sgn + 0x7f800000u + (((uint32_t)(h & 0x03ffu)) << 13);
		default: /* normalized */
			/* Just need to adjust the exponent and shift */
			return f_sgn + (((uint32_t)(h & 0x7fffu) + 0x1c000u) << 13);
		}
	}

	 float HalfPtrToFloat(const uint16_t* h) {
		union {
			uint32_t u32;
			float f32;
		} u;

		u.u32 = HalfbitsToFloatbits(*h);
		return u.f32;
	}

	 float HalfToFloat(const uint16_t h) {
		return HalfPtrToFloat(&h);
	}

	 uint16_t MakeHalfFloat(float f) {
		union {
			float fv;
			uint32_t ui;
		} ci;
		ci.fv = f;

		uint32_t x = ci.ui;
		uint32_t sign = (unsigned short)(x >> 31);
		uint32_t mantissa;
		uint32_t exp;
		uint16_t hf;

		// get mantissa
		mantissa = x & ((1 << 23) - 1);
		// get exponent bits
		exp = x & (0xFF << 23);
		if (exp >= 0x47800000) {
			// check if the original single precision float number is a NaN
			if (mantissa && (exp == (0xFF << 23))) {
				// we have a single precision NaN
				mantissa = (1 << 23) - 1;
			}
			else {
				// 16-bit half-float representation stores number as Inf
				mantissa = 0;
			}
			hf = (((uint16_t)sign) << 15) | (uint16_t)((0x1F << 10)) |
				(uint16_t)(mantissa >> 13);
		}
		// check if exponent is <= -15
		else if (exp <= 0x38000000) {
			/*// store a denorm half-float value or zero
		exp = (0x38000000 - exp) >> 23;
		mantissa >>= (14 + exp);

		hf = (((uint16_t)sign) << 15) | (uint16_t)(mantissa);
		*/
			hf = 0; //denormals do not work for 3D, convert to zero
		}
		else {
			hf = (((uint16_t)sign) << 15) |
				(uint16_t)((exp - 0x38000000) >> 13) |
				(uint16_t)(mantissa >> 13);
		}

		return hf;
	}


};