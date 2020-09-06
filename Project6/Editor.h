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
			cout << "�������� ��������" << endl;
			system("pause");
		}
		else
		{
			system("cls");
			cout << "           ����� �������� <Noname>.       ��� ������ ������� 0" << endl;
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
			cout << "������� �������� �������� ��������. ��� ������������� - ���������" << endl;
		else
		{
			cout << "������� ��� ��������� ��� ��������: ";
			string f;
			cin >> f;
			ifstream in(f);
			if (in.is_open())
			{
				file = f;
				system("cls");
				cout << "           �������� " <<f<< endl;
				while (!in.eof())
				{
					string buf;
					getline(in,buf);
					text.push_back(buf);
					cout << buf << endl;
				}
				in.close();
			}
			else cout << "�������� �� ������" << endl;
		}
		system("pause");
	}
	void save() override
	{
		if (file != "")
		{
			cout << "�������� �������� ��� ������ " << file << endl;			
		}
		else if (file == "" && text.size())
		{
			cout << "������� ��� ����� ��� ����������: ";
			cin >> file;
			ofstream out(file);
			for (auto& x : text)
				out << x << endl;
			out.close();
			cout << "�������� ��������!" << endl;
		}
		else cout << "�������� �� ��� ������ ��� ������. ���������� ����������. " << endl;
		system("pause");
	}
	void saveAs() override
	{
		if (file=="" && !text.size())
			cout << "�������� �� ��� ������ ��� ������. ���������� ����������. " << endl;
		else
		{
			cout << "������� ��� ����� ��� ����������: ";
			cin >> file;
			ofstream out(file);
			for (auto& x : text)
				out << x << endl;
			out.close();
			cout << "�������� �������� ��� ������ "<<file << endl;
		}
		system("pause");
	}
	void print() override
	{
		if (file =="" && !text.size())
			cout<<"�������� �� ��� ������ ��� ������. ������ ����������. " << endl;
		else
		{
			system("cls");
			if (file != "")
				cout << "�������� " << file << endl;
			else cout << "����� ��������  <Noname>" << endl;
			for (auto& x : text)
				cout << x << endl;
		}
		system("pause");
	}
	void close() override
	{
		if (text.size())
		cout << "�� �������, ��� ��������� ����������� ���������? 1 - �� 2 - ������:   ";
		int vibor;
		cin >> vibor;
		if (vibor == 1)
		{
			file = "";
			text.clear();
			cout << "�������� ������!" << endl;
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
			cout << "�������� ��������" << endl;
		else
		{
			system("cls");
			cout << "           ����� ������� <Noname>. " << endl;
			cout << "��������� ���-������ � ���� ������ � ������� ENTER" << endl;
			cin.ignore();
			getline(cin, picture);				
		}
		system("pause");
	}
	void open() override
	{
		if (picture != "")
			cout << "������� �������� �������. ��� ������������� - ���������" << endl;
		else
		{
			cout << "������� ��� ����� ��� ��������: ";
			string f;
			cin >> f;
			ifstream in(f);
			if (in.is_open())
			{
				file = f;
				system("cls");
				cout << "          ������� " << f << endl;
				getline(in, picture);				
				cout << picture << endl;			
			    in.close();
			}
			else cout << "���� �� ������" << endl;
		}
		system("pause");
	}
	void save() override
	{
		if (file != "")
		{
			cout << "������� �������� ��� ������ " << file << endl;
		}
		else if (file == "" && picture !="")
		{
			cout << "������� ��� ����� ��� ����������: ";
			cin >> file;
			ofstream out(file);
			out << picture << endl;
			out.close();
			cout << "������� ��������!" << endl;
		}
		else cout << "������� �� ��� ������ ��� ������. ���������� ����������. " << endl;
		system("pause");
	}
	void saveAs() override
	{
		if (file == "" && picture == "")
			cout << "�������� �� ��� ������ ��� ������. ���������� ����������. " << endl;
		else
		{
			cout << "������� ��� ����� ��� ����������: ";
			cin >> file;
			ofstream out(file);
			out << picture << endl;
			out.close();
			cout << "������� �������� ��� ������ " << file << endl;
		}
		system("pause");
	}
	void print() override
	{
		if (file == "" && picture == "")
			cout << "�������� �� ��� ������ ��� ������. ������ ����������. " << endl;
		else
		{
			system("cls");
			if (file != "")
				cout << "������� " << file << endl;
			else cout << "����� �������  <Noname>" << endl;
			cout << picture << endl;
			system("pause");
		}
		system("pause");
	}
	void close() override
	{
		if (picture != "")
			cout << "�� �������, ��� ��������� ����������� ���������? 1 - �� 2 - ������:   ";
		int vibor;
		cin >> vibor;
		if (vibor == 1)
		{
			file = "";
			picture = "";
			cout << "������� ������!" << endl;
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