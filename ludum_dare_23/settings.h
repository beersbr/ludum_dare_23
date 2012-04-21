#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_X_SIZE = 100;
const int MAX_Y_SIZE = 100;
const int X_TILE_SIZE = 40;
const int Y_TILE_SIZE = 40;

const int REZ_X = 1200;
const int REZ_Y = 800;

const int FRAME_LIMIT = 60;

const std::string WINDOW_TITLE = "Ludum Dare <TO BE NAMED>";

enum GAME_STATE{STOPPED = 0, RUNNING, PAUSED, LOADING};