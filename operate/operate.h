#ifndef _operate_h
#define _operate_h
#define FontWidth1 0.077886
#define LeftWidth GetFontAscent()/2 + 0.2 - 0.02
#define LINEMAX 500
#define WIDTHMAX 200
extern char textbuf[LINEMAX][WIDTHMAX];
extern double textPosY;
extern double RowPitch;
extern double xCaret, yCaret, xCaret0, yCaret0, xCaret1, yCaret1;
extern int xmid, ymid;
extern int MidMainSpace, MidDataSpace;
extern int TimerFlag, TextFlag, ControlFlag, MidFlag, PatternFlag;
extern space* MainSpace, * DataSpace;
extern char* CopySpace, * SideSpace;
int textbuf_length(int y);
int textbuf_sum(int length);
int SumX(double x, int y, int num);
int LocationX(int x, int sum);
void CopyText();
void PasteText();
void CutText();
void AllCopyText();
void AllDeleteText();
void RevokeText();
#endif
