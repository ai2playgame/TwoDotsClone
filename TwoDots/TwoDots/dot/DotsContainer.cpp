#include "DotsContainer.hpp"

dot::DotsContainer::DotsContainer(size_t width, size_t height, Vec2 origin, float margin)
	: m_dotContainer(width, height)
	, m_origin(origin)
	, m_margin(margin)
{
	for (auto y : step(m_dotContainer.height())) {
		for (auto x : step(m_dotContainer.width())) {
			m_dotContainer[y][x] =
				Dot(Palette::Bisque, convertIndicesToPos(x, y));
		}
	}
}

void dot::DotsContainer::draw() const {
	for (const auto& dot : m_dotContainer) {
		dot.draw();
	}
}

void dot::DotsContainer::falldownLine1step(size_t line)
{
	// 最下段行以外は1つ下にずらす
	Dot dotCp = std::move(m_dotContainer[0][line]);
	for (auto y = 0; y < m_dotContainer.height() - 1; ++y) {
		dotCp.move(convertIndicesToPos(line, y + 1));
		std::swap(dotCp, m_dotContainer[y + 1][line]);
	}
	
	// 最上段行に1つドットを追加する
	Dot newDot(Palette::Green, calcSpawnPosByLine(line));
	newDot.move(convertIndicesToPos(line, 0));
	m_dotContainer[0][line] = std::move(newDot);
}

void dot::DotsContainer::update()
{
	for (auto& dot : m_dotContainer) {
		dot.update();
	}
}

Vec2 dot::DotsContainer::convertIndicesToPos(size_t x, size_t y)
{
	return m_origin + Vec2(m_margin * x, m_margin * y);
}

Vec2 dot::DotsContainer::calcSpawnPosByLine(size_t x)
{
	return m_origin + Vec2(m_margin * x, m_margin * -1);
}
