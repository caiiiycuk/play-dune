/* $Id: security.c 2553 2011-11-12 23:16:53Z glx $ */

/** @file src/security.c Security routines. */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "../os/strings.h"

#include "../file.h"
#include "../gfx.h"
#include "../gui/gui.h"
#include "../gui/mentat.h"
#include "../gui/widget.h"
#include "../house.h"
#include "../input/input.h"
#include "../load.h"
#include "../opendune.h"
#include "../sprites.h"
#include "../string.h"
#include "../table/strings.h"
#include "../timer.h"
#include "../tools.h"
#include "../wsa.h"


static void GUI_Security_DrawText(char *text)
{
	uint16 oldScreenID;

	oldScreenID = GFX_Screen_SetActive(4);

	GUI_Mouse_Hide_InRegion(0, 0, SCREEN_WIDTH, 40);
	GUI_Screen_Copy(0, 0, 0, 0, SCREEN_WIDTH / 8, 40, 0, 4);
	GUI_Mouse_Show_InRegion();

	GUI_Screen_Copy(0, 0, 0, 160, SCREEN_WIDTH / 8, 40, 4, 4);

	GUI_Mentat_SplitText(text, 304);

	GUI_DrawText_Wrapper(text, 4, 1, g_curWidgetFGColourBlink, 0, 0x32);

	GUI_Mouse_Hide_InRegion(0, 0, SCREEN_WIDTH, 40);
	GUI_Screen_Copy(0, 0, 0, 0, SCREEN_WIDTH / 8, 40, 4, 0);
	GUI_Mouse_Show_InRegion();

	GFX_Screen_SetActive(oldScreenID);
}

static void GUI_Security_UndrawText()
{
	GUI_Mouse_Hide_Safe();
	GUI_Screen_Copy(0, 160, 0, 0, SCREEN_WIDTH / 8, 40, 4, 0);
	GUI_Mouse_Show_Safe();
}

static void GUI_Security_NormaliseText(char *str)
{
	char *s = str;

	while (*s != '\0') {
		if (isalnum((uint8)*s)) {
			if (islower((uint8)*s)) {
				*s = toupper(*s);
			}
			*str++ = *s;
		}
		s++;
	}

	*str = '\0';
}

/**
 * Ask the security question to the user. Give him 3 times. If he fails,
 *  return false, otherwise true.
 * @return True if and only if the user answered one of the three questions
 *   correct.
 */
void GUI_Security_Show() {
}
