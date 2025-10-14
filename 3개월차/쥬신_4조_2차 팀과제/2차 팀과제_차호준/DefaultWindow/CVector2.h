#pragma once
#include <cmath>	

class CVector2
{

public:
	CVector2() : m_x(0), m_y(0) {}
	CVector2(float _x, float _y) : m_x(_x), m_y(_y) {}
	~CVector2() {}

	float GetX() const { return m_x; }
	float GetY() const { return m_y; }
	void Set(float _x, float _y) { m_x = _x; m_y = _y; }

	CVector2 operator+(const CVector2& other) const { return CVector2(m_x + other.m_x, m_y + other.m_y); }
	CVector2 operator-(const CVector2& other) const { return CVector2(m_x - other.m_x, m_y - other.m_y); }
	CVector2 operator*(float scalar) const { return CVector2(m_x * scalar, m_y * scalar); }


private:
	float m_x;
	float m_y;

public:
	static  float Length(float _x, float _y) { return sqrtf(_x * _x + _y * _y); }	// 길이
	static  CVector2 Lerp(CVector2 start, CVector2 end, float t)					// 선형보간
	{
		return {
			start.m_x + (end.m_x - start.m_x) * t,
			start.m_y + (end.m_y - start.m_y) * t
		};
	}

	static float EaseInOut(float t)													// Lerp progress용 빨리왔다 천천히 도착
	{
		return t * t * (3.0f - 2.0f * t);
	}

	static  CVector2 Normailize(float _x, float _y)									// 정규화
	{
		float len = Length(_x, _y);

		if (len == 0.0f)
			return { 0.0f, 0.0f };

		return { _x / len, _y / len };
	}
};