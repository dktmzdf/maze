#pragma once
#include"main.h"


constexpr auto UP = 0;
constexpr auto DOWN = 1;
constexpr auto LEFT = 2;
constexpr auto RIGHT = 3;
constexpr auto SUBMIT = 4;


void gLoop(int);
void move(int *, int *, int, int, int *, int *);
int menuDraw();
int keyControl();
void titleDraw();
int mapListDraw();
void infoDraw();
void drawMap(int *, int *);
void drawUI(int *, int *, int *);
void inputMap(char *Dest, char [][112]);//MapX==112
void PMG();

