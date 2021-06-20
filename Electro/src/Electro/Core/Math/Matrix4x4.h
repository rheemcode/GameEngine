#pragma once

class Quaternion;
class Vector3;

typedef struct SimpleVec4
{
	union 
	{
		struct { float x, y, z, w;};
		struct { float r, g, b, a;};
	};

	SimpleVec4& operator +=(const SimpleVec4& p_vec)
	{
		this->x += p_vec.x;
		this->y += p_vec.y;
		this->z += p_vec.z;
		this->w += p_vec.w;

		return *this;
	}
	
	SimpleVec4 operator +(const SimpleVec4& p_vec) const
	{
		SimpleVec4 res;
		res.x + p_vec.x;
		res.y + p_vec.y;
		res.z + p_vec.z;
		res.w + p_vec.w;

		return res;
	}
	SimpleVec4 operator -(const SimpleVec4& p_vec) const
	{
		SimpleVec4 res;
		res.x - p_vec.x;
		res.y - p_vec.y;
		res.z - p_vec.z;
		res.w - p_vec.w;

		return res;
	}

	SimpleVec4 operator *(const SimpleVec4& p_vec) const
	{
		SimpleVec4 res;
		res.x * p_vec.x;
		res.y * p_vec.y;
		res.z * p_vec.z;
		res.w * p_vec.w;

		return res;
	}

	SimpleVec4 operator /(const SimpleVec4& p_vec) const
	{
		SimpleVec4 res;
		res.x / p_vec.x;
		res.y / p_vec.y;
		res.z / p_vec.z;
		res.w / p_vec.w;

		return res;
	}

	SimpleVec4 operator *(const float& s) const
	{
		SimpleVec4 res;
		res.x * s;
		res.y * s;
		res.z * s;
		res.w * s;

		return res;
	}
	SimpleVec4 operator /(const float& s) const
	{
		SimpleVec4 res;
		res.x / s;
		res.y / s;
		res.z / s;
		res.w / s;

		return res;
	}

	SimpleVec4 operator +(const float& s) const
	{
		SimpleVec4 res;
		res.x + s;
		res.y + s;
		res.z + s;
		res.w + s;

		return res;
	}

	SimpleVec4 operator -(const float& s) const
	{
		SimpleVec4 res;
		res.x - s;
		res.y - s;
		res.z - s;
		res.w - s;

		return res;
	}
	
	SimpleVec4& operator -=(const SimpleVec4& p_vec)
	{
		this->x -= p_vec.x;
		this->y -= p_vec.y;
		this->z -= p_vec.z;
		this->w -= p_vec.w;

		return *this;
	}

	SimpleVec4& operator *=(const SimpleVec4& p_vec)
	{
		this->x *= p_vec.x;
		this->y *= p_vec.y;
		this->z *= p_vec.z;
		this->w *= p_vec.w;

		return *this;
	}
	SimpleVec4& operator *=(const float& s)
	{
		this->x *= s;
		this->y *= s;
		this->z *= s;
		this->w *= s;

		return *this;
	}

	SimpleVec4& operator -=(const float& s)
	{
		this->x -= s;
		this->y -= s;
		this->z -= s;
		this->w -= s;
		return *this;
	}
	
	SimpleVec4& operator +=(const float& s)
	{
		this->x +=s;
		this->y +=s;
		this->z +=s;
		this->w +=s;
		return *this;
	}
	
	SimpleVec4& operator /=(const float& s)
	{
		this->x /= s;
		this->y /= s;
		this->z /= s;
		this->w /= s;

		return *this;
	}

	SimpleVec4& operator /=(const SimpleVec4& p_vec)
	{
		this->x /= p_vec.x;
		this->y /= p_vec.y;
		this->z /= p_vec.z;
		this->w /= p_vec.w;

		return *this;
	}
	
	const float& operator[](const int& p_index) const
	{
		switch (p_index)
		{
			case(0):  return x;
			case(1):  return y;
			case(2):  return z;
			case(3):  return w;
			default:  return 0;
		}
	}
	
	float& operator[](const int& p_index)
	{
		switch (p_index)
		{
			case(0):  return x;
			case(1):  return y;
			case(2):  return z;
			case(3):  return w;
			default:;
		}
	}

	bool operator ==(const SimpleVec4& p_vec)
	{
		return (this->x == p_vec.x && this->y == p_vec.y && this->z == p_vec.z && this->w == p_vec.w);
	}


	SimpleVec4()
		: x(0), y(0), z(0), w(0){}
	SimpleVec4(const float& p_x, const float& p_y, const float& p_z, const float& p_w)
		: x(p_x), y(p_y), z(p_z), w(p_w) {}
	SimpleVec4(const SimpleVec4& p_vec4)
		: x(p_vec4.x), y(p_vec4.y), z(p_vec4.z), w(p_vec4.w) {}

} colType;

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(const Matrix4x4& p_mat);
	Matrix4x4(const colType& col1, const colType& col2, const colType& col3, const colType& col4 );
	Matrix4x4(const float& s);
	Matrix4x4
	(
		const float& x0, const float& y0, const float& z0, const float& w0,
		const float& x1, const float& y1, const float& z1, const float& w1,
		const float& x2, const float& y2, const float& z2, const float& w2,
		const float& x3, const float& y3, const float& z3, const float& w3
	);


	const float* GetAsFloatPtr() const
	{
		return reinterpret_cast<const float*>(&m_data[0]);
	}


	friend Matrix4x4 operator*(const Matrix4x4& p_left, const Matrix4x4& p_right);
	Matrix4x4& operator*=(const Matrix4x4& p_matrix);
	colType operator[](const int& p_index) const;
	Matrix4x4& operator+=(const Matrix4x4& p_matrix);
	Matrix4x4& operator=(const Matrix4x4& p_matrix);
	bool operator==(const Matrix4x4& p_matrix);

	Matrix4x4 Inverse(const Matrix4x4& p_matrix);

	Vector3 GetTranslation() const;
	Vector3 GetXAxis() const;
	Vector3 GetYAxis() const;
	Vector3 GetZAxis() const;
	Vector3 GetScale() const;

	static Matrix4x4 CreateScale(const float& xScale, const float& yScale, const float& zScale);
	static Matrix4x4 CreateScale(const Vector3& scaleVector);
	static Matrix4x4 CreateScale(const float& scale);
	static Matrix4x4 Scale(const Matrix4x4& p_matrix, const Vector3& scaleVector);
	static Matrix4x4 CreateRotationX(const float& theta);
	static Matrix4x4 CreateRotationY(const float& theta);
	static Matrix4x4 CreateRotationZ(const float& theta);
	static Matrix4x4 Scale(const Matrix4x4& p_matrix, const float& xScale, const float& yScale, const float& zScale);
	static Matrix4x4 Scale(const Matrix4x4& p_matrix, const float& scale);
	static Matrix4x4 RotateX(const Matrix4x4& p_matrix, const float& theta);
	static Matrix4x4 RotateY(const Matrix4x4& p_matrix, const float& theta);
	static Matrix4x4 RotateZ(const Matrix4x4& p_matrix, const float& theta);
	static Matrix4x4 Rotate(const Quaternion& p_rotation);
	static Matrix4x4 Rotate(const Matrix4x4& p_matrix, const Quaternion& q);
	static Matrix4x4 Rotate(const Matrix4x4& p_matrix, const Vector3& p_axis, const float& p_theta);
	static Matrix4x4 CreateTranslation(const Vector3& trans);

	static Matrix4x4 Translate(const Matrix4x4& p_matrix, const Vector3& trans);

	static Matrix4x4 CreateLookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
	static Matrix4x4 LookAt(const Matrix4x4& p_matrix, const Vector3& eye, const Vector3& target, const Vector3& up);

	static float Determinant(const Matrix4x4& p_matrix);
	static Matrix4x4 Transpose(const Matrix4x4& p_matrix);
	static Matrix4x4 CreateOrtho(const float& p_left, const float& p_right, const float& p_bottom, const float& p_top, const float& p_zNear, const float& p_Zfar);
	static Matrix4x4 CreatePerspectiveFOV(const float& fovY, const float& width, const float& height, const float& near, const float& far);
	static Matrix4x4 CreatePerspective(const float& p_fov, const float& p_aspectRatio, const float& p_zNear, const float& p_zFar);
	static Matrix4x4 CreateFrustum(const float& left, const float& right, const float& bottom, const float& top, const float& nearVal, const float& farVal);
	
	static const Matrix4x4 Identity;

private:
	colType m_data[4];
};