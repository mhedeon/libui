#include "checkbox.h"

#define BLACK &(SDL_Color){0, 0, 0, 0}

static void draw_check_off(t_window* win, int x, int y)
{
	color_area(win, &(SDL_Rect){x, y, CHECKBOX_SIZE, CHECKBOX_SIZE},
		& (SDL_Color){255, 255, 255, 0});

	color_area(win, &(SDL_Rect){x, y, CHECKBOX_SIZE, 1}, BLACK);
	color_area(win, &(SDL_Rect){x, y + 1, CHECKBOX_SIZE, 1}, BLACK);
	color_area(win, &(SDL_Rect){x, y + CHECKBOX_SIZE - 1, CHECKBOX_SIZE, 1},
		BLACK);
	color_area(win, &(SDL_Rect){x, y + CHECKBOX_SIZE - 2, CHECKBOX_SIZE, 1},
		BLACK);

	color_area(win, &(SDL_Rect){x, y, 1, CHECKBOX_SIZE}, BLACK);
	color_area(win, &(SDL_Rect){x + 1, y, 1, CHECKBOX_SIZE}, BLACK);
	color_area(win, &(SDL_Rect){x + CHECKBOX_SIZE - 1, y, 1, CHECKBOX_SIZE},
		BLACK);
	color_area(win, &(SDL_Rect){x + CHECKBOX_SIZE - 2, y, 1, CHECKBOX_SIZE},
		BLACK);
}

static void draw_check_on(t_window* win, int x, int y)
{
	draw_check_off(win, x, y);

	color_area(win, &(SDL_Rect){x + 10, y + 3, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 10, y + 4, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 9, y + 5, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 9, y + 6, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 8, y + 7, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 8, y + 8, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 7, y + 9, 2, 1}, BLACK);

	color_area(win, &(SDL_Rect){x + 3, y + 8, 2, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 3, y + 9, 3, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 4, y + 10, 5, 1}, BLACK);
	color_area(win, &(SDL_Rect){x + 5, y + 11, 3, 1}, BLACK);
}

void draw_checkbox(t_window* win, t_checkbox* check)
{
	if (check == NULL)
	{
		error_log("Invalid pointer to checkbox");
		return;
	}
	if (check->status == CHECK_ON)
		draw_check_on(win, check->pos.x, check->pos.y);
	else if (check->status == CHECK_OFF)
		draw_check_off(win, check->pos.x, check->pos.y);
	else
		error_log("Incorrect state checkbox");
}