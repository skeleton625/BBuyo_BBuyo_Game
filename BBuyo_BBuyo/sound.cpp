#include "sound.h"
#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int sound::file_count = 0;
string* sound::break_file;
string* sound::cast_file;
string sound::move_file;

sound::sound(string* _break, string* _cast, string _move, int s)
{
	this->file_count = s;
	this->break_file = _break;
	this->cast_file = _cast;
	this->move_file = _move;
}

void sound::play_break_sound(int _num)
{
	if (_num > file_count)
		_num = file_count-1;

	PlaySound(break_file[_num].c_str(), NULL, SND_FILENAME);
	PlaySound(cast_file[_num].c_str(), NULL, SND_FILENAME);
}

void sound::play_move_sound()
{
	PlaySound(move_file.c_str(), NULL, SND_FILENAME);
}