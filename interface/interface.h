#ifndef _interface_h
#define _interface_h    

#include "datastruct.h"
extern double RowPitch;
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
