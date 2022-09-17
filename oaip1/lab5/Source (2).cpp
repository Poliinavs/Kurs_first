#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <string.h>

struct Notebook {
	char FIO[64], adress[30], work_or_study[30], mobile[30];
	int birthday;
};

int checker_word(char buff[256], char word[256]) {
	int checker = 1, checkpoint = strlen(word);
	for (int a = 1, b = 1; a < 256; a++) {
		if (word[b] == buff[a]) {
			checker++;
			b++;
		}
		if (buff[a] != word[b - 1] and a > 1) {
			b = 1;
		}
		if (checker == checkpoint) {
			return true;
		}
		else if (a == strlen(buff)) {
			return false;
		}

	}
}

void main() {

	Notebook notebook[4];

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	int const_size = 4;
	int rows = 0, size = const_size, choice, c = 0, string_longest, space = 0, symbol_counter = 0;
	char buff[256], buff2[50], search[30], conversionstring[8];
	bool learn_checker[5] = { false };

	std::ofstream fout;
	std::ifstream fin;
	for (;;) {
		system("pause");
		system("cls");
		SetConsoleTextAttribute(console, 3);
		std::cout << "Interface\n1)Input\n2)Deleting\n3)Save Information\n4)Read Information\n5)Find Information\n6)Exit" << std::endl;
		SetConsoleTextAttribute(console, 10);
		do {
			std::cin >> c;
			if (c > 6 || c < 0 || c == NULL) {
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // удаляем все
				SetConsoleTextAttribute(console, 12);
				std::cout << std::endl << "Input again" << std::endl;
				SetConsoleTextAttribute(console, 15);
				c = NULL;
			}
		} while (c == NULL);

		switch (c) {

		case 1:
			for (int i = 0; i < const_size; i++) {
				SetConsoleTextAttribute(console, 10);
				std::cout << "People Number: " << i + 1 << std::endl;
				SetConsoleTextAttribute(console, 15);
				std::cout << "Input FIO: "; std::cin >> notebook[i].FIO;
				std::cout << "Input adress: ";	std::cin >> notebook[i].adress;
				std::cout << "Input place of work or study : "; std::cin >> notebook[i].work_or_study;
				std::cout << "Input Mobile number: "; std::cin >> notebook[i].mobile;
				std::cout << "Input birthday: ";	std::cin >> notebook[i].birthday;
			}
			break;

		case 2:
			do {
				std::cout << "What are we deleting? : ";
				std::cin >> choice;
				if (choice > const_size || choice == NULL) {
					std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
					std::cin.ignore(32767, '\n'); // удаляем все
					SetConsoleTextAttribute(console, 12);
					std::cout << std::endl << "Input again" << std::endl;
					SetConsoleTextAttribute(console, 15);
					choice = NULL;
				}
				else {
					for (int de1 = (choice - 1); de1 < const_size; de1++)
						notebook[de1] = notebook[de1 + 1];
					size--;
				}
			} while (choice == NULL);	break;

		case 3:
			fout.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				fout << notebook[i].FIO << " " << notebook[i].adress << " " << notebook[i].work_or_study << " " << notebook[i].mobile << " " << notebook[i].birthday << '\n';
			}
			fout.close(); break;

		case 4:
			fin.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				learn_checker[0] = false;
				learn_checker[1] = false;
				learn_checker[2] = false;
				learn_checker[3] = false;
				learn_checker[4] = false;
				fin.getline(buff, 256, '\n');
				string_longest = strlen(buff);
				for (int j = 0; j <= string_longest; j++) {
					if (buff[j] == ' ')
						space++;
					if (space == 1 && learn_checker[0] == false) {
						strncpy_s(notebook[i].FIO, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
						std::cout << notebook[i].FIO << " ";
					}
					if (space == 2 && learn_checker[1] == false) {
						strncpy_s(notebook[i].adress, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
						std::cout << notebook[i].adress << " ";
					}
					if (space == 3 && learn_checker[2] == false) {
						strncpy_s(notebook[i].work_or_study, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[2] = true;
						symbol_counter = 0;
						std::cout << notebook[i].work_or_study << " ";
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(notebook[i].mobile, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[3] = true;
						symbol_counter = 0;
						std::cout << notebook[i].mobile << " ";
					}
					if (buff[j] == '\0' && learn_checker[4] == false) {
						char intbuffer[12];
						strncpy_s(intbuffer, &buff[j - symbol_counter + 1], symbol_counter);
						notebook[i].birthday = atoi(intbuffer); // atoi - преобразование строкового числа в инт число
						learn_checker[4] = true;
						symbol_counter = 0;
						std::cout << notebook[i].birthday << std::endl;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fout.close();	break;

		case 5:
			fin.open("FILE1.txt");
			std::cout << "Input info: ";
			std::cin >> search;
			for (int i = 0; i < size; i++) {
				fin.getline(buff, 256, '\n');
				if (checker_word(buff, search) == true) {
					std::cout << notebook[i].FIO << " ";
					std::cout << notebook[i].adress << " ";
					std::cout << notebook[i].work_or_study << " ";
					std::cout << notebook[i].mobile << " ";
					std::cout << notebook[i].birthday << std::endl;
				}
			}
			fin.close();
			break;

		case 6:
			exit(0);
		}
	}
}