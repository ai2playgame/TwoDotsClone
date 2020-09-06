#include <Siv3D.hpp>
#include "dot/DotsContainer.hpp"
#include "dot/LineSegment.hpp"

Array<dot::LineSegment> lines;
dot::DotsContainer dots(10, 10, Vec2{ 100, 100 }, 40);
Array<std::pair<size_t, size_t>> indexPairs;

void addNextPoint() {
	for (auto y : step(dots.m_dotContainer.height())) {
		for (auto x : step(dots.m_dotContainer.width())) {
			auto& checkDot = dots.m_dotContainer[y][x];

			// マウスの下にドットがあれば端点に追加
			if (checkDot.mouseOver()) {
				// 選択済ドットは2重で選べない
				if (checkDot.isSelected()) {
					return;
				}

				// 隣あっていないドットなら線分は引けない
				auto indexPair = indexPairs.back();

				ClearPrint();
				Print << U"f - x: {}, f - y: {}"_fmt(
					Abs((long long)indexPair.first - (long long)x),
					Abs((long long)indexPair.second - (long long)y)
				);

				if (Abs((long long)indexPair.first - (long long)x)
					+
					Abs((long long)indexPair.second - (long long)y) >= 2
					) {
					Print << U"Too far";
					return;
				}

				// そのドットを選択状態に
				checkDot.select();
				// 線分の位置確定
				lines.back().freeze(checkDot.getCenterPos());
				// 新しく線を書き始める
				lines.push_back(dot::LineSegment(checkDot.getCenterPos(),
												 checkDot.getColor()));
				// そのインデックスを保存しておく
				indexPairs.push_back(std::make_pair(x, y));
				return;
			}
		}
	}
}

void Main() {
	lines.clear();
	indexPairs.clear();
	while (System::Update()) {
		// まだ線分を書き始めていない
		if (indexPairs.size() == 0) {
			// マウスを押していれば
			if (MouseL.down()) {
				// ドットを全探索
				for (auto y : step(dots.m_dotContainer.height())) {
					for (auto x : step(dots.m_dotContainer.width())) {
						auto& checkDot = dots.m_dotContainer[y][x];
						// マウスの下にドットがあれば
						if (checkDot.mouseOver()) {
							// ドットを選択
							checkDot.select();
							// 線を書き始める
							lines.push_back(dot::LineSegment(checkDot.getCenterPos(),
															 checkDot.getColor()));
							// そのインデックスを保存しておく
							indexPairs.push_back(std::make_pair(x, y));
						}
					}
				}
			}
		}
		// 既に線分を1本以上引いている
		else {
			// 線分を引いている状態でマウスを押したらドットを消す
			if (MouseL.down()) {
				// 1個しか選択してないなら、線分とインデックスバッファだけ初期化
				
				// 2個以上のドットを選択していればドットを消して、諸々初期化

				// TODO: とりあえず線分とインデックスバッファの初期化だけ実装
				lines.clear();
				indexPairs.clear();
				// ドットの選択状態を解除
				for (auto& dot : dots.m_dotContainer) {
					dot.unselect();
				}
			}
			// マウスを左クリックしていない
			else {
				addNextPoint();
			}
		}

		dots.update();
		dots.draw();

		// for (auto& line : lines) line.update();
		for (const auto& line : lines) line.draw();

		if (Key1.down()) {
			// TODO: とりあえずログ
			for (const auto& [x, y] : indexPairs) {
				Logger << U"({}, {})"_fmt(x, y);
			}
		}

	}

}