#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <list>
#include <algorithm>
#include <set>
#include <unordered_set>
class Book {
	std::string fio; // Основные переменные класса
	std::string title;
	std::string publisher;
	size_t year = 0;
	size_t count_page = 0;
public:
	Book(); //Пустой конструктор
	Book(const Book& bk); // Конструктор копирования
	Book(Book&& bk); // Конструктор перемещения
	void print() const; // Вывод на печать
	void set(std::string fio, std::string title, std::string publisher, int year, int count_page); // Инициализтор
	Book& operator = (const Book& bk); // Перегрузка операций
	Book& operator = (Book&& bk);
	~Book(); // Деструктор
	std::string get_title() const;
	friend std::ofstream& operator <<(std::ofstream& out, const Book& bk); // Дружественная функции вставки в поток
	friend std::ifstream& operator >> (std::ifstream& in, Book& bk);
	friend bool sort_deque(const Book& ob1, const Book& ob2); // Дружественная функция сортировки
	friend bool operator > (const Book& bn1, const Book& bn2); // Перегрузка операций сравнения
	friend bool operator < (const Book& bn1, const Book& bn2);
	friend bool operator >= (const Book& bn1, const Book& bn2);
	friend bool operator <= (const Book& bn1, const Book& bn2);
	friend bool operator == (const Book& bn1, const Book& bn2);
	friend bool operator != (const Book& bn1, const Book& bn2);
};
class BookHash {
public:
	size_t operator()(const Book& bk) const;
};
