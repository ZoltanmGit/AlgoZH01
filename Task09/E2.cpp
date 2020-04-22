#include "E2.h"
E2::E2()
{
	_prev = this;
	_next = this;
}

E2::E2(const int argcode, const int arggrade)
{
	_prev = this;
	_next = this;

	_key.code = argcode;
	_key.grade = arggrade;
}

void E2::precede(E2* q, E2* r)
{
	E2* p = r->_prev;
	q->_prev = p;
	q->_next = r;
	p->_next = q;
	r->_prev = q;
}

void E2::follow(E2* p, E2* q)
{
	E2* r = p->_next;
	q->_prev = p;
	q->_next = r;
	p->_next = q;
	r->_prev = q;
}

void E2::out(E2* q)
{
	E2* p = q->_prev;
	E2* r = q->_next;

	p->_next = r;
	r->_prev = p;
	q->_prev = q;
	q->_next = q;
}
