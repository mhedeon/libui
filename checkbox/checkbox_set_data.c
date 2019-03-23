#include "libmgl.h"

void checkbox_set_status(t_checkbox* check, Uint8 status)
{
	if (check == NULL ||
		(status != CHECK_ON && status != CHECK_OFF))
		return;
	check->status = status;
}

void checkbox_set_available(t_checkbox* check, Uint8 available)
{
	if (check == NULL ||
		(available != CHECK_AVAILABLE && available != CHECK_UNAVAILABLE))
		return;
	check->available = available;
}

void checkbox_set_pos(t_checkbox* check, int x, int y)
{
	if (check == NULL)
		return;
	check->pos.x = x;
	check->pos.y = y;
}