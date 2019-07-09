#include <stdio.h>
#include <Windows.h>
void test_sizeof(void)
{
	int result = sizeof(int);
	int result_1 = sizeof(long);
	int res2 = sizeof(DWORD);
}

void test1_sizeof(void)
{
	typedef struct _DCB {
		DWORD DCBlength; /* sizeof(DCB) */
		DWORD BaudRate; /* Baudrate at which running */
		DWORD fBinary : 1; /* Binary Mode (skip EOF check) */
		DWORD fParity : 1; /* Enable parity checking */
		DWORD fOutxCtsFlow : 1; /* CTS handshaking on output */
		DWORD fOutxDsrFlow : 1; /* DSR handshaking on output */
		DWORD fDtrControl : 2; /* DTR Flow control */
		DWORD fDsrSensitivity : 1; /* DSR Sensitivity */
		DWORD fTXContinueOnXoff : 1; /* Continue TX when Xoff sent */
		DWORD fOutX : 1; /* Enable output X-ON/X-OFF */
		DWORD fInX : 1; /* Enable input X-ON/X-OFF */
		DWORD fErrorChar : 1; /* Enable Err Replacement */
		DWORD fNull : 1; /* Enable Null stripping */
		DWORD fRtsControl : 2; /* Rts Flow control */
		DWORD fAbortOnError : 1; /* Abort all reads and writes on Error */
		DWORD fDummy2 : 17; /* Reserved */
		WORD wReserved; /* Not currently used */
		WORD XonLim; /* Transmit X-ON threshold */
		WORD XoffLim; /* Transmit X-OFF threshold */
		BYTE ByteSize; /* Number of bits/byte, 4-8 */
		BYTE Parity; /* 0-4=None,Odd,Even,Mark,Space */
		BYTE StopBits; /* 0,1,2 = 1, 1.5, 2 */
		char XonChar; /* Tx and Rx X-ON character */
		char XoffChar; /* Tx and Rx X-OFF character */
		char ErrorChar; /* Error replacement char */
		char EofChar; /* End of Input character */
		char EvtChar; /* Received Event character */
		WORD wReserved1; /* Fill for now. */
	} DCB;
	
	typedef struct CUSTOM {
		DWORD first : 1;
	}CUS;

	int siz = sizeof(DCB);
	int siz2 = sizeof(CUS);

	struct stu6 {
			DWORD first : 1;		
			DWORD second : 1;		
	};
	int siz3 =  sizeof(struct stu6);//32位环境下，结果为4

	struct stu7 {
		char first : 1;
		char second : 1;
		char first1 : 1;
		char second1 : 1;
		char first2 : 1;
		char second2 : 1;
		char first3 : 1;
		char second3 : 1;
		char first4 : 1;
		char second4 : 1;
	};
	int siz4 = sizeof(struct stu7);//32位环境下，结果为2

	struct stu7 struct_7 = {0};
	struct_7.first = 0;		//这样只会取最后一个bit
	struct_7.second = 1;
	struct_7.first1 = 2;
	struct_7.second1 = 3;



}