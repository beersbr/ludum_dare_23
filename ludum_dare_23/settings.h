#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


const int MAX_X_SIZE = 100;
const int MAX_Y_SIZE = 100;
const int X_TILE_SIZE = 40;
const int Y_TILE_SIZE = 40;

enum GAME_STATE{STOPPED = 0, RUNNING, PAUSED, LOADING};