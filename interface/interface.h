#ifndef _interface_h
#define _interface_h    

#include "datastruct.h"
extern double RowPitch;
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
extern int Line;
extern int music;
extern space* MainSpace;
void BackGround(int number);
void drawMenu();
void DrawStartMenu();
void DrawExplain();
void DrawHelp();
void DrawReturn();
void DrawCopy();
void DrawPaste();
void DrawClear();
void DrawDelete();
void displaymusic();
#endif
