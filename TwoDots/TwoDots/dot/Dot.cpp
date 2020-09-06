#include "Dot.hpp"

dot::Dot::Dot(Color color, Vec2 initPos, float radius)
	: m_color(color)
	, m_pos(initPos)
	, m_posTo(initPos)
	, m_vel()
	, m_radius(radius)
{
}

void dot::Dot::move(Vec2 posTo)
{
	m_posTo = posTo;
}

void dot::Dot::update()
{
	if (m_pos == m_posTo) return;
	m_pos = Math::SmoothDamp(m_pos, m_posTo, m_vel, 0.06, Scene::DeltaTime());
}

void dot::Dot::draw() const
{
	Circle(m_pos, m_radius).draw(m_color);
}

bool dot::Dot::mouseOver() const
{
	const Circle circle(m_pos, m_radius);
	return circle.mouseOver();
}

bool dot::Dot::selected() const
{
	return false;
}

Color dot::Dot::getColor() const
{
	return m_color;
}
