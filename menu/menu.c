#include "graphics.h"
#include "imgui.h"
#include <stdio.h>
#include "menu.h"
#include <string.h>
#include <stdlib.h>
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
void drawMouseMenu()
{
	char* nowfont = GetFont();
	static char* selectedLabel = NULL;
	static char* mousemenu[] = { "右键菜单",
		"撤销",
		"复制",
		"粘贴",
		"删除"
	};
	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH * 1.5; // 控件高度
	double w = TextStringWidth(mousemenu[1]) * 3; // 控件宽度
	double wlist = TextStringWidth(mousemenu[3]) * 1;
	double xindent = winheight / 20; // 缩进
	int    selection;

	// 文件 菜单
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("微软雅黑");

	selection = menuList(GenUIID(0), ScaleXInches(xmousemenu), ScaleYInches(ymousemenu), w, wlist * 3, h, mousemenu, sizeof(mousemenu) / sizeof(mousemenu[0]));
		if (selection > 0) //selectedLabel = menuListTool[selection];
	{
		switch (selection) {
		case 1:RevokeText();break;//撤销
		
		case 2:TextFlag = 1; break;//复制
		case 3:TextFlag = 2; break;//粘贴
		case 4:TextFlag = 4; break;//删除

		default: break;
		}

	}
	
	
	
	SetFont(nowfont);
}
void drawZoomMenu() {

	char* nowfont = GetFont();
	double fH = 0.156;
	double x = 0; //fH/8;
	double y = winheight;
	double h = 0.235; // 控件高度
	double w = 0.94; // 控件宽度
	double wlist = 1.18;
	double xindent = winheight / 20; // 缩进

	static char* menuListzoom[] = { "缩放",
		"放大",
		"缩小"
	};
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	printf("before:%d\n", pointinzoom);
	SetPointSize(12);
	SetFont("微软雅黑");
	int selectioninzoom;
	selectioninzoom = menuList(GenUIID(0), x + 6 * w, y - h, w, wlist, h, menuListzoom, sizeof(menuListzoom) / sizeof(menuListzoom[0]));
	if (selectioninzoom > 0) {
		switch (selectioninzoom) {
		case 1:	pointinzoom += 5; break;//放大
		case 2:	pointinzoom -= 4; break;//缩小
			IsZoom = 0;
		}

	}
	SetPointSize(pointinzoom + pointinsize);
	SetFont(nowfont);
}


void drawNewFileMenu() {
	char* nowfont = GetFont();
	double fH = 0.156;
	double x = 0; //fH/8;
	double y = winheight;
	double h = 0.235; // 控件高度
	double w = 0.94; // 控件宽度
	double wlist = 1.18;
	double xindent = winheight / 20; // 缩进
	SetPointSize(15);
	SetFont("微软雅黑");
	//char filename[256] = { 0 };
	if (button(GenUIID(0), x + w, y - 2 * h, w, h, "保存")) {
		save(MainSpace->word);
		IsSave = 0;

	}
	if (button(GenUIID(0), x + w, y - 3 * h, w, h, "不保存")) {
		IsSave = 0;
	}
	
	SetFont(nowfont);
}
