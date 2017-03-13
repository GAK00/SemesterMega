/*
 * Meme.cpp
 *
 *  Created on: Mar 13, 2017
 *      Author: gkun9931
 */

#include "Meme.hpp"
using namespace std;
Meme::Meme()
    {
	title = "too dank";
	dankness = 0;
	hipsterQuotient = -.9999;
	mainstream = true;

    }
Meme::Meme(string title)
    {
	this->title = title;
	dankness = title.length();
	hipsterQuotient = 3.14;
	mainstream = true;

    }

Meme::~Meme()
    {
    }
string Meme::getTitle()
    {
    return title;
    }
int Meme::getDankness()
    {
    return dankness;
    }
double Meme::getHipsterQuotient()
    {
    return hipsterQuotient;
    }
bool Meme::isMainstream()
    {
    return mainstream;
    }
void Meme:: setTitle(string title)
    {
	this->title = title;
    }
void Meme::setDankness(int dank)
    {
    dankness = dank;
    }
void Meme::setHipsterQuotienet(double hq)
    {
    this->hipsterQuotient = hq;
    }
void Meme::setMainstream(bool main)
    {
    mainstream = main;
    }

