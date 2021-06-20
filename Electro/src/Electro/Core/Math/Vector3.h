#pragma once

#include "Math/Math.h"
class Vector2;

struct Vector3
{
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float p_x, float p_y, float p_z) 
			:x (p_x), y(p_y), z(p_z) {}
	Vector3(const Vector2& p_vec);
	Vector3(const Vector3& p_vec) 
		: x(p_vec.x), y(p_vec.y), z(p_vec.z) {}

	inline const float& operator[](int p_axis) const { return coord[p_axis];}
	inline float& operator[](int p_axis) { return coord[p_axis]; }

	static inline Vector3 Abs(const Vector3& p_vec);
	static inline Vector3 Floor(const Vector3& p_vec);
	static inline Vector3 Sign(const Vector3& p_vec);
	static inline Vector3 Round(const Vector3& p_vec);
	static inline Vector3 Ceil(const Vector3& p_vec);

	static inline float Length(const Vector3& p_vec);
	static inline float LengthSq(const Vector3& p_vec);
	static inline Vector3 Normalize(const Vector3& p_vec);
	static inline Vector3 Inverse(const Vector3& p_vec);
	static inline Vector3 Zero();
	static Vector3 Rotate(const Vector3& p_vec,  float p_angleRad);
	static Vector3 RotateX(const Vector3& p_vec, float p_angleRad);
	static Vector3 RotateY(const Vector3& p_vec, float p_angleRad);
	static Vector3 RotateZ(const Vector3& p_vec, float p_angleRad);
	static Vector3 Lerp(const Vector3& p_from, const Vector3& p_to, const float p_delta);
	//static Vector3 Slerp(const Vector3& p_from, const Vector3& p_to, const float p_delta);
	static Vector3 MoveTowards(const Vector3& p_from, const Vector3& p_to, const float p_delta);
	static inline Vector3 Cross(const Vector3& p_vecA, const Vector3& p_vecB);
	static inline float Dot(const Vector3& p_vecA, const Vector3& p_vecB);
	static inline float Distance(const Vector3& p_vecA, const Vector3& p_vecB);
	static inline float DistanceSq(const Vector3& p_vecA, const Vector3& p_vecB);
	static inline float AngleBetween(const Vector3& p_vecA, const Vector3& p_vecB);
	static inline float SignedAngleBetween(const Vector3& p_vecA, const Vector3& p_vecB, const Vector3& p_axis);
	static inline Vector3 Direction(const Vector3& p_vec, const Vector3& p_vecB);
	static inline Vector3 Project(const Vector3& p_vec, const Vector3& p_to);
	static inline Vector3 Slide(const Vector3& p_vec, const Vector3& p_normal);
	static inline Vector3 Bounce(const Vector3& p_vec, const Vector3& p_normal);
	static inline Vector3 Reflect(const Vector3& p_vec, const Vector3& p_normal);

	inline Vector3& operator+=(const Vector3& p_v);
	inline Vector3 operator+(const Vector3& p_v) const;
	inline Vector3& operator-=(const Vector3& p_v);
	inline Vector3 operator-(const Vector3& p_v) const;
	inline Vector3& operator*=(const Vector3& p_v);
	inline Vector3 operator*(const Vector3& p_v) const;
	inline Vector3& operator/=(const Vector3& p_v);
	inline Vector3 operator/(const Vector3& p_v) const;

	inline Vector3& operator*=(float p_scalar);
	inline Vector3 operator*(float p_scalar) const;
	inline friend Vector3 operator*(const float& p_scalar, const Vector3& p_vec);
	inline Vector3& operator/=(float p_scalar);
	inline Vector3 operator/(float p_scalar) const;

	inline Vector3 operator-() const;

	inline bool operator==(const Vector3& p_v) const;
	inline bool operator!=(const Vector3& p_v) const;
	inline bool operator<(const Vector3& p_v) const;
	inline bool operator<=(const Vector3& p_v) const;
	inline bool operator>(const Vector3& p_v) const;
	inline bool operator>=(const Vector3& p_v) const;

	union {
		struct {
			float x;
			float y;
			float z;
		};

		float coord[3] = { 0 };
	};
};