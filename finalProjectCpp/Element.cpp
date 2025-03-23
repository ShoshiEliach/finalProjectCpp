#include "Element.h"

Element::Element()
{
}

int Element::getCount1()
{
	return this->count1;
}

int Element::getCount2()
{
	return this->count2;
}

int Element::getCount_element()
{
	return this->count_element;
}

std::string Element::getName1()const
{
	return this->name1;
}

std::string Element::getName2()
{
	return this->name2;
}

std::string Element::getname_element()
{
	return this->name_element;
}

void Element::setCount1(int c)
{
	this->count1 = c;
}

void Element::setCount2(int c)
{
	this->count2 = c;
}

void Element::setCount_element(int c)
{
	this->count_element = c;
}

void Element::setName1(std::string n)
{
	this->name1 = n;
}

void Element::setName2(std::string n)
{
	this->name2 = n;
}

void Element::setName_element(std::string n)
{
	this->name_element = n;
}
