#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK Dlgproc(HWND hModule, UINT type, WPARAM wParam, LPARAM lParam)
{
	switch (type) {  //�Ի����ʼ���¼�
	case WM_INITDIALOG:
	{
		SetDlgItemTextA(hModule, IDC_EDIT1, "Hello");
		MessageBoxA(hModule, "��ʼ������", "��ʾ", 0);
		HWND hwnd = GetDlgItem(hModule, IDC_EDIT1); //�����IDC_EDIT1�ǶԻ�����ı༭�����ID
		break;
	}
	case WM_COMMAND: { //���������ID
		switch (wParam)
		{
		case IDOK: { //ȷ��
			char string[15];
			GetDlgItemTextA(hModule, IDC_EDIT1, string, sizeof(string));
			MessageBoxA(hModule, string, "��ʾ", 0);
			EndDialog(hModule, 0); //�رմ��ڲ�����ֵ0
			break;
		}
		case IDCANCEL: {  //ȡ��
			MessageBoxA(hModule, "ȡ����", "��ʾ", 0);
			EndDialog(hModule, 1); //�رմ��ڲ�����ֵ1
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: { //�Ի���ر��¼�
		EndDialog(hModule, 123); //�رմ��ڲ�����ֵ123
		break;
	}
	default://Ĭ�ϲ����κδ���
		break;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int ret = DialogBoxParamA(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Dlgproc, 0);
	return 0;
}