#pragma once

class Quaternion;
class Matrix4x4;

class Transform
{
public:
	Transform() {}
	Transform(const Quaternion& p_rotation, const Vector3& p_position, const Vector3& p_scale);
	Transform(const Vector3& p_x, const class Vector3& p_y, const class Vector3& p_z, const class Vector3& p_position);
	Transform(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz, float ox, float oy, float oz);

    Vector3 InverseTransformDirection(const Vector3& direction);
    Vector3 InverseTransformDirection(float x, float y, float z);
    Vector3 InverseTransformPoint(float x, float y, float z);
    Vector3 InverseTransformPoint(const Vector3& position);
    Vector3 InverseTransformVector(const Vector3& vector);
    Vector3 InverseTransformVector(float x, float y, float z);

    void LookAt(Transform target, Vector3 worldUp);

    void LookAt(Vector3 worldPosition, [DefaultValue("Vector3.up")] Vector3 worldUp);
    void LookAt(Vector3 worldPosition);
    void LookAt(Transform target);
    void Rotate(float xAngle, float yAngle, float zAngle);
    void Rotate(Vector3 eulers);
    void Rotate(Vector3 axis, float angle);

    void SetParent(Transform& parent);
    bool IsChildOf(Transform& parent);
    void SetPositionAndRotation(Vector3 position, Quaternion rotation);
    void SetSiblingIndex(int index);

    void Translate(float x, float y, float z);
    void Translate(float x, float y, float z, Transform relativeTo);
    void Translate(Vector3 translation, Transform relativeTo);

    void SetPosition(const Vector3& p_vec);
    void SetScale(const Vector3& p_vec);
    void SetLocalScale(const Vector3& p_vec);
    void SetLocalPosition(const Vector3& p_vec);
    void SetEulerAngles(const Vector3& p_vec);
    void SetLocalEulerAngles(const Vector3& p_vec);
    void SetRotation(const Quaternion& p_rotation);
    void SetLocalRotation(const Quaternion& p_rotation);

    Vector3 GetPosition() const;
    Vector3 GetScale() const;
    Vector3 GetLocalScale() const;
    Vector3 GetLocalPosition() const;
    Vector3 GetEulerAngles() const;
    Vector3 GetLocalEulerAngle() const;
    Vector3 GetUpAxis() const;
    Vector3 GetRightAxis() const;
    Vector3 GetForwardAxis() const;
    const Quaternion GetRotation() const;
    const Quaternion GetLocalRotation() const;
    const Transform* GetParent() const;



private:
	Quaternion m_rotation;
	Vector3 m_position;
	Vector3 m_scale;

	Quaternion m_worldRotation;
	Vector3 m_worldPosition;
	Vector3 m_worldScale;

	Transform* m_parent;

    Matrix4x4 m_Elements;
};

