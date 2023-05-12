// ToDoList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale.h> 
#include "windows.h"
#include "List.h" //Подключаем заголовочный файл 

enum CHOICE
{
 ADD_NOTE = 1,
 SEE_ALL_NOTES,
 FIND_ONE_NOTE,
 REMOVE_ONE_NOTE,
 REMOVE_ALL_NOTES
};

int main()
{
    system("Color E1"); // Выбор цвета консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    while (true) 
    {
    system("cls");
    show_menu();
    cout << "\n\tВаш выбор: ";
    int choice = 0;
    cin >> choice;
    if (choice == ADD_NOTE)
    {
    system("cls");

    string new_note;
    getline(cin, new_note);
    cout << "\n\tДобавьте название задачи," << endl;
    cout << "\n\tприоритет от 1 до 10," << endl;
    cout << "\n\tописание,время исполнения и" << endl;
    cout << "\n\tдату исполнения (Через запятую)" << endl;
    cout << "\n\t"; getline(cin, new_note);
    cout << "\n\t"; add_note(new_note);
   
            
    system("pause");
    }
    else if (choice == SEE_ALL_NOTES)
    {
    system("cls");
    see_all_notes();
    system("pause");
    }
    else if (choice == FIND_ONE_NOTE){
    system("cls");
    string note_to_find;
    getline(cin, note_to_find);
    cout << "\n\tВведите параметр поиска "<<endl;
    cout << "\n\tНазвание, приоритет от 1 до 10, описание, дата или время" << endl;
    cout << "\n\t"; getline(cin, note_to_find);

    int n_found=0;
    string* found_notes = find_one_note(note_to_find, n_found);

    if (found_notes)
    {
    cout << "\n\tНайденные задачи: " << endl;
    for (int i = 0; i < n_found; i++)
    cout << found_notes [i]<< endl;

    delete [] found_notes;
    }
    else
    {
    cout << "\n\tТакой записки нет!" << endl;
    }
    system("pause");
    }
    else if (choice == REMOVE_ONE_NOTE)
    {
    system("cls");
           
    //Получаем все заметки
    int count = 0;
    string* all_notes_arr = all_notes(count);

    //Выводим их в консоль
    cout << "\n\tВсе задачи:" << endl;
    for (int i = 0; i < count; i++)
    cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;

    cout << "\n\tНомер задачи которую нужно удалить:";
    int choice = 0;
    cin >> choice;
    cout << "\n\t"; remove_one_note(all_notes_arr,count, choice);
    cout << "\n\tВаша задача удалена! ";

    delete [] all_notes_arr;
    system("pause");
    }
    else if (choice == REMOVE_ALL_NOTES){
    system("cls");
    cout << "\n\t"; remove_all_notes();
    cout << "\n\tВсе задачи удалены! " << endl;
    system("pause");
    }
    else
    exit(0);
    }
}

 
