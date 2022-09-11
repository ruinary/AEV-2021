#pragma once

#include "Error.h"

#define LEXEMA_FIXSIZE		1																// ������������� ������ �������
#define LT_MAXSIZE			4096															// ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX		0xfffffff														// ��� �������� ������� ���������������

#define LEX_TYPE			't'						// ������� ��� ���������� ���� (int_ chr_ str_ bool_)
#define LEX_CREATE			'c'						// ������� ��� �������� ���������� (create)
#define LEX_ID				'i'						// ������� ��� ��������������
#define LEX_LITERAL			'l'						// ������� ��� ��������
#define LEX_MAIN			'm'						// ������� ��� main
#define LEX_FUNCTION		'f'						// ������� ��� function
#define LEX_PROCEDURE		'p'						// ������� ��� procedure
#define LEX_GIVE			'r'						// ������� ��� ����������� �������� (give)
#define LEX_SPEAK			'o'						// ������� ��� ������ � ������� (speak)
#define LEX_OPERATOR		'v'						// ������� ��� ���������� (+ - * / %)
#define LEX_EQUAL			'='						// ������� ��� ��������� ������������ (=)
#define LEX_LOGOPERATOR		'g'						// ������� ��� ����������� ��������� (> < ~ #)
#define LEX_�YCLE			'u'						// ������� ��� cycle (����)
#define LEX_WHERE			'w'						// ������� ��� where (�������� ��������)
#define LEX_OTHERWISE		'!'						// ������� ��� otherwise (�������� ��������)
#define LEX_SEMICOLON		';'						// ������� ��� ;
#define LEX_COMMA			','						// ������� ��� ,
#define LEX_LEFTBRACE		'{'						// ������� ��� {
#define LEX_BRACELET		'}'						// ������� ��� }
#define LEX_LEFTTHESIS		'['						// ������� ��� [
#define LEX_RIGHTTHESIS		']'						// ������� ��� ]
#define LEX_LEFTBRACKET		'('						// ������� ��� (
#define LEX_RIGHTBRACKET	')'						// ������� ��� )

#define LEX_COMBINE			'+'						// ������� ��� ������������ ����� (combine)
#define LEX_LEXCOMP			'*'						// ������� ��� ������������ ����� (combine)
#define LEX_MEASURE			'%'						// ������� ��� ��������� ����� ������ (measure)
#define LEX_EXPONENT		'e'						// ������� ��� ���������� � ������� (exponent)
#define LEX_BREAKL			'b'						// ������� ��� �������� �� ����� ������ (breakl)
#define LEX_RANDOMIZE		'z'						// ������� ��� ��������� ���������� ����� � ��������� (randomize)

namespace LT																				// ������� ������
{
	enum OPER { NOT = -1, PLUS = 1, MINUS, MUL, DIV, REST, MORE, LESS, EQU, NOEQU };

	struct Entry								// ������ ������� ������
	{
		unsigned char lexema;					// �������
		int line;								// ����� ������ � �������� ������
		int idxTI;								// ������ � ������� ��������������� ��� LT_TI_NULLIDX
		int priority;							// ���������
		OPER operation;
	};

	struct LexTable								// ��������� ������� ������
	{
		int maxsize;							// ������� ������� ������ < LT_MAXSIZE
		int size;								// ������� ������ ������� ������ < maxsize
		Entry* table;							// ������ ����� ������� ������
	};

	LexTable Create(																		// ������� ������� ������
		int size																			// ������� ������� ������ < LT_MAXSIZE
		);

	void Add(																				// �������� ������ � ������� ������
		LexTable& lextable,																	// ��������� ������� ������
		Entry entry																			// ������ ������� ������
		);

	Entry GetEntry(																			// �������� ������ ������� ������
		LexTable& lextable,																	// ��������� ������� ������
		int n																				// ����� ���������� ������
		);

	void Delete(LexTable& lextable);														// ������� ������� ������ (���������� ������)

	Entry writeEntry(																		// ��������� ������ ������� ������
		Entry& entry,
		unsigned char lexema,
		int indx,
		int line,
		int priority = -1,
		OPER operation = NOT
		);

	void WriteLexTable(LexTable& lextable);

	void WriteTokens(LexTable lextable);
};