#pragma once
#include <vector>
#include "raylib.h"

#include "area.h"

struct Label {
	int x;
	int y;
	int font_size;
	const char* text;
};
struct ClickDetector {
	Area area;
	const char* command;
};

class GUI {
	void handle() {
		Vector2 mpos = GetMousePosition();
		bool click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
		for (const ClickDetector& cd : clickdetectors) {
			bool inside_cd = PointInArea(mpos, cd.area);
			if (inside_cd && click) {
				system(cd.command);
			}
		}
	}
	void draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (const Label& label : labels) {
			DrawText(label.text, label.x, label.y, label.font_size, BLACK);
		}
		for (const ClickDetector& cd : clickdetectors) {
			DrawArea(cd.area);
		}
		EndDrawing();
	}
public:
	// Window properties
	const int width;
	const int height;
	const char* title;

	// Window contents
	std::vector<Label> labels;
	std::vector<ClickDetector> clickdetectors;

	// GUI initializer
	GUI(int width, int height, const char* title) : width(width), height(height), title(title) {}

	// GUI constructors
	void addLabel(int x, int y, int font_size, const char* text) {
		Label new_label = { x,y,font_size,text };
		labels.push_back(new_label);
	}
	void addButton(int x, int y, int font_size, const char* text, const char* command, int padding = 2) {
		Label new_label = { x,y,font_size,text };
		labels.push_back(new_label);

		int text_measure = TextLength(text) * font_size * 0.575;

		Area click_area = {
			x - padding,y - padding, // Minimum
			x + text_measure + padding, y + font_size + padding
		};
		ClickDetector new_cd = { click_area,command };
		clickdetectors.push_back(new_cd);
	}

	// Main GUI loop
	void show() {
		// Load window assets
		Image favicon = LoadImage("../../../favicon.png");
		// Create window
		InitWindow(width, height, title);
		SetWindowIcon(favicon);

		// Draw the window while open
		while (!WindowShouldClose()) {
			handle(); // Handle clicks
			draw();   // Draw GUI
		}

		// Close window
		CloseWindow();
	}
};