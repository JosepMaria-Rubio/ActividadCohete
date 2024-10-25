#pragma once

enum MoveType{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum CoordsType {
	X,
	Y
};

enum ActionType {
	ADD,
	DELETE,
	TRANSFER,
	CHARGE,
	OBJECTIVE,
	LAUNCH,
	DRAW,
	MOVE,
	EXIT
};

const int MaxCapsulas = 10;
const int MaxCarga = 10000;
const int MaxMapa = 10;
const int MaxCoords = 2;
const int MaxCohetes = 2;