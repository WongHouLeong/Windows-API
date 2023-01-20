#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK Dlgproc(HWND hModule, UINT type, WPARAM wParam, LPARAM lParam)
{
	switch (type) {  //对话框初始化事件
	case WM_INITDIALOG:
	{
		SetDlgItemTextA(hModule, IDC_EDIT1, "Hello");
		MessageBoxA(hModule, "初始化啦！", "提示", 0);
		HWND hwnd = GetDlgItem(hModule, IDC_EDIT1); //这里的IDC_EDIT1是对话框里的编辑框组件ID
		break;
	}
	case WM_COMMAND: { //触发的组件ID
		switch (wParam)
		{
		case IDOK: { //确认
			char string[15];
			GetDlgItemTextA(hModule, IDC_EDIT1, string, sizeof(string));
			MessageBoxA(hModule, string, "提示", 0);
			EndDialog(hModule, 0); //关闭窗口并返回值0
			break;
		}
		case IDCANCEL: {  //取消
			MessageBoxA(hModule, "取消！", "提示", 0);
			EndDialog(hModule, 1); //关闭窗口并返回值1
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: { //对话框关闭事件
		EndDialog(hModule, 123); //关闭窗口并返回值123
		break;
	}
	default://默认不做任何处理
		break;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int ret = DialogBoxParamA(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Dlgproc, 0);
	return 0;
}