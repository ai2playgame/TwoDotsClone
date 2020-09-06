#include "Dot.hpp"

dot::Dot::Dot(Color color, Vec2 initPos, float radius)
	: m_color(color)
	, m_pos(initPos)
	, m_posTo(initPos)
	, m_vel()
	, m_radius(radius)
	, m_selected(false)
	, m_eraseFlag(false)
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
	Circle circle(m_pos, m_radius);
	if (circle.mouseOver()) {
		circle.drawFrame(4.0, Palette::Red);
	}
	circle.draw(m_color);
}

void dot::Dot::select()
{
	m_selected = true;
}

void dot::Dot::unselect()
{
	m_selected = false;
}

bool dot::Dot::mouseOver() const
{
	const Circle circle(m_pos, m_radius);
	return circle.mouseOver();
}

bool dot::Dot::isSelected() const
{
	return m_selected;
}

Color dot::Dot::getColor() const
{
	return m_color;
}

Vec2 dot::Dot::getCenterPos() const
{
	return m_pos;
}
