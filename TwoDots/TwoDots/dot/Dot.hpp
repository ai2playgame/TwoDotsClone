#pragma once
#include <Siv3D.hpp>

namespace dot {

class Dot {
public:
	Dot() = default;
	Dot(Color color, Vec2 initPos, float radius = 8);
	
	void move(Vec2 posTo);
	void update();
	void draw() const;

	void select();
	void unselect();
	void erase();

	bool mouseOver() const;
	bool isSelected() const;

	Color getColor() const;
	Vec2 getCenterPos() const;
private:
	Color m_color;
	Vec2 m_pos, m_posTo;
	Vec2 m_vel;
	float m_radius;
	bool m_selected;
	bool m_eraseFlag;
};

}
