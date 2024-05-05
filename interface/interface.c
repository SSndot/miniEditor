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
		SetPenColor("灰蓝");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 2:
		SetPenColor("马卡龙粉");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 3:
		SetPenColor("Yellow");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 4:
		SetPenColor("杏仁饼橙");
		drawRectangle(0, 0, W, H - 0.3, 1);
		break;
	case 5:
		SetPenColor("杏仁饼绿");
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
//欢迎界面函数
void drawMenu()
{
	if(scene==1){
	char* nowfont = GetFont();

	static char* menuListFile[] = { "文件（F）",
    // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
    "新建（N）|Ctrl-N" ,
   "新窗口(W)|Ctrl-W",
   "保存(S)|Ctrl-S",
   "打开(O)|Ctrl-O",
   "退出(X)|Ctr-X" };
	static char* menuListTool[] = { "编辑（E）",
	  "撤销(U)|Ctrl-U",
	  "剪切(T)|Ctrl-T",
	  "复制(C)|Ctrl-C",
	  "粘贴(V)|Ctrl-V",
	  "删除(L)|Ctrl-L",
	  "全选(A)|Ctrl-A", 
	  "清屏(D)|Ctrl-D" 
	};
	static char* menuListtypeface[] = { "字体",
	  "微软雅黑",
	  "宋体",
	  "仿宋",
	  "黑体",
	  "Times New Roman",
	  "Microsoft Tai Le",
	  "Consolas"
	};
	static char* menuListbackcolor[] = { "背景颜色",
	"灰蓝",
	"马卡龙粉",
	"White",
	"Yellow",
	"杏仁饼橙",
	"杏仁饼绿" };
	static char* menuListsize[] = { "字体大小",
	"初号",
	"小初",
	"一号",
	"小一",
	"二号",
	"小二" ,
	"三号" };
	static char* menuListmode[] = { "查看",
		"阅读模式",
		"编辑模式",
		"音乐播放",
		"音乐停止" 
	};
    static char* menuListabout[]={"帮助",
     "使用说明",
	 "关于本软件" 
	};
    static char*menuListformat[]={"格式",
	"1倍行距",
	"1.5倍行距",
	"2倍行距" 
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
	SetFont("微软雅黑");

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

	// 编辑 菜单
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("微软雅黑");
	int    selectionintool;

	selectionintool = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListTool, sizeof(menuListTool) / sizeof(menuListTool[0]));
	if (selectionintool > 0) //selectedLabel = menuListTool[selection];
	{
		switch (selectionintool) {
		case 1:RevokeText();break;//撤销
		case 2:TextFlag = 3; break;//剪切
		case 3:TextFlag = 1; break;//复制
		case 4:TextFlag = 2; break;//粘贴
		case 5:TextFlag = 4; break;//删除
		case 6:AllCopyText();break;//全选
		case 7: AllDeleteText();break;//清屏 

		default: break;
		}

	}
	// 字体 菜单
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("微软雅黑");

	int    selectioninfont;
	selectioninfont = menuList(GenUIID(0), x + 2 * w, y - h, w, wlist, h, menuListtypeface, sizeof(menuListtypeface) / sizeof(menuListtypeface[0]));
	if (selectioninfont > 0) {
		switch (selectioninfont) {
		case 1:SetFont("微软雅黑"); display(); break;
		case 2:SetFont("宋体"); display(); ; break;
		case 3:SetFont("仿宋"); display(); break;
		case 4:SetFont("黑体");  display(); break;
		case 5:SetFont("Times New Roman"); display(); break;
		case 6:SetFont("Microsoft Tai Le"); display(); break;
		case 7:SetFont("Consolas"); DrawLine(1, -10); display(); break;
		default: break;
		}
		nowfont = GetFont();

	}
	//背景颜色
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("微软雅黑");
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

	//字体大小
	setMenuColors("Light Gray", "Black", "Blue", "Black", 1);
	SetPointSize(12);
	SetFont("微软雅黑");
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
	SetFont("微软雅黑");
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
	SetFont("微软雅黑");
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
	SetFont("微软雅黑");
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
	//图标菜单栏 
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPenSize(2);
	SetPointSize(8);
	SetFont("微软雅黑");
	int buttonreturn=0;
	if(buttonreturn=menuList(GenUIID(0), x + 6.5 * w, y - h, h, h,h,menuListicon,2)){
		RevokeText();
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("微软雅黑");
	int buttoncopy=0;
	if(buttoncopy=menuList(GenUIID(0), x + 6.5 * w+h, y - h, h, h,h,menuListicon,2)){
		TextFlag = 1;
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("微软雅黑");
	int buttonpaste=0;
	if(buttonpaste=menuList(GenUIID(0), x + 6.5 * w+2*h, y - h, h, h,h,menuListicon,2)){
		TextFlag = 2;
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("微软雅黑");
	int buttonclear=0;
	if(buttonclear=menuList(GenUIID(0), x + 6.5 * w+3*h, y - h, h, h,h,menuListicon,2)){
		AllDeleteText();
		display();
	}
	setMenuColors("Light Gray", "Black", "Blue", "Black", 0);
	SetPointSize(12);
	SetFont("微软雅黑");
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
	if (IsEdit == 0) { sprintf(results, "Now mode is: %s", "阅读模式"); }
	else { sprintf(results, "Now mode is: %s", "编辑模式"); }
	MovePen(4, 0.1);
	DrawTextString(results);
	char line[80] = "";
	sprintf(line, "共%d行", Line + 1);
	MovePen(0.1, 0.1);
	DrawTextString(line);


 	//状态栏
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
    SetPenColor("品蓝");
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
    SetFont("微软雅黑");
    SetPenColor("Black");
    MovePen(3,4.3); 
    SetPointSize(120);
    SetPenSize(80);
    DrawTextString("文本编辑器");
    MovePen(3.6,2);
    SetPointSize(16);
    DrawTextString("Welcome!  鼠标点击任意区域进入主界面..."); 
    SetPointSize(17);
    SetPenSize(2);
    setButtonColors("Light Gray","Black","Blue","Black",1); 
    
}
//说明界面函数
void DrawExplain()
{
	DisplayClear();
    SetPenColor("Black");
    SetFont("微软雅黑");
    SetPenSize(3);
    SetPointSize(14);
    MovePen(2,H-4); 
    DrawTextString("编译成功后，进入开始界面，点击“开始”按钮进入主界面，点击“关闭”按钮退出。");
    MovePen(2,H-4-a);
    DrawTextString("鼠标划过相应抬头弹出相应工具栏,点击相应栏目实现相应功能：");
    MovePen(2,H-4-2*a);
    DrawTextString("文件：新建、新窗口、保存、打开、退出；");
     MovePen(2,H-4-3*a);
    DrawTextString("编辑：全选、剪切、复制、粘贴、删除；");
     MovePen(2,H-4-4*a);
    DrawTextString("字体：微软雅黑、宋体、仿宋、黑体、Times New Roman、Microsoft Tai Le、Consolas");
     MovePen(2,H-4-5*a);
    DrawTextString("背景颜色：品蓝、马卡龙粉、White、Yellow、Orange、杏仁饼绿");
    MovePen(2,H-4-6*a);
    DrawTextString("查看：阅读模式、编辑模式，阅读模式下可以更换字体大小、样式，编辑模式下可以进行编辑");
    MovePen(2,H-4-7*a);
    DrawTextString("点击右键，出现右键菜单：包括：撤销、复制、粘贴、删除功能");
    MovePen(2,H-4-8*a);
    DrawTextString("点击抬头右键菜单可将菜单折叠收起");
    MovePen(2,H-4-9*a);
    DrawTextString("右侧滚轮，拖动滚轮滑动文本");
    MovePen(2,H-4-10*a);
    DrawTextString("底部菜单记录阅读/编辑模式、行数");
    SetPenColor("Blue"); 
    MovePen(3,H-4-12*a);
    DrawTextString("鼠标点击任意区域返回...");
    SetPenColor("品蓝");
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
    SetFont("微软雅黑");
    SetPenSize(3);
    SetPointSize(14);
    MovePen(2,H-4); 
    DrawTextString("开发时间：");
    MovePen(2,H-4-a);
    DrawTextString("2022.4.31—2022.5.31");
    MovePen(2,H-4-2*a);
    DrawTextString("开发目的：");
     MovePen(2,H-4-3*a);
    DrawTextString("文本编辑器是各种电子设备如手机、电脑等必备的基础功能软件");
     MovePen(2,H-4-4*a);
    DrawTextString("人们需要随时记录大量信息，在工作、学习、生活中也需要使用文本编辑器的功能");
     MovePen(2,H-4-5*a);
    DrawTextString("所以我们在windows自带记事本软件的基础上开发了简易自定义文本编辑器");
    MovePen(2,H-4-6*a);
    DrawTextString("提供给用户基本的纯文本编辑功能，并最终实现文件的存储和修改。");
    MovePen(2,H-4-7*a);
    DrawTextString("解决用户生活中记录文字、编辑文字的需求。");
  /*  MovePen(2,H-4-8*a);
    DrawTextString("点击抬头右键菜单可将菜单折叠收起");
    MovePen(2,H-4-9*a);
    DrawTextString("右侧滚轮，拖动滚轮滑动文本");
    MovePen(2,H-4-10*a);
    DrawTextString("底部菜单记录阅读/编辑模式、行数");*/
    SetPenColor("Blue"); 
    MovePen(3,H-4-12*a);
    DrawTextString("鼠标点击任意区域返回...");
    SetPenColor("品蓝");
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
 SetPenColor("品蓝");
 MovePen(x+0.7*b,y+0.35*b);
 DrawLine(-0.4*b,0);
 DrawLine(0.09*b,0.09*b);
 
 
}
void DrawClear(){
 double x=6.87,y=6.81;
 double b=0.23;
 MovePen(x,y);
 SetPenSize(3);
    SetPenColor("灰蓝");
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


