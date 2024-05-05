#include "graphics.h"
#include "imgui.h"
#include <stdio.h>
#include "interface.h"
#include <windows.h>

#define W 14
#define H 10
#define FontWidth1 0.077886
#define LeftWidth GetFontAscent()/2 + 0.2 - 0.02
#define a 0.35

void BackGround(int number)
{
	switch (number) {
	case 1:
		SetPenColor("����");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 2:
		SetPenColor("������");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 3:
		SetPenColor("Yellow");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 4:
		SetPenColor("���ʱ���");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 5:
		SetPenColor("���ʱ���");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 0:
		SetPenColor("White");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 7:
		SetPenColor("Brown");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 8:
		SetPenColor("Gray");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 9:
		SetPenColor("Cyan");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	}

}
//��ӭ���溯��
void drawMenu()
{
	if(scene==1){
	char* nowfont = GetFont();

	static char* menuListFile[] = { "�ļ���F��",
    // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
    "�½���N��|Ctrl-N" ,
   "�´���(W)|Ctrl-W",
   "����(S)|Ctrl-S",
   "��(O)|Ctrl-O",
   "�˳�(X)|Ctr-X" };
	static char* menuListTool[] = { "�༭��E��",
	  "����(U)|Ctrl-U",
	  "����(T)|Ctrl-T",
	  "����(C)|Ctrl-C",
	  "ճ��(V)|Ctrl-V",
	  "ɾ��(L)|Ctrl-L",
	  "ȫѡ(A)|Ctrl-A", 
	  "����(D)|Ctrl-D" 
	};
	static char* menuListtypeface[] = { "����",
	  "΢���ź�",
	  "����",
	  "����",
	  "����",
	  "Times New Roman",
	  "Microsoft Tai Le",
	  "Consolas"
	};
	static char* menuListbackcolor[] = { "������ɫ",
	"����",
	"������",
	"White",
	"Yellow",
	"���ʱ���",
	"���ʱ���" };
	static char* menuListsize[] = { "�����С",
	"����",
	"С��",
	"һ��",
	"Сһ",
	"����",
	"С��" ,
	"����" };
	static char* menuListmode[] = { "�鿴",
		"�Ķ�ģʽ",
		"�༭ģʽ",
		"���ֲ���",
		"����ֹͣ" 
	};
    static char* menuListabout[]={"����",
     "ʹ��˵��",
	 "���ڱ����" 
	};
    static char*menuListformat[]={"��ʽ",
	"1���о�",
	"1.5���о�",
	"2���о�" 
	};
	static char*menuListicon[]={"","GO"};
	double fH = 0.156;
	double x = 0; 
	double y = winheight;
	double h = 0.235; 
	double w = 0.94; 
	//double wlist = 1.18;
	double wlist=1.3;
	double xindent = winheight / 20;
	static char* selectedLabel = NULL;
	SetPenColor("Light Gray");
	drawRectangle(0, y - h, winwidth, h, 1);
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");

	char filename[256] = { 0 };
	int    selectioninfile;
	selectioninfile = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListFile, sizeof(menuListFile) / sizeof(menuListFile[0]));
	if (selectioninfile > 0) {
		selectedLabel = menuListFile[selectioninfile];
		switch (selectioninfile) {
		case 1:{
			IsSave=1;
				AllDeleteText();
			
			break;
		}
		case 2: {
			AllDeleteText();
		 } break;
		case 3:save(MainSpace->word); break;
		case 4:{
			AllDeleteText();
			openfile(MainSpace->word);
		}   break;
		case 5:exit(-1); break;
		default: exit(-1); break;
		}
	}

	// �༭ �˵�
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int    selectionintool;

	selectionintool = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListTool, sizeof(menuListTool) / sizeof(menuListTool[0]));
	if (selectionintool > 0) //selectedLabel = menuListTool[selection];
	{
		switch (selectionintool) {
		case 1:RevokeText();break;//����
		case 2:TextFlag = 3; break;//����
		case 3:TextFlag = 1; break;//����
		case 4:TextFlag = 2; break;//ճ��
		case 5:TextFlag = 4; break;//ɾ��
		case 6:AllCopyText();break;//ȫѡ
		case 7: AllDeleteText();break;//���� 

		default: break;
		}

	}
	// ���� �˵�
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");

	int    selectioninfont;
	selectioninfont = menuList(GenUIID(0), x + 2 * w, y - h, w, wlist, h, menuListtypeface, sizeof(menuListtypeface) / sizeof(menuListtypeface[0]));
	if (selectioninfont > 0) {
		switch (selectioninfont) {
		case 1:SetFont("΢���ź�"); display(); break;
		case 2:SetFont("����"); display(); ; break;
		case 3:SetFont("����"); display(); break;
		case 4:SetFont("����");  display(); break;
		case 5:SetFont("Times New Roman"); display(); break;
		case 6:SetFont("Microsoft Tai Le"); display(); break;
		case 7:SetFont("Consolas"); DrawLine(1, -10); display(); break;
		default: break;
		}
		nowfont = GetFont();

	}
	//������ɫ
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectioninback;

	selectioninback = menuList(GenUIID(0), x + 3 * w, y - h, w, wlist, h, menuListbackcolor, sizeof(menuListbackcolor) / sizeof(menuListbackcolor[0]));
	if (selectioninback > 0) {
		switch (selectioninback) {
	    case 1:backcolor = 1; display(); break;
		case 2:backcolor=2; display(); break;
		case 3:backcolor=0; display(); break;
		case 4:backcolor=3; display(); break;
		case 5:backcolor = 4; display(); break;
		case 6:backcolor = 5; display(); break;
		}
	}

	//�����С
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectioninsize;
	selectioninsize = menuList(GenUIID(0), x + 4 * w, y - h, w, wlist, h, menuListsize, sizeof(menuListsize) / sizeof(menuListsize[0]));
	if (selectioninsize > 0) {
		switch (selectioninsize) {
		case 1:pointinsize = 56;   break;
		case 2:pointinsize = 48;  break;
		case 3:pointinsize = 34;  break;
		case 4:pointinsize = 32; break;
		case 5:pointinsize = 29;  break;
		case 6:pointinsize = 24; break;
		case 7:pointinsize = 20; break;
		default:break;
		}
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectioninmode;
	selectioninmode = menuList(GenUIID(0), x + 5 * w, y - h, w - 0.1, wlist, h, menuListmode, sizeof(menuListmode) / sizeof(menuListmode[0]));
	if (selectioninmode > 0) {
		switch (selectioninmode) {
		case 1:	
		IsEdit = 0; 
		IsZoom = 1;
		PatternFlag=0; 
		ControlFlag=0;
		break;
		case 2:
		IsEdit = 1; 
		IsZoom = 0; 
		PatternFlag=1;
		ControlFlag=0;
		break;
		case 3:
			music=1;
			displaymusic();
	   break;
    	case 4:
		music=0;
	 displaymusic() ;
		break; 
		}
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectionabout;
	selectionabout= menuList(GenUIID(0), x + 9.5* w, y - h, w - 0.1, wlist, h, menuListabout, sizeof(menuListabout) / sizeof(menuListabout[0]));
		if (selectionabout > 0) {
		switch (selectionabout) {
		case 1:	
		scene=2;
		display(); 
		break;
		case 2:
		scene=3;
	    display();
	    break;
		}

	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("΢���ź�");
	int selectionformat;
	selectionformat= menuList(GenUIID(0), x + 8.5* w, y - h, w - 0.1, wlist, h, menuListformat, sizeof(menuListformat) / sizeof(menuListformat[0]));
		if (selectionformat > 0) {
			
		switch (selectionformat) {
		case 1:	
		ControlFlag=0;
		RowPitch=0.2;
		display(); 
		break;
		case 2:
		ControlFlag=0;
		RowPitch=0.3;
	    display();
	    break;
	    case 3:
	    ControlFlag=0;
	    RowPitch=0.4;
	    display();
	    break;
		}

	}
	//ͼ��˵��� 
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPenSize(2);
	SetPointSize(8);
	SetFont("΢���ź�");
	int buttonreturn=0;
	if(buttonreturn=menuList(GenUIID(0), x + 6.5 * w, y - h, h, h,h,menuListicon,2)){
		RevokeText();
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("΢���ź�");
	int buttoncopy=0;
	if(buttoncopy=menuList(GenUIID(0), x + 6.5 * w+h, y - h, h, h,h,menuListicon,2)){
		TextFlag = 1;
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("΢���ź�");
	int buttonpaste=0;
	if(buttonpaste=menuList(GenUIID(0), x + 6.5 * w+2*h, y - h, h, h,h,menuListicon,2)){
		TextFlag = 2;
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("΢���ź�");
	int buttonclear=0;
	if(buttonclear=menuList(GenUIID(0), x + 6.5 * w+3*h, y - h, h, h,h,menuListicon,2)){
		AllDeleteText();
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("΢���ź�");
	int buttondelete=0;
	if(buttondelete=menuList(GenUIID(0), x + 6.5 * w+4*h, y - h, h, h,h,menuListicon,2)){
		TextFlag = 4;
		display();
	}
	DrawReturn();
	DrawCopy();
	DrawPaste();
	DrawClear();
	DrawDelete();
	
	SetPenColor("Light Gray");
	drawRectangle(0,0,W,0.3,1);
	SetPenColor("Black"); 
	static char results[200] = "";
	if (IsEdit == 0) { sprintf(results, "Now mode is: %s", "�Ķ�ģʽ"); }
	else { sprintf(results, "Now mode is: %s", "�༭ģʽ"); }
	MovePen(4, 0.1);
	DrawTextString(results);
	char line[80] = "";
	sprintf(line, "��%d��", Line + 1);
	MovePen(0.1, 0.1);
	DrawTextString(line);


 	//״̬��
	SetPenColor("Light Gray");
	MovePen(0, H - 0.3);
	DrawLine(W, 0);
	drawRectangle(0, 0, W, 0.3, 0.25);
	setMenuColors("Light Gray", "Black", "Black", "Black", 0);
	SetPenColor("Gray");
	MovePen(0, 0.3);
	DrawLine(W, 0);
	SetPointSize(pointinsize + pointinzoom);
	SetFont(nowfont);
	if(IsEdit==0) RowPitch=(pointinsize+pointinzoom)/60.0;
	
   }else if(scene==2){
   	DrawExplain();
   }else if(scene==0){
   	DrawStartMenu();
   }else if(scene==3){
   	DrawHelp();
   }
}

void DrawStartMenu(){
    SetPenColor("white");
    drawRectangle(0, 0, W, H, 1);
    SetPenColor("Ʒ��");
    SetPointSize(60);
    SetPenSize(10);
    MovePen(1.3,4.2);
    DrawLine(0,0.9);
    DrawLine(0.5,0);
    DrawLine(0,-0.15);
    DrawLine(0.75,0);
    DrawLine(0,-0.2);
    MovePen(1.3,4.2);
    DrawLine(0.25,0.55);
    DrawLine(1.25,0);
    DrawLine(-0.25,-0.55);
    DrawLine(-1.25,0);
    SetFont("΢���ź�");
    SetPenColor("Black");
    MovePen(3,4.3); 
    SetPointSize(120);
    SetPenSize(80);
    DrawTextString("�ı��༭��");
    MovePen(3.6,2);
    SetPointSize(16);
    DrawTextString("Welcome!  ����������������������..."); 
    SetPointSize(17);
    SetPenSize(2);
    setButtonColors("Light Gray","Black","Blue","Black",1); 
    
}
//˵�����溯��
void DrawExplain()
{
	DisplayClear();
    SetPenColor("Black");
    SetFont("΢���ź�");
    SetPenSize(3);
    SetPointSize(14);
    MovePen(2,H-4); 
    DrawTextString("����ɹ��󣬽��뿪ʼ���棬�������ʼ����ť���������棬������رա���ť�˳���");
    MovePen(2,H-4-a);
    DrawTextString("��껮����Ӧ̧ͷ������Ӧ������,�����Ӧ��Ŀʵ����Ӧ���ܣ�");
    MovePen(2,H-4-2*a);
    DrawTextString("�ļ����½����´��ڡ����桢�򿪡��˳���");
     MovePen(2,H-4-3*a);
    DrawTextString("�༭��ȫѡ�����С����ơ�ճ����ɾ����");
     MovePen(2,H-4-4*a);
    DrawTextString("���壺΢���źڡ����塢���Ρ����塢Times New Roman��Microsoft Tai Le��Consolas");
     MovePen(2,H-4-5*a);
    DrawTextString("������ɫ��Ʒ���������ۡ�White��Yellow��Orange�����ʱ���");
    MovePen(2,H-4-6*a);
    DrawTextString("�鿴���Ķ�ģʽ���༭ģʽ���Ķ�ģʽ�¿��Ը��������С����ʽ���༭ģʽ�¿��Խ��б༭");
    MovePen(2,H-4-7*a);
    DrawTextString("����Ҽ��������Ҽ��˵������������������ơ�ճ����ɾ������");
    MovePen(2,H-4-8*a);
    DrawTextString("���̧ͷ�Ҽ��˵��ɽ��˵��۵�����");
    MovePen(2,H-4-9*a);
    DrawTextString("�Ҳ���֣��϶����ֻ����ı�");
    MovePen(2,H-4-10*a);
    DrawTextString("�ײ��˵���¼�Ķ�/�༭ģʽ������");
    SetPenColor("Blue"); 
    MovePen(3,H-4-12*a);
    DrawTextString("������������򷵻�...");
    SetPenColor("Ʒ��");
    SetPointSize(15);
    SetPenSize(10);
    MovePen(0.3,H-4.5);
    DrawLine(0,0.9);
    DrawLine(0.5,0);
    DrawLine(0,-0.15);
    DrawLine(0.75,0);
    DrawLine(0,-0.2);
    MovePen(0.3,H-4.5);
    DrawLine(0.25,0.55);
    DrawLine(1.25,0);
    DrawLine(-0.25,-0.55);
    DrawLine(-1.25,0);
    SetPenColor("Light Gray");
    MovePen (1.5,H-5);
    DrawLine(0,-3.5);
    DrawLine(7,0);
    DrawLine(0,5);
    DrawLine(-6,0);
    SetPointSize(12);
    SetPenSize(4);
    setButtonColors("Light Gray","Black","Blue","Black",1); 
}
void DrawHelp()
{
	DisplayClear();
    SetPenColor("Black");
    SetFont("΢���ź�");
    SetPenSize(3);
    SetPointSize(14);
    MovePen(2,H-4); 
    DrawTextString("����ʱ�䣺");
    MovePen(2,H-4-a);
    DrawTextString("2022.4.31��2022.5.31");
    MovePen(2,H-4-2*a);
    DrawTextString("����Ŀ�ģ�");
     MovePen(2,H-4-3*a);
    DrawTextString("�ı��༭���Ǹ��ֵ����豸���ֻ������Եȱر��Ļ����������");
     MovePen(2,H-4-4*a);
    DrawTextString("������Ҫ��ʱ��¼������Ϣ���ڹ�����ѧϰ��������Ҳ��Ҫʹ���ı��༭���Ĺ���");
     MovePen(2,H-4-5*a);
    DrawTextString("����������windows�Դ����±�����Ļ����Ͽ����˼����Զ����ı��༭��");
    MovePen(2,H-4-6*a);
    DrawTextString("�ṩ���û������Ĵ��ı��༭���ܣ�������ʵ���ļ��Ĵ洢���޸ġ�");
    MovePen(2,H-4-7*a);
    DrawTextString("����û������м�¼���֡��༭���ֵ�����");
  /*  MovePen(2,H-4-8*a);
    DrawTextString("���̧ͷ�Ҽ��˵��ɽ��˵��۵�����");
    MovePen(2,H-4-9*a);
    DrawTextString("�Ҳ���֣��϶����ֻ����ı�");
    MovePen(2,H-4-10*a);
    DrawTextString("�ײ��˵���¼�Ķ�/�༭ģʽ������");*/
    SetPenColor("Blue"); 
    MovePen(3,H-4-12*a);
    DrawTextString("������������򷵻�...");
    SetPenColor("Ʒ��");
    SetPointSize(15);
    SetPenSize(10);
    MovePen(0.3,H-4.5);
    DrawLine(0,0.9);
    DrawLine(0.5,0);
    DrawLine(0,-0.15);
    DrawLine(0.75,0);
    DrawLine(0,-0.2);
    MovePen(0.3,H-4.5);
    DrawLine(0.25,0.55);
    DrawLine(1.25,0);
    DrawLine(-0.25,-0.55);
    DrawLine(-1.25,0);
    SetPenColor("Light Gray");
    MovePen (1.5,H-5);
    DrawLine(0,-3.5);
    DrawLine(7,0);
    DrawLine(0,5);
    DrawLine(-6,0);
    SetPointSize(12);
    SetPenSize(4);
    //setButtonColors("Light Gray","Black","Blue","Black",1); 
 } 
 void DrawReturn()
{
 //double x=6.5*0.94+0.01,y=H-0.9;
double x=6.3,y=6.82;
 double b=0.45;
 MovePen(x,y);
 SetPenSize(4);
 SetPenColor("Yellow");

 DrawArc(0.2*b,0,90);
 DrawLine(-0.1*b,0);
 DrawLine(0.1*b,0.1*b);

 } 
void DrawCopy()
{ 
 double x=6.38,y=6.80;
 double b=0.2;
 MovePen(x,y);
 SetPenSize(3);
    SetPenColor("Black");
 drawRectangle(x,y,0.55*b,0.7*b,0); 
 MovePen(x+0.2*b,y+0.7*b);
 DrawLine(0,0.2*b);
 DrawLine(0.55*b,0);
 DrawLine(0,-0.7*b);
 DrawLine(-0.2*b,0);
}
void DrawPaste()
{
	double x=6.64,y=6.81;
 double b=0.23;
 MovePen(x,y);
 SetPenSize(3);
    SetPenColor("Black");
 drawRectangle(x,y,0.55*b,0.7*b,0);
 SetPenColor("Ʒ��");
 MovePen(x+0.7*b,y+0.35*b);
 DrawLine(-0.4*b,0);
 DrawLine(0.09*b,0.09*b);
 
 
}
void DrawClear(){
 double x=6.87,y=6.81;
 double b=0.23;
 MovePen(x,y);
 SetPenSize(3);
    SetPenColor("����");
 drawRectangle(x,y,0.55*b,0.7*b,0);
 	
}
void DrawDelete(){
	double x=7.1,y=6.81;
	double b=0.13;
	MovePen(x,y);
	SetPenSize(5);
	SetPenColor("Red");
	//drawRectangle(x,y,0.55*b,0.7*b,0);
	DrawLine(b,b);
	DrawLine(-b/2,-b/2);
	DrawLine(-b/2,b/2);
	DrawLine(b,-b);
}

void displaymusic()
{
	
	if(music==1){
	
	 PlaySound(TEXT("1.wav"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);
  
}

if(music==0){
	
	 PlaySound(TEXT(NULL),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);
   
}

}


