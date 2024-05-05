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
	static char* mousemenu[] = { "�Ҽ��˵�",
		"����",
		"����",
		"ճ��",
		"ɾ��"
	};
	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH * 1.5; // �ؼ��߶�
	double w = TextStringWidth(mousemenu[1]) * 3; // �ؼ����
	double wlist = TextStringWidth(mousemenu[3]) * 1;
	double xindent = winheight / 20; // ����
	int    selection;

	// �ļ� �˵�
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");

	selection = menuList(GenUIID(0), ScaleXInches(xmousemenu), ScaleYInches(ymousemenu), w, wlist * 3, h, mousemenu, sizeof(mousemenu) / sizeof(mousemenu[0]));
		if (selection > 0) //selectedLabel = menuListTool[selection];
	{
		switch (selection) {
		case 1:RevokeText();break;//����
		
		case 2:TextFlag = 1; break;//����
		case 3:TextFlag = 2; break;//ճ��
		case 4:TextFlag = 4; break;//ɾ��

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
	double h = 0.235; // �ؼ��߶�
	double w = 0.94; // �ؼ����
	double wlist = 1.18;
	double xindent = winheight / 20; // ����

	static char* menuListzoom[] = { "����",
		"�Ŵ�",
		"��С"
	};
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	printf("before:%d\n", pointinzoom);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectioninzoom;
	selectioninzoom = menuList(GenUIID(0), x + 6 * w, y - h, w, wlist, h, menuListzoom, sizeof(menuListzoom) / sizeof(menuListzoom[0]));
	if (selectioninzoom > 0) {
		switch (selectioninzoom) {
		case 1:	pointinzoom += 5; break;//�Ŵ�
		case 2:	pointinzoom -= 4; break;//��С
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
	double h = 0.235; // �ؼ��߶�
	double w = 0.94; // �ؼ����
	double wlist = 1.18;
	double xindent = winheight / 20; // ����
	SetPointSize(15);
	SetFont("΢���ź�");
	//char filename[256] = { 0 };
	if (button(GenUIID(0), x + w, y - 2 * h, w, h, "����")) {
		save(MainSpace->word);
		IsSave = 0;

	}
	if (button(GenUIID(0), x + w, y - 3 * h, w, h, "������")) {
		IsSave = 0;
	}
	
	SetFont(nowfont);
}
