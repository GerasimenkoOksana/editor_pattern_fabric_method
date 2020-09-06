#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Editor
{
public:
	virtual ~Editor() {}
	virtual void create() = 0;
	virtual void open() = 0;
	virtual void save() = 0;
	virtual void saveAs() = 0;
	virtual void print() = 0;
	virtual void close() = 0;
};

class TextEditor : public Editor
{
	string file ="";
	vector<string> text;
public:
	void create() override
	{
		if (file != "" || text.size())
		{
			cout << "Закройте документ" << endl;
			system("pause");
		}
		else
		{
			system("cls");
			cout << "           Новый документ <Noname>.       Для выхода нажмите 0" << endl;
			string buf;
			do
			{
				getline(cin, buf);
				if (buf != "0")
					text.push_back(buf);
			} while (buf != "0");
		}
	}
	void open() override
	{
		if (text.size())
			cout << "Сначала закройте открытый документ. При необходимости - сохраните" << endl;
		else
		{
			cout << "Введите имя документа для открытия: ";
			string f;
			cin >> f;
			ifstream in(f);
			if (in.is_open())
			{
				file = f;
				system("cls");
				cout << "           Документ " <<f<< endl;
				while (!in.eof())
				{
					string buf;
					getline(in,buf);
					text.push_back(buf);
					cout << buf << endl;
				}
				in.close();
			}
			else cout << "Документ не найден" << endl;
		}
		system("pause");
	}
	void save() override
	{
		if (file != "")
		{
			cout << "Документ сохранен под именем " << file << endl;			
		}
		else if (file == "" && text.size())
		{
			cout << "Введите имя файла для сохранения: ";
			cin >> file;
			ofstream out(file);
			for (auto& x : text)
				out << x << endl;
			out.close();
			cout << "Документ сохранен!" << endl;
		}
		else cout << "Документ не был создан или открыт. Сохранение невозможно. " << endl;
		system("pause");
	}
	void saveAs() override
	{
		if (file=="" && !text.size())
			cout << "Документ не был создан или открыт. Сохранение невозможно. " << endl;
		else
		{
			cout << "Введите имя файла для сохранения: ";
			cin >> file;
			ofstream out(file);
			for (auto& x : text)
				out << x << endl;
			out.close();
			cout << "Документ сохранен под именем "<<file << endl;
		}
		system("pause");
	}
	void print() override
	{
		if (file =="" && !text.size())
			cout<<"Документ не был создан или открыт. Печать невозможна. " << endl;
		else
		{
			system("cls");
			if (file != "")
				cout << "Документ " << file << endl;
			else cout << "Новый документ  <Noname>" << endl;
			for (auto& x : text)
				cout << x << endl;
		}
		system("pause");
	}
	void close() override
	{
		if (text.size())
		cout << "Вы уверены, что сохранили необходимые изменения? 1 - да 2 - отмена:   ";
		int vibor;
		cin >> vibor;
		if (vibor == 1)
		{
			file = "";
			text.clear();
			cout << "Документ закрыт!" << endl;
		}
		system("pause");
	}
};

class DrawEditor : public Editor
{
	string file = "";
	string picture = "";
public:
	void create() override
	{
		if (file != "" || picture != "")
			cout << "Закройте документ" << endl;
		else
		{
			system("cls");
			cout << "           Новый рисунок <Noname>. " << endl;
			cout << "Нарисуйте что-нибудь в одну строку и нажмите ENTER" << endl;
			cin.ignore();
			getline(cin, picture);				
		}
		system("pause");
	}
	void open() override
	{
		if (picture != "")
			cout << "Сначала закройте рисунок. При необходимости - сохраните" << endl;
		else
		{
			cout << "Введите имя файла для открытия: ";
			string f;
			cin >> f;
			ifstream in(f);
			if (in.is_open())
			{
				file = f;
				system("cls");
				cout << "          Рисунок " << f << endl;
				getline(in, picture);				
				cout << picture << endl;			
			    in.close();
			}
			else cout << "Файл не найден" << endl;
		}
		system("pause");
	}
	void save() override
	{
		if (file != "")
		{
			cout << "Рисунок сохранен под именем " << file << endl;
		}
		else if (file == "" && picture !="")
		{
			cout << "Введите имя файла для сохранения: ";
			cin >> file;
			ofstream out(file);
			out << picture << endl;
			out.close();
			cout << "Рисунок сохранен!" << endl;
		}
		else cout << "Рисунок не был создан или открыт. Сохранение невозможно. " << endl;
		system("pause");
	}
	void saveAs() override
	{
		if (file == "" && picture == "")
			cout << "Документ не был создан или открыт. Сохранение невозможно. " << endl;
		else
		{
			cout << "Введите имя файла для сохранения: ";
			cin >> file;
			ofstream out(file);
			out << picture << endl;
			out.close();
			cout << "Рисунок сохранен под именем " << file << endl;
		}
		system("pause");
	}
	void print() override
	{
		if (file == "" && picture == "")
			cout << "Документ не был создан или открыт. Печать невозможна. " << endl;
		else
		{
			system("cls");
			if (file != "")
				cout << "Рисунок " << file << endl;
			else cout << "Новый рисунок  <Noname>" << endl;
			cout << picture << endl;
			system("pause");
		}
		system("pause");
	}
	void close() override
	{
		if (picture != "")
			cout << "Вы уверены, что сохранили необходимые изменения? 1 - да 2 - отмена:   ";
		int vibor;
		cin >> vibor;
		if (vibor == 1)
		{
			file = "";
			picture = "";
			cout << "Рисунок закрыт!" << endl;
		}
		system("pause");
	}
};

class Creator
{
public:
	virtual ~Creator() {}
	virtual Editor* createEditor() = 0;
	Editor* create()
	{
		Editor* editor = this->createEditor();
		return editor;
	}
};

class TextEditCreator : public Creator
{
public:
	Editor* createEditor() override
	{
		return new TextEditor;
	}
};

class DrawEditCreator : public Creator
{
public:
	Editor* createEditor() override
	{
		return new DrawEditor;
	}
};