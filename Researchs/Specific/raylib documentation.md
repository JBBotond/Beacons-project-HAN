short documentation on usefull functions for raylib;

use the cheat sheet to see all functions
https://www.raylib.com/cheatsheet/cheatsheet.html

Vector2: just a struct with 2 floats in it (x and y)


a method of sectoring your screen (example):

```
Vector2 cnvrt_to_sector(int x, int y)
{
	
	Vector2 sector_size = { GetScreenWidth() / 32, GetScreenHeight() / 32 };
	Vector2 sector{ x * sector_size.x, y * sector_size.y };
	return sector;
}

```


```
bool CheckCollisionPointRec(Vector2 point, Rectangle rec);
```
returns 1 if a point and a rectangle overlap, rectangle is x pos origin, y pos origin, x length, y length

example:
```
for (int c = 1; c < 6; c++)
{
    Rectangle menu_button = { cnvrt_to_sector(3, c * 3 + 5).x, cnvrt_to_sector(3, c * 3 + 5).y, cnvrt_to_sector(5, 2).x, cnvrt_to_sector(5, 2).y };

    switch (c)
    {
    case 1: // continue
        if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(menu_select);
        }
        break;
    case 2: // load profile
        if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(menu_select);
        }
        break;
    case 3: // new profile
        if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(menu_select);
        }
        break;
    case 4: // settings
        if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(menu_select);
        }
        break;
    case 5: // quit
        if (bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(menu_select);
            program_should_run = 0;

        }
        break;
    default:
        break;
    }
```


this function first creates a rectangle that's shifter over $3*c$ and increments c by one 5 times (starting at 1) this creates 5 buttons each 3 sectors wide and 2 sectors tall and one sector apart below each other, (sector was previously stated to be 1/32nd of screen Hight/width).

the switch statement looks at what c is and if mouse possition is 1 or 0 and exicudes the code, you could multiply c by 10 and add bool{CheckCollisionPointRec(GetMousePosition(), menu_button)} and make the cases 11, 21, 31, 41 and 51.

with the second method it should look something like the following:

for (int c = 1; c < 6; c++)
{
    Rectangle menu_button = { cnvrt_to_sector(3, c * 3 + 5).x, cnvrt_to_sector(3, c * 3 + 5).y, cnvrt_to_sector(5, 2).x, cnvrt_to_sector(5, 2).y };

    switch (c * 10 + bool{ CheckCollisionPointRec(GetMousePosition(), menu_button) } && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
    case 11: // continue
            PlaySound(menu_select);
        break;
    case 21: // load profile
            PlaySound(menu_select);
        break;
    case 31: // new profile
            PlaySound(menu_select);
        break;
    case 41: // setting
            PlaySound(menu_select);
        break;
    case 51: // quit
            PlaySound(menu_select);
            program_should_run = 0;
        break;
    default: // none clicked on
        break;
    }



