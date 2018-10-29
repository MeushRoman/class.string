#include "_string.h"


//конструктор по умолчанию
_string::_string()
{
	this->str = nullptr; //создается пустая строка
	this->length = 0;
}

//конструктор фиксированного размера строки
_string::_string(int length)
{
	this->str = new char[length+1];
	str[length] = '\0';
	this->length = length;
}

//конструктор создающий строку на основе str
_string::_string(const char * str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	this->length = strlen(str);
}

//конструктор копирования
_string::_string(const _string & obj)
{
	this->length = obj.length;
	if (obj.length == 0) {
		this->str = nullptr;
		return;
	}
	this->str = new char[obj.length + 1];
	strcpy_s(this->str, obj.length + 1, obj.str);

}

//конструктор возвращения строки
int _string::getLength()
{
	return this->length;
}

//конструктор возвращения размера
const char * _string::getString()
{
	return this->str;
}

//конструктор перезаписи строки
void _string::setString(const char * str)
{
	this->~_string();

	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);

	this->length = strlen(str);

}

void _string::insert(int position, const char * str)
{
	char *tmp;
	int k = position;

	if (str == nullptr || position < 0 || position > this->length) return;

	if (this->str == nullptr && position == 0) {
		this->setString(str);
		return;
	}

	tmp = new char[this->length + strlen(str) + 1];
	int newLength = length + strlen(str);
	for (int i = 0, j = 0; i < newLength + 1; i++)
	{
		if (i < position) tmp[i] = this->str[i];
		else
			if (i >= position && j < strlen(str))	{
				tmp[i] = str[j];
				j++;
			}
			else	{
				tmp[i] = this->str[k];
				k++;
			}
	}
	this->~_string();
	this->str = tmp;
	this->length = newLength;
	this->str[length] = '\0';
}

void _string::erase(int position, int number)
{
	char *tmp;
	if (position < 0 || this->str == nullptr || this->length < position + number) return;
	int newLenght = this->length - number;
	tmp = new char[newLenght + 1];
	for (int i = 0; i < newLenght + 1; i++)
	{
		if (i < position)
			tmp[i] = this->str[i];
		else if (i >= position)
			tmp[i] = this->str[i + number];
	}
	this->~_string();
	this->str = tmp;
	this->length = newLenght;
}


//конструктор ввода с консоли
void _string::input()
{
	this->~_string();

	char tmp[1200];
	cin.getline(tmp, 1200);
	
	this->str = new char[strlen(tmp) + 1];
	strcpy_s(this->str, strlen(tmp) + 1, tmp);

	this->length = strlen(tmp);
}

//конструктор очистки строки
void _string::clear()
{
	this->~_string();
}

//конструктор распечатки строки
void _string::output()
{
	cout << this->str;
}

//деструктор
_string::~_string()
{
	if (this->str != nullptr) delete[] str;
	this->str = nullptr;
	this->length = 0;
}
