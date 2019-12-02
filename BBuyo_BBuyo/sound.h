#pragma once
#include <string>
using namespace std;

class sound
{
private:
	static int file_count;
	static string* break_file;
	static string* cast_file;
	static string move_file;
public:
	sound(string* _break, string* _cast, string _move, int s);
	static void play_break_sound(int _num);
	static void play_move_sound();
};