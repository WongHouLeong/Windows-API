#include <Windows.h>
int main(int argc, char* argv[])
{
	MessageBoxA(NULL, "��ʼѧϰ��", "��ʦ", MB_OK | MB_ICONINFORMATION);
	if (MessageBoxA(NULL, "����˭�᣿", "��ʦ", MB_YESNO | MB_ICONQUESTION) == IDYES)
		MessageBoxA(NULL, "�һᣡ", "ѧ��", MB_OK | MB_ICONQUESTION);
	else
		MessageBoxA(NULL, "���ᣡ", "��", MB_OK | MB_ICONSTOP);
	return 0;
}