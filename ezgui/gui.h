#pragma once
#include <vector>
#include "raylib.h"

struct TextLabel {
	Vector2 pos;      // Label position
	int font_size;    // Label font size
	Color font_color; // Label text color
	const char* text; // Label text
};
struct ClickDetector {
	Rectangle rect;      // Position and size
	const char* command; // Command to run on click
};
struct ColorRect {
	Rectangle rect;
	Color bg_color;
	Color border_color;
};
struct ImageRect {
	Rectangle rect;
	Image image;

	Texture _texture;
};

class GUI {
	void init() {
		for (ImageRect& ir : imagerects) {
			ir._texture = LoadTextureFromImage(ir.image);
		}
	}
	void handle() {
		Vector2 mpos = GetMousePosition();
		bool click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
		for (const ClickDetector& cd : clickdetectors) {
			bool inside_cd = CheckCollisionPointRec(mpos,cd.rect);
			if (inside_cd && click) {
				system(cd.command);
			}
		}
	}
	void draw() {
		// TO-DO:
		// - Add drawing order

		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (const ImageRect& ir : imagerects) {
			DrawTexturePro(ir._texture, { 0,0,(float)ir.image.width,(float)ir.image.height }, ir.rect, { 0 }, 0, WHITE);
		}
		for (const ColorRect& cr : colorrects) {
			DrawRectangleRec(cr.rect, cr.bg_color);
			DrawRectangleLinesEx(cr.rect,2.0f,cr.border_color);
		}
		for (const TextLabel& label : labels) {
			DrawTextEx(GetFontDefault(), label.text, label.pos, label.font_size, 2, label.font_color);
		}
		EndDrawing();
	}
public:
	// Window properties
	const int width;
	const int height;
	const char* title;

	// Window contents
	std::vector<ImageRect> imagerects;
	std::vector<ColorRect> colorrects;
	std::vector<TextLabel> labels;
	std::vector<ClickDetector> clickdetectors;

	// GUI initializer
	GUI(int width, int height, const char* title) : width(width), height(height), title(title) {}

	// GUI constructors
	void addTextLabel(int x, int y, int font_size, Color font_color, const char* text) {
		TextLabel new_label = { x,y,font_size,font_color,text };
		labels.push_back(new_label);
	}
	void addImageLabel(int x, int y, int width, int height, const char* filename) {
		Rectangle label_rect = { x,y,width,height };
		Image image = LoadImage(filename);
		ImageResize(&image, width, height);
		ImageRect new_image_label = { label_rect,image };
		imagerects.push_back(new_image_label);
	}
	void addTextButton(int x, int y, int font_size, Color font_color, const char* text, Color bg_color, Color border_color, const char* command, int padding = 2) {
		TextLabel new_label = { x,y,font_size,font_color,text };
		labels.push_back(new_label);

		int text_measure = TextLength(text) * font_size * 0.575;

		Rectangle click_area = {
			x - padding,y - padding,
			text_measure + padding, font_size + padding,
		};

		ClickDetector new_cd = { click_area, command };
		clickdetectors.push_back(new_cd);

		ColorRect new_colorrect = { click_area, bg_color, border_color };
		colorrects.push_back(new_colorrect);
	}

	// Main GUI loop
	void show() {
		// Load window assets
		Image favicon = LoadImage("../../../favicon.png");
		// Create window
		InitWindow(width, height, title);
		SetWindowIcon(favicon);

		// Init GUI assets
		init();

		// Draw the window while open
		while (!WindowShouldClose()) {
			handle(); // Handle clicks
			draw();   // Draw GUI
		}

		// Close window
		CloseWindow();
	}
};