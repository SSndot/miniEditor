#ifndef _menu_h
#define _menu_h    
#define W 14
#define H 10
#define FontWidth1 0.077886
#define LeftWidth GetFontAscent()/2 + 0.2 - 0.02
#define a 0.35
#include "datastruct.h"
extern double RowPitch;
extern int xmousemenu, ymousemenu;
extern int backcolor;//������ɫ����
extern int scene;//Ļ������0Ϊ��ӭ���桢1Ϊ�����桢2Ϊ˵������ 
extern int IsEdit;//1Ϊ�༭ģʽ
extern int IsZoom;//1ʱ�������Ų˵�
extern int pointinzoom;//���Ÿı�Ĵ�С
extern int pointinsize;//�����Ӧ�ֺŵĴ�С
extern int countchar, countchinese;
extern double winwidth, winheight; 
extern int IsSave;
extern int TimerFlag, TextFlag, ControlFlag, MidFlag, PatternFlag;
extern int mousemenuflag;
extern int Line;
extern space* MainSpace;
void drawMouseMenu();
void drawZoomMenu();
void drawNewFileMenu();
#endif
