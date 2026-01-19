#pragma once
#include <vector>
#include "raylib.h"

struct Label {
	int x;
	int y;
	int font_size;
	const char* text;
};

class GUI {
	void draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (const Label& label : labels) {
			DrawText(label.text, label.x, label.y, label.font_size, BLACK);
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

	// GUI initializer
	GUI(int width, int height, const char* title) : width(width), height(height), title(title) {}

	// GUI constructors
	void addLabel(int x, int y, int font_size, const char* text) {
		Label new_label = { x,y,font_size,text };
		labels.push_back(new_label);
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
			draw();
		}

		// Close window
		CloseWindow();
	}
};