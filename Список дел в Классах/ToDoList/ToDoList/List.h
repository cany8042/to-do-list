#pragma once
#include<string>

// show_menu- ������� � ������� 
void show_menu();

// add_note - ��������� ������� � �������� 
//��������� � ���� ������
void add_note(const std::string& new_note);

// see_all_notes - ������� ��� �������
void see_all_notes();

//find_one_note - ����� ����� �������
std::string* find_one_note(const std::string& note_to_find, int &n_count);

//���������� ��������� �� ������ ���� �������
std::string* all_notes(int & n_count);

//������� ���� ������� ��� �������� choice-1
void remove_one_note(std::string* all_notes_arr,int count, int choice);

//������� ��� �������
void remove_all_notes();