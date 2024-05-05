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
extern int backcolor;//背景颜色参数
extern int scene;//幕参数，0为欢迎界面、1为主界面、2为说明界面 
extern int IsEdit;//1为编辑模式
extern int IsZoom;//1时弹出缩放菜单
extern int pointinzoom;//缩放改变的大小
extern int pointinsize;//字体对应字号的大小
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
