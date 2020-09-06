#pragma once
#include <Siv3D.hpp>

namespace dot {

class LineSegment {
public:
	LineSegment(const Vec2& startPoint, const Color& color);

	void draw() const;
	void freeze(const Vec2 endPoiont);

private:
	Vec2 m_startPoint, m_endPoint;
	Color m_color;
	bool m_isFreeze;
};

}
