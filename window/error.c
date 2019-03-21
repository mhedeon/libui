#include "libmgl.h"

int	error_log(char *message)
{
	SDL_Log("\x1b[31m%s %s\x1b[0m\n", message, SDL_GetError());
	SDL_ClearError();
	return (0);
}
