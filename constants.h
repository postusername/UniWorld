//���� �������� ��������
//
#include <iostream>

#ifndef CONSTANTS_H
#define CONSTANTS_H

//Global constants
constexpr auto SCREEN_WIDTH  = 640;
constexpr auto SCREEN_HEIGHT = 480;
constexpr auto WORLD_WIDTH = SCREEN_WIDTH / 2;
constexpr auto WORLD_HEIGHT = SCREEN_HEIGHT / 2;
constexpr auto BOTS_MAX = WORLD_WIDTH * WORLD_HEIGHT;

//Bot constants
constexpr auto DNA_SIZE = 256;
constexpr auto DNA_MAX_INDEX = DNA_SIZE - 1;
constexpr auto SUB_SIZE = 8;
constexpr auto SUB_MAX_INDEX = SUB_SIZE - 1;
enum cond {organic_hold = 1, organic_sink, alive, input };
enum drct : unsigned short { upper_left, up = 1, upper_right, right = 3, bottom_right, down = 5, bottom_left, left = 7 };

//Navigation constants
constexpr auto empty = 0;
constexpr auto wall = BOTS_MAX + 10000;
constexpr auto MAX_X = WORLD_WIDTH - 1;
constexpr auto MAX_Y = WORLD_HEIGHT - 1;

#pragma warning(disable : 4996)
#define srand(); 	/* �������� ������� ����� ��� ��������� ����������.*/ /* ! ����� ������ � �������������� */ struct tm *st; const time_t timer = time(NULL); st = localtime(&timer); /* ������� ������� � ������� */ int rnd_seed = 3600 * st->tm_hour + 60 * st->tm_min + st->tm_sec; srand(rnd_seed);

//������� ������ ���������� ����� � �������� ���������
inline int getRandomNumber(int min, int max) {
	//����� �������� ������� srand();

	if (min < 0) //�������� ���������� ��� ��������� ����������� �����
	{
		std::cout << std::endl << __LINE__ << "|" << "	getRandomNumber():������� ��������� ������ ����� ���������" << std::endl;
		system("exit");
	}

	if (max > RAND_MAX) //�������� ���������� ��� ���������� RAND_MAX
	{
		std::cout << std::endl << __LINE__ << "|" << "	getRandomNumber():�������� ������������ ����� ���������" << std::endl;
		system("exit");
	}

	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	//���������� ������������ ��������� ����� � ����� ���������
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

#endif //CONSTANTS_H