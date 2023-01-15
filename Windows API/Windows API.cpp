#include <Windows.h>
int main(int argc, char* argv[])
{
	MessageBoxA(NULL, "开始学习！", "老师", MB_OK | MB_ICONINFORMATION);
	if (MessageBoxA(NULL, "这题谁会？", "老师", MB_YESNO | MB_ICONQUESTION) == IDYES)
		MessageBoxA(NULL, "我会！", "学霸", MB_OK | MB_ICONQUESTION);
	else
		MessageBoxA(NULL, "不会！", "我", MB_OK | MB_ICONSTOP);
	return 0;
}