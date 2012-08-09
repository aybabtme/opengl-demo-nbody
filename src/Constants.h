#ifndef CONSTANTS_H_GUARD
#define CONSTANTS_H_GUARD

// Strings
const static char *APP_NAME = "n-body simulation";
const static char *APP_VERSION = "v0.01 (C) Antoine Grondin, 2012";

// Configuration
const static bool DEBUG = false;
const static bool TEST = true;
const static int BODY_COUNT = 2;

// GUI constants
const static int APP_WIDTH = 800;
const static int APP_HEIGHT= 600;

// GL constant
const static float APP_CAMERA_FOV = 40.0f;
const static float APP_CAMERA_NEAR = 1.0f;
const static float APP_CAMERA_FAR = 10000.f;

#endif
