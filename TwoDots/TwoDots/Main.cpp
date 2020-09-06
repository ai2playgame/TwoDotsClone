#include <Siv3D.hpp>
#include "dot/DotsContainer.hpp"

void Main() {
	using namespace dot;
	Dot dot(Palette::Bisque, Scene::Center());
	DotsContainer container(10, 10, Vec2{ 100, 100 }, 40);
	while (System::Update()) {
		if (Key1.down()) {
			container.falldownLine1step(1);
		}
		container.update();
		container.draw();
	}
}