#pragma once
#include<string>

// show_menu- выводим в кансоль 
void show_menu();

// add_note - добавл€ем заметку в качестве 
//параметра в виде ссылки
void add_note(const std::string& new_note);

// see_all_notes - покзать все заметки
void see_all_notes();

//find_one_note - поиск одной заметке
std::string* find_one_note(const std::string& note_to_find, int &n_count);

//¬озврвщает указатель на массив всех заметок
std::string* all_notes(int & n_count);

//”дал€ем одну заметку под индексом choice-1
void remove_one_note(std::string* all_notes_arr,int count, int choice);

//”дал€ет все заметки
void remove_all_notes();