#pragma once
struct Area {
	int min_x;
	int min_y;
	int max_x;
	int max_y;
};

bool PointInArea(Vector2 point, Area area) {
	return area.min_x <= point.x && point.x <= area.max_x && area.min_y <= point.y && point.y <= area.max_x;
}

void DrawArea(Area area) {
	DrawLine(area.min_x, area.min_y, area.max_x, area.min_y, RED);
	DrawLine(area.max_x, area.min_y, area.max_x, area.max_y, RED);
	DrawLine(area.max_x, area.max_y, area.min_x, area.max_y, RED);
	DrawLine(area.min_x, area.max_y, area.min_x, area.min_y, RED);
}