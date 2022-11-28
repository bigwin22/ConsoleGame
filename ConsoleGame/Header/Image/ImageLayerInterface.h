#pragma once
#include <Windows.h>

#ifndef IMAGE_LAYER_INTERFACE_H
#define IMAGE_LAYER_INTERFACE_H

typedef struct {
	char* fileName;
	int x, y;
	double scale;
	int isHide;
	int type; //-1: background, 0: User, 1: Mob, 2: Missile, 3: obstacle
}Image;

typedef struct _ImageLayer {
	//멤버 변수
	Image* images;
	int imageCount;
	UINT transparentColor;

	HWND _windowHandle;
	HDC _consoleDC;

	//함수
	void (*initialize)(struct _ImageLayer*);
	void (*renderAll)(struct _ImageLayer*);
	void (*fadeIn)(struct _ImageLayer*, void(*applyToBackDC)(HDC));
	void (*fadeOut)(struct _ImageLayer*, void(*applyToBackDC)(HDC));
	void (*applyToDC)(HDC);
}ImageLayer;

#endif