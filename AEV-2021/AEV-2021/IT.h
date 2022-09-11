#pragma once

#include "stdafx.h"
#include "Error.h"
#include "LT.h"

#define ID_MAXSIZE		10																	// ������������ ���������� �������� � ��������������													// ������������ ����� �������� � �������������� + ������� ���������
#define TI_MAXSIZE		4096																// ������������ ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT	0x00000000															// �������� �� ��������� ��� ���� integer
#define TI_STR_DEFAULT	0x00																// �������� �� ��������� ��� ���� string
#define TI_NULLIDX		0xffffffff															// ��� �������� ������� ���������������
#define TI_STR_MAXSIZE	255																	// ������������ ����� ������													
#define MAX_PARAMS_COUNT 3
#define COMBINE_PARAMS_CNT 2
#define LEXCOMP_PARAMS_CNT 2
#define MEASURE_PARAMS_CNT 1
#define RANDOMIZE_PARAMS_CNT 2
#define EXPONENT_PARAMS_CNT 2

#define COMBINE_TYPE IT::IDDATATYPE::STR
#define LEXCOMP_TYPE IT::IDDATATYPE::INT
#define MEASURE_TYPE IT::IDDATATYPE::INT
#define RANDOMIZE_TYPE IT::IDDATATYPE::INT
#define EXPONENT_TYPE IT::IDDATATYPE::INT

namespace IT																				// ������� ���������������
{
	enum IDDATATYPE { INT = 1, STR = 2, PROC = 3, BOOL = 4, CHR = 5,  UNKNOWN };		// ���� ������ ���������������: integer, string, ��� ����(���������), bool, ������ ��������������
	enum IDTYPE {
		V = 1, F = 2, P = 3, L = 4, S = 5						// ���� ���������������: ����������, �������, ��������, �������, ����. �������
	};

	static const IDDATATYPE LINK_PARAMS[] = { IT::IDDATATYPE::STR, IT::IDDATATYPE::STR };
	static const IDDATATYPE LEXCOMP_PARAMS[] = { IT::IDDATATYPE::STR, IT::IDDATATYPE::STR };
	static const IDDATATYPE MEASURE_PARAMS[] = { IT::IDDATATYPE::STR };
	static const IDDATATYPE RANDOMIZE_PARAMS[] = { IT::IDDATATYPE::INT, IT::IDDATATYPE::INT };
	static const IDDATATYPE EXPONENT_PARAMS[] = { IT::IDDATATYPE::INT, IT::IDDATATYPE::INT };

	struct Entry												// ������ ������� ���������������
	{
		int			idxfirstLE;									// ������ ������ ������ � ������� ������
		unsigned char id[ID_MAXSIZE];							// ��������������
		IDDATATYPE	iddatatype = UNKNOWN;						// ��� ������
		IDTYPE		idtype;										// ��� ��������������
		unsigned char visibility[ID_MAXSIZE];					// ������� ���������

		struct
		{
			int vint;											// �������� integer
			struct
			{
				int len;										// ���������� �������� � string
				unsigned char str[TI_STR_MAXSIZE - 1];			// ������� string
			} vstr;												// �������� string
			struct
			{
				int count;										// ���������� ���������� �������
				IDDATATYPE* types;								// ���� ���������� �������
			} params;
		} value = { LT_TI_NULLIDX };							// �������� ��������������
	};

	struct IdTable												// ��������� ������� ���������������
	{
		int maxsize;											// ������� ������� ��������������� < TI_MAXSIZE
		int size;												// ������� ������ ������� ��������������� < maxsize
		Entry* table;											// ������ ����� ������� ���������������
	};

	IdTable Create(																			// ������� ������� ���������������
		int size																			// ������� ������� ��������������� < TI_MAXSIZE
		);

	void Add(																				// �������� ������ � ������� ���������������
		IdTable& idtable,																	// ��������� ������� ���������������
		Entry entry																			// ������ ������� ���������������
		);

	Entry GetEntry(																			// �������� ������ ������� ���������������
		IdTable& idtable,																	// ��������� ������� ���������������
		int n																				// ����� ���������� ������
		);

	int IsId(																				// �������: ����� ������ (���� ����), TI_NULLIDX (���� ���)
		IdTable& idtable,																	// ��������� ������� ���������������
		unsigned char id[ID_MAXSIZE]														// �������������
		);

	void Delete(IdTable& idtable);															// ������� ������� ������ (���������� ������)

	void WriteTable(IdTable& idtable);
};