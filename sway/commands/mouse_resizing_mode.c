#include "sway/commands.h"

struct cmd_results *cmd_mouse_resizing_mode(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "mouse_resizing_mode", EXPECTED_EQUAL_TO, 1))) {
		return error;
	} else if (strcmp(argv[0], "four_direction") == 0) {
		config->mouse_resizing_mode = MOUSE_RESIZING_MODE_4_DIR;
	} else if (strcmp(argv[0], "eight_direction") == 0) {
		config->mouse_resizing_mode = MOUSE_RESIZING_MODE_8_DIR;
	} else {
		return cmd_results_new(CMD_FAILURE,
			"Expected 'mouse_resizing_mode four_direction|eight_direction'");
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}
