/*
 * main.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include "Human.h"
#include "Man.h"
#include "Woman.h"
#include "FineryDecorator.h"
#include "TShirt.h"
#include "BigTrouser.h"
#include "Suit.h"
#include "Necktie.h"


int main()
{
	Human* pman = new Man();
	FineryDecorator* pTShirt = new TShirt();
	FineryDecorator* pNecktie = new Necktie();
	FineryDecorator* pSuit = new Suit();
	FineryDecorator* pBigTrouser = new BigTrouser();

	pTShirt->Decorate(pman);
	pNecktie->Decorate(pTShirt);
	pSuit->Decorate(pNecktie);
	pBigTrouser->Decorate(pSuit);

	pBigTrouser->Show();

	return 0;
}


