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
	Vector2 sector_size = 
	{ 
		GetScreenWidth() / 32, 
		GetScreenHeight() / 32 
	};

	Vector2 sector
	{
		x * sector_size.x,
		y * sector_size.y 
	};

	return sector;
}
//----------------------------------------------------------
//rectangle button
//----------------------------------------------------------
void draw_button_rectangle
(
	int startpos_x, 
	int startpos_y, 
	int width,
	int height,
	const char *button_name
)

{

	Rectangle menu_button = 
	{
		cnvrt_to_sector_x(startpos_x),
		cnvrt_to_sector_y(startpos_y),
		cnvrt_to_sector_x(width),
		cnvrt_to_sector_y(height)
	};

	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		DrawRectangleLinesEx(menu_button, 6, GREEN);

	else
		DrawRectangleLinesEx(menu_button, 6, RED);
	
	DrawText
	(
		button_name, 
		cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_x(width)/2 - MeasureText(button_name, 
		cnvrt_to_sector_y(height) - 30)/2, 
		cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 - (cnvrt_to_sector_y(height) - 30) / 2, 
		cnvrt_to_sector_y(height) - 30, 
		RAYWHITE
	);
}



bool logic_button_rectangle
(
	int startpos_x, 
	int startpos_y, 
	int width, 
	int height
)
{

	Rectangle menu_button = 
	{ 
		cnvrt_to_sector_x(startpos_x), 
		cnvrt_to_sector_y(startpos_y), 
		cnvrt_to_sector_x(width), 
		cnvrt_to_sector_y(height) 
	};

	return bool
	{
		CheckCollisionPointRec(GetMousePosition(), menu_button)
		&& 
		IsMouseButtonPressed(MOUSE_BUTTON_LEFT) 
	};
}
//----------------------------------------------------------
//dropdown menu
//----------------------------------------------------------


void draw_button_dropdown
(
	int startpos_x, 
	int startpos_y, 
	int width, 
	int height, 
	int options, 
	bool down_false, 
	const char* button_name[], 
	int current_selection
)

{
	Rectangle menu_button = 
	{
		cnvrt_to_sector_x(startpos_x), 
		cnvrt_to_sector_y(startpos_y), 
		cnvrt_to_sector_x(width), 
		cnvrt_to_sector_y(height) 
	};

	Color colour;
	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		colour = GREEN;
	else
		colour = RED;

	DrawRectangleLinesEx(menu_button, 6, colour);

	DrawLineEx
	(
		Vector2
		{ 
			cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height), 
			cnvrt_to_sector_y(startpos_y) 
		}, 
		Vector2
		{ 
			cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height), 
			cnvrt_to_sector_y(startpos_y + height) 
		},
		6, colour
	);

	DrawText
	(
		button_name[current_selection],
		cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_x(width) / 2 - cnvrt_to_sector_y(height)/2 - MeasureText(button_name[current_selection],
		cnvrt_to_sector_y(height) - 30) / 2, 
		cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 - (cnvrt_to_sector_y(height) - 30) / 2,
		cnvrt_to_sector_y(height) - 30, 
		RAYWHITE
	);

	if (!down_false)
		{
			DrawPolyLinesEx
			(
				Vector2
				{ 
					cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height) / 2 - 3 / 2,
					cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 
				},
				3, 15, 0, 6, colour
			);

			for (int count = 0; count < options; count++)
			{
				DrawRectangle
				(
					cnvrt_to_sector_x(startpos_x + width), 
					cnvrt_to_sector_y(startpos_y + count * height),
					cnvrt_to_sector_x(width),
					cnvrt_to_sector_y(height), 
					BLACK // <-- replace "BLACK" with your used background colour.
				);
				Rectangle sub_button
				{
					cnvrt_to_sector_x(startpos_x + width),
					cnvrt_to_sector_y(startpos_y + count * height),
					cnvrt_to_sector_x(width),
					cnvrt_to_sector_y(height),
				};

				Color sub_colour;
				if (CheckCollisionPointRec(GetMousePosition(), sub_button))
					sub_colour = GREEN;
				else
					sub_colour = RED;

				DrawRectangleLinesEx(sub_button,6,sub_colour);

				DrawText
				(
					button_name[count],
					cnvrt_to_sector_x(startpos_x + width) + cnvrt_to_sector_x(width) / 2 - MeasureText
						(
							button_name[count],
							cnvrt_to_sector_y(height) - 30
						) / 2,
					cnvrt_to_sector_y(startpos_y + height * count) + cnvrt_to_sector_y(height) / 2 - (cnvrt_to_sector_y(height) - 30) / 2,
					cnvrt_to_sector_y(height) - 30,
					RAYWHITE
				);

				
			}
		}
	else
		DrawPolyLinesEx
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x + width) - cnvrt_to_sector_y(height) / 2 - 3 / 2, 
				cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) / 2 
			}, 
			3, 15, -90, 6, colour
		);
}

int logic_button_dropdown
(
	int startpos_x, 
	int startpos_y, 
	int width, 
	int height,
	int options,
	int option_selected,
	bool* down_false
)

{
	Rectangle menu_button = 
	{ 
		cnvrt_to_sector_x(startpos_x), 
		cnvrt_to_sector_y(startpos_y), 
		cnvrt_to_sector_x(width), 
		cnvrt_to_sector_y(height) 
	};
	if (CheckCollisionPointRec(GetMousePosition(), menu_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		*down_false = !*down_false;
	}
	if (!*down_false)
	{
		for (int count = 0; count < options; count++)
		{
			Rectangle sub_button
			{
				cnvrt_to_sector_x(startpos_x + width),
				cnvrt_to_sector_y(startpos_y + count * height),
				cnvrt_to_sector_x(width),
				cnvrt_to_sector_y(height),
			};

			if (CheckCollisionPointRec(GetMousePosition(), sub_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				option_selected = count + 1;
			}
		}
	}
	return option_selected;
}



//----------------------------------------------------------
//square button
//----------------------------------------------------------
void draw_button_square
(
	int startpos_x,
	int startpos_y, 
	int height, 
	bool active,
	const char *button_name
)

{
	Rectangle menu_button = 
	{ 
		cnvrt_to_sector_x(startpos_x), 
		cnvrt_to_sector_y(startpos_y), 
		cnvrt_to_sector_y(height), 
		cnvrt_to_sector_y(height)
	};

	Color colour;
	if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) })
		colour = GREEN;
	else
		colour = RED;
	DrawRectangleLinesEx(menu_button, 6, colour);
	if (active)
	{
		DrawLineEx
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) + 15,
				cnvrt_to_sector_y(startpos_y) + 15 
			}, 
				Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height), 
				cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) - 15 
			}, 
			6, colour
		);

		DrawLineEx
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) + 15,
				cnvrt_to_sector_y(startpos_y + 2) - 15 
			}, 
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height),
				cnvrt_to_sector_y(startpos_y + 2) - cnvrt_to_sector_y(height) + 15 
			},
			6, colour
		);

		DrawCircleV
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) + 15, 
				cnvrt_to_sector_y(startpos_y) + 15 
			}, 
			3, colour
		);

		DrawCircleV
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height),
				cnvrt_to_sector_y(startpos_y) + cnvrt_to_sector_y(height) - 15 
			}, 
			3, colour
		);

		DrawCircleV
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) + 15,
				cnvrt_to_sector_y(startpos_y + 2) - 15 
			}, 
			3, colour
		);

		DrawCircleV
		(
			Vector2
			{ 
				cnvrt_to_sector_x(startpos_x) - 15 + cnvrt_to_sector_y(height),
				cnvrt_to_sector_y(startpos_y + 2) - cnvrt_to_sector_y(height) + 15 
			}, 
			3, colour
		);
	}

	DrawText
	(
		button_name, 
		cnvrt_to_sector_x(startpos_x) + cnvrt_to_sector_y(height + 1),
		cnvrt_to_sector_y(startpos_y) + 15, 
		cnvrt_to_sector_y(height) - 30, 
		RAYWHITE
	);
}



bool logic_button_square
(
	int startpos_x,
	int startpos_y, 
	int height
)

{
	Rectangle menu_button = 
	{ 
		cnvrt_to_sector_x(startpos_x), 
		cnvrt_to_sector_y(startpos_y), 
		cnvrt_to_sector_y(height), 
		cnvrt_to_sector_y(height) 
	};

	return bool
	{
		CheckCollisionPointRec(GetMousePosition(), menu_button)
		&&
		IsMouseButtonPressed(MOUSE_BUTTON_LEFT) 
	};
}
