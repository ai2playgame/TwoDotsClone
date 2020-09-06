#include "LineSegment.hpp"

dot::LineSegment::LineSegment(const Vec2& startPoint, const Color& color)
	: m_startPoint(startPoint)
	, m_endPoint()
	, m_color(color)
	, m_isFreeze(false)
{
}

void dot::LineSegment::draw() const
{
	if (m_isFreeze) {
		Line(m_startPoint, m_endPoint).draw(6, m_color);
	}
	else {
		Line(m_startPoint, Cursor::Pos()).draw(6, m_color);
	}
}

void dot::LineSegment::freeze(const Vec2 endPoiont)
{
	m_endPoint = endPoiont;
	m_isFreeze = true;
}
