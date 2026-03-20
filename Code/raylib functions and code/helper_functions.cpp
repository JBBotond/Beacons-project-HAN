#include "helper_functions.hpp"
#include "raylib.h"

float sector_length_x()
{
	return GetScreenWidth() / 32;
}


float sector_length_y()
{
	return GetScreenHeight() / 32;
}



float cnvrt_to_sector_x(int x)
{
	float sector_size_x = GetScreenWidth() / 32;
	float sector_x = x * sector_size_x;
	return sector_x;
}


float cnvrt_to_sector_y(int y)
{
	float sector_size_y = GetScreenHeight() / 32;
	float sector_y = y * sector_size_y;
	return sector_y;
}



Vector2 cnvrt_to_sector(int x, int y)
{
	Vector2 sector_size = { GetScreenWidth() / 32, GetScreenHeight() / 32 };
	Vector2 sector{ x * sector_size.x, y * sector_size.y };
	return sector;
}
//----------------------------------------------------------
//rectangle button
//----------------------------------------------------------
void draw_button_rectangle(int startpos_x, int startpos_y, int width, int height, const char *button_name)
{
	Rectangle menu_button = { cnvrt_to_sector_x(startpos_x), cnvrt_to_sector_y(startpos_y), cnvrt_to_sector_x(width), cnvrt_to_sector_y(height)};
	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		DrawRectangleLinesEx(menu_button, 6, GREEN);

	else
		DrawRectangleLinesEx(menu_button, 6, RED);
	
	DrawText(button_name, cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_x(width)/2 - MeasureText(button_name, cnvrt_to_sector_y(height) - 30)/2, cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 - (cnvrt_to_sector_y(height) - 30) / 2, cnvrt_to_sector_y(height) - 30, RAYWHITE);
}



bool logic_button_rectangle(int startpos_x, int startpos_y, int width, int height)
{
	Rectangle menu_button = { cnvrt_to_sector_x(startpos_x), cnvrt_to_sector_y(startpos_y), cnvrt_to_sector_x(width), cnvrt_to_sector_y(height) };
	return bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) };
}
//----------------------------------------------------------
//dropdown menu
//----------------------------------------------------------
void draw_button_dropdown(int startpos_x, int startpos_y, int width, int height, const char* button_name)
{
	Rectangle menu_button = { cnvrt_to_sector_x(startpos_x), cnvrt_to_sector_y(startpos_y), cnvrt_to_sector_x(width), cnvrt_to_sector_y(height) };
	Color colour;
	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		colour = GREEN;
	else
		colour = RED;

	DrawRectangleLinesEx(menu_button, 6, colour);
	DrawLineEx(
		Vector2{ cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y) }, 
		Vector2{ cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y + height) }, 6, colour);
		DrawText(button_name, 
		cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_x(width) / 2 - cnvrt_to_sector_y(height)/2 - MeasureText(button_name, 
		cnvrt_to_sector_y(height) - 30) / 2, cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 - (cnvrt_to_sector_y(height) - 30) / 2,
		cnvrt_to_sector_y(height) - 30, RAYWHITE);
		DrawTriangle(
			Vector2{ cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 },
			Vector2{ cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height) + 15, cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 },
			Vector2{ cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height) - 15, cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 },
			colour);
}



//----------------------------------------------------------
//square button
//----------------------------------------------------------
void draw_button_square(int startpos_x, int startpos_y, int height, bool active, const char *button_name)
{
	Rectangle menu_button = { cnvrt_to_sector_x(startpos_x), cnvrt_to_sector_y(startpos_y), cnvrt_to_sector_y(height), cnvrt_to_sector_y(height) };
	Color colour;
	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		colour = GREEN;
	else
		colour = RED;
	DrawRectangleLinesEx(menu_button, 6, colour);
	if (active)
	{
		DrawLineEx(Vector2{ cnvrt_to_sector_x(startpos_x) + 15, cnvrt_to_sector_y(startpos_y) + 15 }, Vector2{ cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) - 15 }, 6, colour);
		DrawLineEx(Vector2{ cnvrt_to_sector_x(startpos_x) + 15, cnvrt_to_sector_y(startpos_y + 2) - 15 }, Vector2{ cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y + 2) - cnvrt_to_sector_y(height) + 15 }, 6, colour);

		DrawCircleV(Vector2{ cnvrt_to_sector_x(startpos_x) + 15, cnvrt_to_sector_y(startpos_y) + 15 }, 3, colour);
		DrawCircleV(Vector2{ cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) - 15 }, 3, colour);
		DrawCircleV(Vector2{ cnvrt_to_sector_x(startpos_x) + 15, cnvrt_to_sector_y(startpos_y + 2) - 15 }, 3, colour);
		DrawCircleV(Vector2{ cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height), cnvrt_to_sector_y(startpos_y + 2) - cnvrt_to_sector_y(height) + 15 }, 3, colour);
	}
	DrawText(button_name, cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_y(height + 1), cnvrt_to_sector_y(startpos_y) + 15, cnvrt_to_sector_y(height) - 30, RAYWHITE);
}



bool logic_button_square(int startpos_x, int startpos_y, int height)
{
	Rectangle menu_button = { cnvrt_to_sector_x(startpos_x), cnvrt_to_sector_y(startpos_y), cnvrt_to_sector_y(height), cnvrt_to_sector_y(height) };
	return bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) };
}
