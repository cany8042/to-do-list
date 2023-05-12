#include <iostream>
#include <fstream>
#include<string>
#include <locale.h> 
#include "windows.h"
#include "List.h"


// show_menu- выводим меню в консоль 
void show_menu()
{
	setlocale(LC_ALL, "rus");
	std::cout << "\t\t\t***********************************************************************" << std::endl;
	std::cout << "\t\t\t***********************************************************************" << std::endl;
	std::cout << "\t\t\t                  😎          ДОБРО ПОЖАЛОВАТЬ         😎            " << std::endl;
	std::cout << "\t\t\t                               В ваш список дел                        " << std::endl;
	std::cout << "\t\t\t***********************************************************************" << std::endl;

	std::cout << "\n\t[1] Добавить задачу" << std::endl;
	std::cout << "\n\t[2] Показать задачи." << std::endl;
	std::cout << "\n\t[3] Найти задачу." << std::endl;
	std::cout << "\n\t[4] Удалить одну задачу." << std::endl;
	std::cout << "\n\t[5] Удалить все задачи." << std::endl;
	std::cout << "\n\t[6] Выход." << std::endl;
}
// add_note - добавить задачу 
void add_note(const std::string& new_note)
{
	//добавляем заметку в созданый текстовый файл
	std::cout << new_note;
	std::ofstream file("tasks.txt", std::ios::app);
	if (!file.is_open())
	{
		std::cout << "\n\t[-] Файл не открывается!";
		exit(EXIT_FAILURE);
	}
	file << new_note << std::endl;

	file.close();

	std::cout << "\n\tЗадача добавлена!  ";
}

// see_all_notes - покзать все заметки
void see_all_notes()
{
	std::ifstream file("tasks.txt");
	if (!file.is_open())
	{
		std::cout << "\n\tЗадач нет! Добавьте их!" << std::endl;
		return;
	}
	std::string one_note;
	std::cout << "\n\tВсе задачи:" << std::endl;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, one_note);
		if (one_note.empty())
			continue;
		std::cout << '[' << i << "] " << one_note << std::endl;
	}
	file.close();
}


//find_one_note - поиск одной заметке
std::string* find_one_note(const std::string& note_to_find, int& n_count)
{
	std::ifstream file("tasks.txt");
	if (!file.is_open())
	{
		std::cout << "Задач нет! Добавьте их" << std::endl;
		return nullptr;
	}
	std::string one_note;
	std::string* found_notes = nullptr;
	std::string* found_notes_tmp = nullptr;
	int count = 0;// количество найденых элементов
	while (!file.eof())
	{
		getline(file, one_note);
		if (one_note.find(note_to_find) != -1) {
			count++;
			found_notes_tmp = new std::string[count];

			//копируем все уже найденые заметки 
			for (int i = 0; i < count - 1; i++)
				found_notes_tmp[i] = found_notes[i];

			//добавляем найденую заметку
			found_notes_tmp[count - 1] = one_note;

			//удаляем стаорое содержимое found_notes чтобы небыло утечки памяти
			delete[] found_notes;

			//found_notes указывает на новый массив
			found_notes = found_notes_tmp;
			found_notes_tmp = nullptr;
		}
	}
	file.close();
	n_count = count;
	return found_notes;
}

//Возвращает указатель на массив всех заметок
std::string* all_notes(int& n_count)
{
	std::string* all_notes = nullptr;
	std::string* all_notes_ptr = nullptr;

	std::ifstream file("tasks.txt");
	if (!file.is_open())
	{
		std::cout << "\n\tФайл не открывает";
		exit(EXIT_FAILURE);
	}
	std::string one_note;
	int count = 0;
	while (!file.eof())
	{
		getline(file, one_note);
		if (one_note.empty())
			continue;
		count++;
		all_notes_ptr = new std::string[count];

		//Копируем уже считаные заметки
		for (int i = 0; i < count - 1; i++)
			all_notes_ptr[i] = all_notes[i];

		//Добавляем новую заметку
		all_notes_ptr[count - 1] = one_note;

		//Очищаем старый массив all_notes
		delete[] all_notes;

		//all_notes указывает на новый массив
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;

	}
	file.close();
	n_count = count;

	return all_notes;
}


//Удаляем одну заметку под индексом choice-1
void remove_one_note(std::string* all_notes_arr, int count, int choice)
{
	std::ofstream file("tasks.txt");
	if (!file.is_open())
	{
		std::cout << "\n\t[-]Ошибка! Файл не открывается!" << std::endl;
		exit(EXIT_FAILURE);
	}

	//Перезапись заметок без заметки с индексом choice-1
	for (int i = 0; i < count; i++)
	{
		if (i + 1 == choice )//Пропуск заметки с индексом choice-1
			continue;
		file << all_notes_arr[i] << std::endl;
	}
	file.close();
}

//Удаляет все заметки
void remove_all_notes()
{
	std::fstream file("tasks.txt", std::ios::out | std::ios::trunc);
	if (!file.is_open())
	{
		std::cout << "\n\t[-]Файл не открывается!" << std::endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}