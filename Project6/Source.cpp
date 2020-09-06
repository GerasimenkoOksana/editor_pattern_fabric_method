#include"Editor.h"
#include<Windows.h>
int main()
{
	setlocale(0, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Creator* creator;
	Editor* editor;
	int type;
	cout << "� ����� ���������� ������ ��������? 1 -  ��������� ��������  2 - ����������� ��������:   ";
	cin >> type;
	switch (type)
	{
	case 1: creator = new TextEditCreator; break;
	case 2: creator = new DrawEditCreator; break;
	default: creator = nullptr;	break;
	}
	if (creator)
	{		
		editor = creator->create();
		while (true)
		{
			system("cls");
			cout << "1 - �������" << endl;
			cout << "2 - �������" << endl;
			cout << "3 - ���������" << endl;
			cout << "4 - ��������� ���..." << endl;
			cout << "5 - ������" << endl;
			cout << "6 - �������" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 1: editor->create(); break;
			case 2: editor->open(); break;
			case 3: editor->save(); break;
			case 4: editor->saveAs(); break;
			case 5: editor->print(); break;
			case 6: editor->close(); break;
			default:
				break;
			}
		}
	}
	else cout << "������ ������" << endl;
	system("pause");
}