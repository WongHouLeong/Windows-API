#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK Dlgproc(HWND hModule, UINT type, WPARAM wParam, LPARAM lParam)
{
	switch (type) {  //�Ի����ʼ���¼�
	case WM_INITDIALOG:
	{
		MessageBoxA(hModule, "��ʼ������", "��ʾ", 0);
		break;
	}
	case WM_COMMAND: { //���������ID
		switch (wParam)
		{
		case IDOK: { //ȷ��
			MessageBoxA(hModule, "ȷ�ϣ�", "��ʾ", 0);
			break;
		}
		case IDCANCEL: {  //ȡ��
			MessageBoxA(hModule, "ȡ����", "��ʾ", 0);
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: { //�Ի���ر��¼�
		break;
	}
	default://Ĭ�ϲ����κδ���
		break;
	}
	return false;
}

int main(int argc, char* argv[])
{
	DialogBoxParamA(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Dlgproc, 0);
	return 0;
}