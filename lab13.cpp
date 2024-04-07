#include "book.h"


bool sort_deque(const Book& ob1, const Book& ob2) // Функция для сортировки по названию
{
    return ob1.title < ob2.title;
}
void print_deque(std::deque<Book>& deque) { // Печать deque
    std::cout << "-----Deque-----" << std::endl;
    for (auto& elem : deque) {
        elem.print();
        std::cout << std::endl;
    }
}
void print_list(std::list<Book>& list) { // Печать list
    std::cout << "-----List-----" << std::endl;
    for (auto& elem : list) {
        elem.print();
        std::cout << std::endl;
    }
}
void print_set(std::set<Book>& set) { // Запись list в файл
    std::cout << "-----Set-----" << std::endl;
    for (auto& elem : set) {
        elem.print();
        std::cout << std::endl;
    }
}
void print_unordered(std::unordered_set<Book, BookHash>& unordered) {
    std::cout << "-----Unordered set-----" << std::endl;
    for (auto& elem : unordered) {
        elem.print();
        std::cout << std::endl;
    }
}
void deque_to_file(std::ofstream& fout, std::deque<Book>& deque) { // Запись deque в файл
    fout << "-----Deque-----\n";
    for (auto& elem : deque) {
        fout << elem << "\n";
    }
}
void list_to_file(std::ofstream& fout, std::list<Book>& list) { // Запись list в файл
    fout << "-----List-----\n";
    for (auto& elem : list) {
        fout << elem << "\n";
    }
}
void set_to_file(std::ofstream& fout, std::set<Book>& set) { // Запись list в файл
    fout << "-----Set-----\n";
    for (auto& elem : set) {
        fout << elem << "\n";
    }
}
void unordered_to_file(std::ofstream& fout, std::unordered_set<Book, BookHash>& unordered) {
    fout << "-----Unordered set-----\n";
    for (auto& elem : unordered) {
        fout << elem << "\n";
    }
}
int main(int argc, const char* argv[])
{
    int enough_arguments = 3;
    if (argc != enough_arguments) { // Проверка на количество аргументов при запуске
        std::cerr << "Not enough arguments :(" << std::endl;
        std::cerr << "Need: " << enough_arguments << " Given: " << argc << std::endl;
        return -1;
    }
    const std::string in = argv[1];
    const std::string out = argv[2];
    std::ifstream fin(in);
    std::ofstream fout(out);
    if (!fin) { // Проверка на наличие файла для чтения
        std::cerr << "File not found :(" << std::endl;
        return -2;
    }
    int quantity = 0; // Количество строк в файле
    int private_variables = 5;
    std::string temp;
    while (!fin.eof()) { // Подсчет строк в файле
        std::getline(fin, temp);
        ++quantity;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg); // Перевод курсора в начало файла
    quantity /= private_variables; // Количество объектов

    std::deque<Book> deque_book(quantity);
    std::list<Book> list_book;
    std::set<Book> set_book;
    std::unordered_set<Book,BookHash> unordered_book;

    for (int i = 0; i < quantity; ++i) { // Считываем данные в контейнер из файла
        if (i != 0) fin.ignore();
        std::string fio;
        std::string title;
        std::string publisher;
        int year, count_page;
        std::getline(fin, fio);
        std::getline(fin, title);
        std::getline(fin, publisher);
        fin >> year;
        fin >> count_page;
        deque_book[i].set(fio, title, publisher, year, count_page);
    }
    print_deque(deque_book); // Выводим информацию на печать
    deque_to_file(fout, deque_book); // Выводим информацию в файл

    for (auto& elem : deque_book) {
        set_book.insert(elem);
    }
    print_set(set_book);
    set_to_file(fout, set_book);


    for (auto& elem : deque_book) {
        unordered_book.insert(elem);
    }
    print_unordered(unordered_book);
    unordered_to_file(fout, unordered_book);

    std::copy(deque_book.begin(), deque_book.end(), std::back_inserter(list_book)); // Копируем deque в list
    std::cout << "-----Copied deque to list-----" << std::endl;;
    print_list(list_book);
    fout << "-----Copied deque to list-----\n";
    list_to_file(fout, list_book);

    std::sort(deque_book.begin(), deque_book.end(), sort_deque); // Сортируем deque
    std::cout << "-----Sorted deque-----" << std::endl;
    print_deque(deque_book);
    fout << "-----Sorted deque-----\n";
    deque_to_file(fout, deque_book);
    set_to_file(fout, set_book);
    return 0;
}
