#pragma once

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include "raylib.h"





using namespace std;
//--------------------------------------
// sectoring functions
// -------------------------------------
float sector_length_x();
float sector_length_y();
float cnvrt_to_sector_x(int x);
float cnvrt_to_sector_y(int y);
Vector2 cnvrt_to_sector(int x, int y);
//--------------------------------------
// rectangles
// -------------------------------------
void draw_button_rectangle
(
	int startpos_x, 
	int startpos_y, 
	int width,
	int height, 
	const char* button_name
);

bool logic_button_rectangle
(
	int startpos_x,
	int startpos_y,
	int width,
	int height
);



void draw_button_dropdown
(
	int startpos_x, 
	int startpos_y, 
	int width, 
	int height, 
	int options, 
	bool down_true,
	const char* button_name[], 
	int current_selection
);

int logic_button_dropdown
(
	int startpos_x,
	int startpos_y, 
	int width,
	int height,
	int options, 
	int option_selected, 
	bool* down_true
);

//--------------------------------------
// squares
// -------------------------------------
void draw_button_square
(
	int startpos_x, 
	int startpos_y, 
	int height,
	bool active, 
	const char* button_name
);

bool logic_button_square
(
	int startpos_x, 
	int startpos_y,
	int height
);
#endif