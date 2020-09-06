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
	cout << "С каким редактором хотите работать? 1 -  текстовый редактор  2 - графический редактор:   ";
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
			cout << "1 - создать" << endl;
			cout << "2 - открыть" << endl;
			cout << "3 - сохранить" << endl;
			cout << "4 - сохранить как..." << endl;
			cout << "5 - печать" << endl;
			cout << "6 - закрыть" << endl;
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
	else cout << "ошибка выбора" << endl;
	system("pause");
}