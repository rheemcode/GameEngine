#include "elpch.h"

#include "Vector2.h"
#include "Math/Vector3.h"

Vector3::Vector3(const Vector2& p_vec)
	: x(p_vec.x), y(p_vec.y), z(0) {}

Vector3 Vector3::Abs(const Vector3& p_vec)
{
	return Vector3(Math::Abs(p_vec.x), Math::Abs(p_vec.y), Math::Abs(p_vec.z));
}

Vector3 Vector3::Sign(const Vector3& p_vec)
{
	return Vector3(Math::Sign(p_vec.x), Math::Sign(p_vec.y), Math::Sign(p_vec.z));
}

Vector3 Vector3::Floor(const Vector3& p_vec)
{
	return Vector3(Math::Floor(p_vec.x), Math::Floor(p_vec.y), Math::Floor(p_vec.z));
}

Vector3 Vector3::Ceil(const Vector3& p_vec)
{
	return Vector3(Math::Ceil(p_vec.x), Math::Ceil(p_vec.y), Math::Ceil(p_vec.z));
}

Vector3 Vector3::Round(const Vector3& p_vec)
{
	return Vector3(Math::Round(p_vec.x), Math::Round(p_vec.y), Math::Round(p_vec.z));
}

Vector3 Vector3::Cross(const Vector3& p_a, const Vector3& p_b)
{
	Vector3 temp;
	temp.x = p_a.y * p_b.z - p_a.z * p_b.y;
	temp.y = p_a.z * p_b.x - p_a.x * p_b.z;
	temp.z = p_a.x * p_b.y - p_a.y * p_b.x;
	return temp;
}

float Vector3::Dot(const Vector3& p_a, const Vector3& p_b)
{
	return p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z;
}

inline float Vector3::AngleBetween(const Vector3& p_vecA, const Vector3& p_vecB)
{
	return 0.0f;
}

Vector3 Vector3::RotateX(const Vector3& p_vec, float p_angleRad)
{
	return Vector3(
		p_vec.x, 
		p_vec.y * Math::Cos(p_angleRad) - p_vec.z * Math::Sin(p_angleRad),
		p_vec.y * Math::Sin(p_angleRad) + p_vec.z * Math::Cos(p_angleRad)
		);
}

Vector3 Vector3::RotateY(const Vector3& p_vec, float p_angleRad)
{
	return Vector3(
		p_vec.x * Math::Cos(p_angleRad) + p_vec.z * Math::Sin(p_angleRad),
		p_vec.y,
		-p_vec.x * Math::Sin(p_angleRad) + p_vec.z * Math::Cos(p_angleRad)
		);
}

Vector3 Vector3::RotateZ(const Vector3& p_vec, float p_angleRad)
{
	return Vector3(
		p_vec.x * Math::Cos(p_angleRad) - p_vec.y * Math::Sin(p_angleRad),
		p_vec.x * Math::Sin(p_angleRad) + p_vec.y * Math::Cos(p_angleRad),
		p_vec.z
		);
}

Vector3 Vector3::Lerp(const Vector3& p_from, const Vector3& p_to, const float p_delta)
{
	return Vector3
	(
		Math::Lerp(p_from.x, p_to.x, p_delta),
		Math::Lerp(p_from.y, p_to.y, p_delta),
		Math::Lerp(p_from.z, p_to.z, p_delta)
	);
}

Vector3 Vector3::MoveTowards(const Vector3& p_from, const Vector3& p_to, const float p_delta)
{
	return Vector3();
}

Vector3 Vector3::Normalize(const Vector3& p_vec)
{
	float length = Vector3::Length(p_vec);
	return Vector3 (p_vec.x / length, p_vec.y / length, p_vec.z / length);
}


float Vector3::Length(const Vector3& p_vec)
{
	return Math::Sqrt(Vector3::Dot(p_vec, p_vec));
}

float Vector3::LengthSq(const Vector3& p_vec)
{
	return Vector3::Dot(p_vec, p_vec);
}

Vector3 Vector3::Direction(const Vector3& p_from, const Vector3& p_to)
{
	return Normalize(p_to - p_from);
}

float Vector3::Distance(const Vector3& p_from, const Vector3& p_to)
{
	return Vector3::Length((p_from - p_to));
}

float Vector3::DistanceSq(const Vector3& p_from, const Vector3& p_to)
{
	return LengthSq((p_from - p_to));
}

//float Vector3::AngleBetween(const Vector3& p_vecA, const Vector3& p_vecB)
//{
//	float dotP = Dot(p_vecA, p_vecB);
//	float mag = Math::Sqrt(Dot(p_vecA, p_vecA)) * Math::Sqrt(Dot(p_vecB, p_vecB));
//
//	return Math::ACos(dotP / mag);
//}

float Vector3::AngleBetween(const Vector3& p_vecA, const Vector3& p_vecB)
{
	return Math::ACos(Dot(Normalize(p_vecA), Normalize(p_vecB)));
}

float Vector3::SignedAngleBetween(const Vector3& p_vecA, const Vector3& p_vecB, const Vector3& p_axis)
{
	Vector3 crossTo = Cross(p_vecA, p_vecB);
	float unsignedAngle = AngleBetween(p_vecA, p_vecB);

	float sign = Dot(crossTo, p_axis);
	return (sign < 0) ? -unsignedAngle : unsignedAngle;

}

Vector3 Vector3::Project(const Vector3& p_vec, const Vector3& p_to)
{
	return p_to * (Vector3::Dot(p_vec, p_to)) / Vector3::LengthSq(p_to);
}

inline Vector3 Vector3::Slide(const Vector3& p_vec, const Vector3& p_normal)
{
	return p_vec - p_normal * Dot(p_vec, p_normal);
}

inline Vector3 Vector3::Bounce(const Vector3& p_vec, const Vector3& p_normal)
{
	return -Reflect(p_vec, p_normal);
}

inline Vector3 Vector3::Reflect(const Vector3& p_vec, const Vector3& p_normal)
{
	return  (p_normal * 2.0f) * Dot(p_vec, p_normal) - p_vec;
}

inline Vector3 Vector3::Inverse(const Vector3& p_vec)
{
	return Vector3(1 / p_vec.x, 1 / p_vec.y, 1 / p_vec.z);
}

inline Vector3 Vector3::Zero()
{
	return Vector2();
}




Vector3& Vector3::operator+=(const Vector3& p_v) {
	x += p_v.x;
	y += p_v.y;
	z += p_v.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& p_v) const {
	return Vector3(x + p_v.x, y + p_v.y, z + p_v.z);
}

Vector3& Vector3::operator-=(const Vector3& p_v) {
	x -= p_v.x;
	y -= p_v.y;
	z -= p_v.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& p_v) const {
	return Vector3(x - p_v.x, y - p_v.y, z - p_v.z);
}

Vector3& Vector3::operator*=(const Vector3& p_v) {
	x *= p_v.x;
	y *= p_v.y;
	z *= p_v.z;
	return *this;
}

Vector3 Vector3::operator*(const Vector3& p_v) const {
	return Vector3(x * p_v.x, y * p_v.y, z * p_v.z);
}

Vector3& Vector3::operator/=(const Vector3& p_v) {
	x /= p_v.x;
	y /= p_v.y;
	z /= p_v.z;
	return *this;
}

Vector3 Vector3::operator/(const Vector3& p_v) const {
	return Vector3(x / p_v.x, y / p_v.y, z / p_v.z);
}

Vector3& Vector3::operator*=(float p_scalar) {
	x *= p_scalar;
	y *= p_scalar;
	z *= p_scalar;
	return *this;
}

inline Vector3 operator*(float p_scalar, const Vector3& p_vec) {
	return p_vec * p_scalar;
}

Vector3 Vector3::operator*(float p_scalar) const {
	return Vector3(x * p_scalar, y * p_scalar, z * p_scalar);
}

Vector3& Vector3::operator/=(float p_scalar) {
	x /= p_scalar;
	y /= p_scalar;
	z /= p_scalar;
	return *this;
}

Vector3 Vector3::operator/(float p_scalar) const {
	return Vector3(x / p_scalar, y / p_scalar, z / p_scalar);
}

Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

bool Vector3::operator==(const Vector3& p_v) const {
	return x == p_v.x && y == p_v.y && z == p_v.z;
}

bool Vector3::operator!=(const Vector3& p_v) const {
	return x != p_v.x || y != p_v.y || z != p_v.z;
}

bool Vector3::operator<(const Vector3& p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z < p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

bool Vector3::operator>(const Vector3& p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z > p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

bool Vector3::operator<=(const Vector3& p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z <= p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

bool Vector3::operator>=(const Vector3& p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z >= p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

