#include <stdio.h>
#include "RichBoy.h"
// ��� struct Class
#include "new.h"
#include <string.h>
static char greeting[4] = "Hey";
static char flex1[18] = "I have a supercar";
static char flex2[51] = "Of course, baby. I'm the richest boy in the world!";
#define num(p) ((( struct User *)(p)) -> num)
#define name(p) ((( struct User *)(p)) -> name)
// ���������� ������������ ��� Circle
static void *RichBoy_ctor(void *_self, va_list *app) {
	// ��������� Circle ����������� �� Point, ������ ����� ��
	// �������� ����������� ������ Point, ��������� ��� ���� ���������.
	// ��, ��� �� �����, ����� ������������� � ��������� �� Circle,
	// ������ ��� ���������� ������ ����� ������ sizeof (struct Circle).
	struct RichBoy *self = ((const struct Class *)Boy)->ctor(_self, app);


	// ���������� ��������� �� ������
	return self;
}
static void *RichBoy_dtor(void *_self) {
	((const struct Class *)Boy)->dtor(_self);
}
// ��� ��� ���������������� ������ ��� ������� � ����� �������� ������ Point
// ����������� p � ��������� �� struct Point � ������ ��������������� ����

// ���������� ����������� ������� draw ��� ������ Circle
//#define greeting(p) (((const struct User *)(p)) -> greeting)
static void RichBoy_type(const void * _self, message*mes)
{
	int counter = 0;
	
	// �� �����, ��� ��, ��� ��� ��������, ��� ��������� �� Circle
	const struct RichBoy *self = _self;
	int size = mes->size;
	mes->current += num(self);
	if (mes->lap == 0) {
		printf("%s: ", name(self));
		puts(greeting);
		counter++;
		printf("%s ", name(self));
		puts(flex1);
		counter++;
		message_insert(mes, greeting);
		message_insert(mes, flex1);
	}
	for (int i = mes->current; i < size; i++) {
		if (strstr(mes->log[i], "I want a dress") != NULL) {
			printf("%s: ", name(self));
			puts(flex2);
			counter++;
			message_insert(mes, flex2);
		}
	}
	num(self) = counter;
}

static const struct Class _RichBoy = {
	sizeof(struct RichBoy),
	RichBoy_ctor,
	RichBoy_dtor,
	RichBoy_type
};

const void *RichBoy = &_RichBoy;