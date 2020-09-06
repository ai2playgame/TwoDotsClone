#pragma once
#include <Siv3D.hpp>

namespace dot {

class LineSegment {
public:
	LineSegment(const Vec2 startPoint);

	void draw();
	void freeze(const Vec2 endPoiont);

private:
	Vec2 m_startPoint, m_endPoint;
	bool m_isFreeze;
};

}
