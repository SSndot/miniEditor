#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "datastruct.h"
#include "operate.h"
#include "extgraph.h"
int textbuf_length(int y)
{
	int i, length = 0;
	for (i = 0; i < y; i++)
		length += strlen(textbuf[i]);
	return length;
}

int textbuf_sum(int length)
{
	int i = 0, Length = 0;
	char* p = GB_array(DataSpace);
	while (Length != length)
	{
		if (p[i] == '\0')
			break;
		Length += p[i] - '0';
		i++;
	}
	if (p[i] == '0')
		i++;
	return i;
}

int SumX(double x, int y, int num)
{
	char* p = GB_array(DataSpace);
	double length = x;
	double Length = LeftWidth;
	int i = num;
	while (Length <= length)
	{
		Length += (p[i] - '0') * FontWidth1;
		i++;
		if (p[i] == '\0' || p[i] == '0')
			break;
	}
	return i;

}

int LocationX(int x, int sum)
{
	char* p = GB_array(DataSpace);
	int i = sum;
	int Length = 0;
	for (i = sum; i < x; i++)
		Length += p[i] - '0';
	return  Length;
}

void CopyText()
{
	int ConvertY0 = (int)((textPosY + RowPitch - yCaret0) / RowPitch);
	int WordLength0 = textbuf_length(ConvertY0);
	int WordSum0 = textbuf_sum(WordLength0);
	int ConvertX0 = SumX(xCaret0, ConvertY0, WordSum0);
	int NumLineX0 = ConvertX0 - WordSum0;
	int LineX0 = LocationX(ConvertX0, WordSum0);
	printf("%f\n", yCaret0);
	int ConvertY1 = (int)((textPosY + RowPitch - yCaret1) / RowPitch);
	int WordLength1 = textbuf_length(ConvertY1);
	int WordSum1 = textbuf_sum(WordLength1);
	int ConvertX1 = SumX(xCaret1, ConvertY1, WordSum1);
	int NumLineX1 = ConvertX1 - WordSum1;
	int LineX1 = LocationX(ConvertX1, WordSum1);
	int CopyLocation1 = LineX1 + WordLength1;
	int CopyLocation0 = LineX0 + WordLength0;

	if (CopyLocation1 > CopyLocation0)
	{
		CopySpace = (char*)malloc(sizeof(char) * (CopyLocation1 - CopyLocation0) + 1);
		SideSpace = (char*)malloc(sizeof(char) * (ConvertX1 - ConvertX0) + 1);
		char* midbuf = (char*)malloc(sizeof(char) * (CopyLocation1 - CopyLocation0) + 1);
		memcpy(midbuf, GB_array(MainSpace) + CopyLocation0, CopyLocation1 - CopyLocation0);
		memcpy(CopySpace, midbuf, CopyLocation1 - CopyLocation0);
		memcpy(midbuf, GB_array(DataSpace) + ConvertX0, ConvertX1 - ConvertX0);
		memcpy(SideSpace, midbuf, ConvertX1 - ConvertX0);
		CopySpace[CopyLocation1 - CopyLocation0] = '\0';
		SideSpace[ConvertX1 - ConvertX0] = '\0';
	}
	else
	{
		CopySpace = (char*)malloc(sizeof(char) * (CopyLocation0 - CopyLocation1) + 1);
		SideSpace = (char*)malloc(sizeof(char) * (ConvertX0 - ConvertX1) + 1);
		char* midbuf = (char*)malloc(sizeof(char) * (CopyLocation0 - CopyLocation1) + 1);
		memcpy(midbuf, GB_array(MainSpace) + CopyLocation1, CopyLocation0 - CopyLocation1);
		memcpy(CopySpace, midbuf, CopyLocation0 - CopyLocation1);
		memcpy(midbuf, GB_array(DataSpace) + ConvertX1, ConvertX0 - ConvertX1);
		memcpy(SideSpace, midbuf, ConvertX0 - ConvertX1);
		CopySpace[CopyLocation0 - CopyLocation1] = '\0';
		SideSpace[ConvertX0 - ConvertX1] = '\0';
	}
}

void PasteText()
{
	int i, sum = 0;
	for (i = 0; i < strlen(CopySpace); i++)
		GB_insert(MainSpace, CopySpace[i]);
	for (i = 0; i < strlen(SideSpace); i++)
		GB_insert(DataSpace, SideSpace[i]);
	MidMainSpace += strlen(CopySpace);
	MidDataSpace += strlen(SideSpace);
	ControlFlag = 0;
	display();
}

void CutText()
{
	int ConvertY0 = (int)((textPosY + RowPitch - yCaret0) / RowPitch);
	int WordLength0 = textbuf_length(ConvertY0);
	int WordSum0 = textbuf_sum(WordLength0);
	int ConvertX0 = SumX(xCaret0, ConvertY0, WordSum0);
	int NumLineX0 = ConvertX0 - WordSum0;
	int LineX0 = LocationX(ConvertX0, WordSum0);

	int ConvertY1 = (int)((textPosY + RowPitch - yCaret1) / RowPitch);
	int WordLength1 = textbuf_length(ConvertY1);
	int WordSum1 = textbuf_sum(WordLength1);
	int ConvertX1 = SumX(xCaret1, ConvertY1, WordSum1);
	int NumLineX1 = ConvertX1 - WordSum1;
	int LineX1 = LocationX(ConvertX1, WordSum1);

	int CopyLocation1 = LineX1 + WordLength1;
	int CopyLocation0 = LineX0 + WordLength0;

	if (CopyLocation1 > CopyLocation0)
	{
		CopySpace = (char*)malloc(sizeof(char) * (CopyLocation1 - CopyLocation0) + 1);
		SideSpace = (char*)malloc(sizeof(char) * (ConvertX1 - ConvertX0) + 1);
		char* midbuf = (char*)malloc(sizeof(char) * (CopyLocation1 - CopyLocation0) + 1);
		memcpy(midbuf, GB_array(MainSpace) + CopyLocation0, CopyLocation1 - CopyLocation0);
		memcpy(CopySpace, midbuf, CopyLocation1 - CopyLocation0);
		memcpy(midbuf, GB_array(DataSpace) + ConvertX0, ConvertX1 - ConvertX0);
		memcpy(SideSpace, midbuf, ConvertX1 - ConvertX0);
		CopySpace[CopyLocation1 - CopyLocation0] = '\0';
		SideSpace[ConvertX1 - ConvertX0] = '\0';
		MidMainSpace = WordLength0 + LineX0;
		MidDataSpace = ConvertX0;
	}
	else
	{
		CopySpace = (char*)malloc(sizeof(char) * (CopyLocation0 - CopyLocation1) + 1);
		SideSpace = (char*)malloc(sizeof(char) * (ConvertX0 - ConvertX1) + 1);
		char* midbuf = (char*)malloc(sizeof(char) * (CopyLocation0 - CopyLocation1) + 1);
		memcpy(midbuf, GB_array(MainSpace) + CopyLocation1, CopyLocation0 - CopyLocation1);
		memcpy(CopySpace, midbuf, CopyLocation0 - CopyLocation1);
		memcpy(midbuf, GB_array(DataSpace) + ConvertX1, ConvertX0 - ConvertX1);
		memcpy(SideSpace, midbuf, ConvertX0 - ConvertX1);
		CopySpace[CopyLocation0 - CopyLocation1] = '\0';
		SideSpace[ConvertX0 - ConvertX1] = '\0';
		MidMainSpace = WordLength1 + LineX1;
		MidDataSpace = ConvertX1;
	}
	int i;
	if (CopyLocation0 > CopyLocation1)
	{

		for (i = 1; i <= CopyLocation0 - CopyLocation1; i++)
		{
			if (DataSpace->word[DataSpace->ahead - 1] == '2')
			{
				GB_backspace(MainSpace);
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
				if (xCaret > LeftWidth) { xCaret -= 2 * FontWidth1; }
				else
					xCaret = LeftWidth;
				i++;
			}
			else if (DataSpace->word[DataSpace->ahead - 1] == '1')
			{
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
				if (xCaret > LeftWidth) { xCaret -= FontWidth1; }
				else { xCaret = LeftWidth; }
			}
			else
			{
				GB_backspace(DataSpace);
				i--;
			}
		}
	}
	else
	{
		int ConvertY = (int)((textPosY + RowPitch - yCaret1) / RowPitch);
		int WordLength = textbuf_length(ConvertY);
		int WordSum = textbuf_sum(WordLength);
		int ConvertX = SumX(xCaret1, ConvertY, WordSum);
		int NumLineX = ConvertX - WordSum;
		int LineX = LocationX(ConvertX, WordSum);
		GB_move(MainSpace, WordLength + LineX - MainSpace->ahead);
		GB_move(DataSpace, ConvertX - DataSpace->ahead);
		for (i = 1; i <= CopyLocation1 - CopyLocation0; i++)
		{
			if (DataSpace->word[DataSpace->ahead - 1] == '2')
			{
				GB_backspace(MainSpace);
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
				if (xCaret > LeftWidth)
				{
					xCaret -= 2 * FontWidth1;
				}
				else {
					xCaret = LeftWidth;
				}
				i++;
			}
			else if (DataSpace->word[DataSpace->ahead - 1] == '1')
			{
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
				if (xCaret > LeftWidth)
				{
					xCaret -= FontWidth1;
				}
				else
					xCaret = LeftWidth;
			}
			else
			{
				GB_backspace(DataSpace);
				i--;
			}
		}
	}
	ControlFlag = 0;
	display();
}

void AllCopyText()
{
	CopySpace = (char*)malloc(sizeof(char) * (strlen(GB_array(MainSpace)) + 1));
	strcpy(CopySpace, GB_array(MainSpace));
}

void AllDeleteText()
{
	int i;
	AllCopyText();
	GB_move(MainSpace,MainSpace->total-MainSpace->ahead);
	for(i=1;i<=strlen(MainSpace->word);i++)
	GB_backspace(MainSpace);
	GB_move(DataSpace,DataSpace->total-DataSpace->ahead);
	for(i=1;i<=strlen(DataSpace->word);i++)
	GB_backspace(DataSpace);	 
	ControlFlag = 0;
	display(); 
	MidFlag = 3;
}

void RevokeText()
{
	if (MidFlag == 1)
	{
		GB_move(MainSpace, MidMainSpace - MainSpace->ahead);
		GB_move(DataSpace, MidDataSpace - DataSpace->ahead);
		PasteText();
	}
	if (MidFlag == 2)
	{
		GB_move(MainSpace, MidMainSpace - MainSpace->ahead);
		GB_move(DataSpace, MidDataSpace - DataSpace->ahead);
		int i, j;
		for (i = 0, j = 0; i < strlen(SideSpace); i++)
		{
			if (SideSpace[i] == '2')
			{
				GB_backspace(MainSpace);
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
			}
			else if (SideSpace[i] == '1')
			{
				GB_backspace(MainSpace);
				GB_backspace(DataSpace);
			}
			else
			{
				GB_backspace(DataSpace);
			}
		}
	}
	if (MidFlag == 3)
	{
		MainSpace = (space*)malloc(sizeof(space));
		DataSpace = (space*)malloc(sizeof(space));
		GB_init(MainSpace, 10000);
		GB_init(DataSpace, 10000);
		PasteText();
	}
	ControlFlag = 0;
	MidFlag = 0;
	display();
}
