#pragma once
#include "Dot.hpp"
#include <Siv3D/Grid.hpp>

namespace dot {

class DotsContainer {
public:
	DotsContainer() = default;
	DotsContainer(size_t width, size_t height, Vec2 m_origin, float m_margin = 45);

	void update();
	void draw() const;
	
	void falldownLine1step(size_t line);

	Vec2 convertIndicesToPos(size_t x, size_t y);
	Vec2 calcSpawnPosByLine(size_t x);
	
	// TODO: ƒƒ“ƒo•Ï”‚Íâ‘Îpublic‚Éo‚·‚×‚«‚Å‚Í‚È‚¢I
	Grid<Dot> m_dotContainer;
private:
	Vec2 m_origin;
	float m_margin;
};

}
