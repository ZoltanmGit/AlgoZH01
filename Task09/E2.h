#pragma once
struct E2Key
{
	int code;
	int grade;
	//Date, points etc...
};
class E2
{
public:
	E2();
	E2(const int argcode, const int arggrade);
	E2* _next;
	E2* _prev;
	struct E2Key _key;

	void precede(E2* p, E2* q);
	void follow(E2* q, E2* r);
	void out(E2* q);
};
