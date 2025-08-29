#include "pch.h"
#include "Submission.cpp"
#include "gtest/gtest.h"
#include <cstring>
using namespace std;

//-------------------Question No 1-----------------

TEST(Question_1, BinaryCheck)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0, 2)));
	ASSERT_EQ(0, strcmp("1", BaseConverter(1, 2)));
	ASSERT_EQ(0, strcmp("110", BaseConverter(6, 2)));
	ASSERT_EQ(0, strcmp("100", BaseConverter(4, 2)));
	ASSERT_EQ(0, strcmp("101", BaseConverter(5, 2)));
	ASSERT_EQ(0, strcmp("111", BaseConverter(7, 2)));
	EXPECT_TRUE(true);
}

TEST(Question_1, BaseThreeCheck)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0, 3)));
	ASSERT_EQ(0, strcmp("1", BaseConverter(1, 3)));
	ASSERT_EQ(0, strcmp("11", BaseConverter(4, 3)));
	ASSERT_EQ(0, strcmp("12", BaseConverter(5, 3)));
	ASSERT_EQ(0, strcmp("20", BaseConverter(6, 3)));
	ASSERT_EQ(0, strcmp("21", BaseConverter(7, 3)));
}

TEST(Question_1, BaseFourCheck)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0, 4)));
	ASSERT_EQ(0, strcmp("1", BaseConverter(1, 4)));
	ASSERT_EQ(0, strcmp("2", BaseConverter(2, 4)));
	ASSERT_EQ(0, strcmp("3", BaseConverter(3, 4)));
	ASSERT_EQ(0, strcmp("10", BaseConverter(4, 4)));
	ASSERT_EQ(0, strcmp("11", BaseConverter(5, 4)));
	ASSERT_EQ(0, strcmp("12", BaseConverter(6, 4)));
	ASSERT_EQ(0, strcmp("32", BaseConverter(14, 4)));
	ASSERT_EQ(0, strcmp("33", BaseConverter(15, 4)));
}

TEST(Question_1, BaseElevenCheck)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0, 11)));
	ASSERT_EQ(0, strcmp("1", BaseConverter(1, 11)));
	ASSERT_EQ(0, strcmp("A", BaseConverter(10, 11)));
	ASSERT_EQ(0, strcmp("10", BaseConverter(11, 11)));
	ASSERT_EQ(0, strcmp("14", BaseConverter(15, 11)));
	ASSERT_EQ(0, strcmp("1A", BaseConverter(21, 11)));
	ASSERT_EQ(0, strcmp("190", BaseConverter(220, 11)));
}

TEST(Question_1, FloatNumberCheckForBaseSixteen)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0.0, 16)));
	ASSERT_EQ(0, strcmp("0.8", BaseConverter(0.5, 16)));
	ASSERT_EQ(0, strcmp("0.4", BaseConverter(0.25, 16)));
	ASSERT_EQ(0, strcmp("0.C", BaseConverter(0.75, 16)));
	ASSERT_EQ(0, strcmp("0.2", BaseConverter(0.125, 16)));
	ASSERT_EQ(0, strcmp("0.A", BaseConverter(0.625, 16)));
	ASSERT_EQ(0, strcmp("0.6", BaseConverter(0.375, 16)));
	ASSERT_EQ(0, strcmp("0.E", BaseConverter(0.875, 16)));
	ASSERT_EQ(0, strcmp("0.1", BaseConverter(0.0625, 16)));
	ASSERT_EQ(0, strcmp("0.9", BaseConverter(0.5625, 16)));
	ASSERT_EQ(0, strcmp("0.5", BaseConverter(0.3125, 16)));
	ASSERT_EQ(0, strcmp("0.D", BaseConverter(0.8125, 16)));
	ASSERT_EQ(0, strcmp("0.3", BaseConverter(0.1875, 16)));
	ASSERT_EQ(0, strcmp("0.B", BaseConverter(0.6875, 16)));
	ASSERT_EQ(0, strcmp("0.7", BaseConverter(0.4375, 16)));
	ASSERT_EQ(0, strcmp("0.F", BaseConverter(0.9375, 16)));
}

TEST(Question_1, BaseSixteenCheck)
{
	ASSERT_EQ(0, strcmp("0", BaseConverter(0, 16)));
	ASSERT_EQ(0, strcmp("1", BaseConverter(1, 16)));
	ASSERT_EQ(0, strcmp("A", BaseConverter(10, 16)));
	ASSERT_EQ(0, strcmp("F", BaseConverter(15, 16)));
	ASSERT_EQ(0, strcmp("10", BaseConverter(16, 16)));
	ASSERT_EQ(0, strcmp("1A", BaseConverter(26, 16)));
	ASSERT_EQ(0, strcmp("1F", BaseConverter(31, 16)));
	ASSERT_EQ(0, strcmp("190", BaseConverter(400, 16)));
}

TEST(Question_1, NegativeNumbersCheckerMixedBases)
{
	ASSERT_EQ(0, strcmp("010", BaseConverter(-6, 2)));
	ASSERT_EQ(0, strcmp("011", BaseConverter(-5, 2)));
	ASSERT_EQ(0, strcmp("0001", BaseConverter(-15, 2)));

	ASSERT_EQ(0, strcmp("11", BaseConverter(-55, 8)));
	ASSERT_EQ(0, strcmp("400", BaseConverter(-256, 8)));
	ASSERT_EQ(0, strcmp("5666", BaseConverter(-1098, 8)));

	ASSERT_EQ(0, strcmp("7", BaseConverter(-9, 16)));
	ASSERT_EQ(0, strcmp("E1", BaseConverter(-31, 16)));
	ASSERT_EQ(0, strcmp("DF", BaseConverter(-33, 16)));
}

//-------------------Question No 2-----------------

TEST(Question_2, insertOpreations)
{
	int totalPages = 0;
	char*** book;
	char text[] = "In a tiny village nestled between rolling hills and babbling brooks, there lived a peculiar cat named Whiskers. Whiskers wasn't your ordinary feline; he had a knack for solving mysteries. One day, the village's prized possession, the Giant Cheese Wheel, went missing.Whiskers, with his magnifying glass in paw and detective hat perched atop his head, embarked on a thrilling quest.His journey took him through meadows and over bridges until he stumbled upon a suspicious trail of cheesy paw prints leading to Farmer Brown's barn. Inside the barn, Whiskers discovered a group of mischievous mice having a cheese feast. Among them was a mouse named Munch, the mastermind behind the cheesy caper. However, instead of scolding them, Whiskers proposed a deal: they could have a cheese party every month as long as they promised not to pilfer the Giant Cheese Wheel.";
	makeBook(text, book, totalPages);

	insert(book, totalPages, 3); // As you will 3 pages in book after makeBook function. Page# are 1,2,3

	char text1[] = "From that day forward, the village enjoyed monthly cheese celebrations, and Whiskers became a hero. As for Munch and his mouse friends, they learned that sometimes, it's better to negotiate than to nibble. And so, peace reigned in the village, thanks to the clever detective work of Whiskers, the cheese-loving cat.";

	insertText(book, totalPages, 4, 1, 0, text1); // 0 means start of the line.

	insert(book, totalPages, 4, 0); // insert empty line at start of the page.

	char ans[] = "---------- Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\njourney took him through meadows and\nover bridges until he stumbled upon a\nsuspicious trail of cheesy paw prints\nleading to Farmer Brown's barn. Inside\nthe barn, Whiskers discovered a group of\nmischievous mice having a cheese feast.\nAmong them was a mouse named Munch, the\nmastermind behind the cheesy caper.\nHowever, instead of scolding them,\nWhiskers proposed a deal: they could\n----------Page 3 ----------\nhave a cheese party every month as long\nas they promised not to pilfer the Giant\nCheese Wheel.\n----------Page 4 ----------\n\nFrom that day forward, the village\nenjoyed monthly cheese celebrations,\nand Whiskers became a hero. As for\nMunch and his mouse friends, they\nlearned that sometimes, it's better to\nnegotiate than to nibble.And so, peace\nreigned in the village, thanks to the\nclever detective work of Whiskers, the\ncheese-loving cat.";

	ASSERT_EQ(0, strcmp(ans, toString(book, totalPages)));
}

TEST(Question_2, deleteOpreations)
{
	int totalPages;
	char*** book;
	char text[] = "In a tiny village nestled between rolling hills and babbling brooks, there lived a peculiar cat named Whiskers.Whiskers wasn't your ordinary feline; he had a knack for solving mysteries. One day, the village's prized possession, the Giant Cheese Wheel, went missing.Whiskers, with his magnifying glass in paw and detective hat perched atop his head, embarked on a thrilling quest.His journey took him through meadows and over bridges until he stumbled upon a suspicious trail of cheesy paw prints leading to Farmer Brown's barn. Inside the barn, Whiskers discovered a group of mischievous mice having a cheese feast. Among them was a mouse named Munch, the mastermind behind the cheesy caper. However, instead of scolding them, Whiskers proposed a deal: they could have a cheese party every month as long as they promised not to pilfer the Giant Cheese Wheel.";
	makeBook(text, book, totalPages);

	Delete(book, totalPages, 2);

	char ans1[] = "---------- Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\nhave a cheese party every month as long\nas they promised not to pilfer the Giant\nCheese Wheel.";

	ASSERT_EQ(2, totalPages);
	ASSERT_EQ(0, strcmp(ans1, toString(book, totalPages)));

	Delete(book, totalPages, 1, 1); // first line of page

	char ans2[] = "---------- Page 1 ----------\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\nhave a cheese party every month as long\n----------Page 2 ----------\nas they promised not to pilfer the Giant\nCheese Wheel.";

	ASSERT_EQ(0, strcmp(ans2, toString(book, totalPages)));

	char text1[] = "Cheese";

	DeleteText(book, totalPages, text1);

	char ans3[] = "---------- Page 1 ----------\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Wheel, went missing. Whiskers,\nwith his magnifying glass in paw and\ndetective hat perched atop his head,\nembarked on a thrilling quest. His have\na party every month as long as they\n---------- Page 2 ----------\npromised not to pilfer the Giant Wheel.";

	ASSERT_EQ(0, strcmp(ans2, toString(book, totalPages)));
}

TEST(Question_2, CutPasteOpreations)
{
	int totalPages;
	char*** book;
	char text[] = "In a tiny village nestled between rolling hills and babbling brooks, there lived a peculiar cat named Whiskers.Whiskers wasn't your ordinary feline; he had a knack for solving mysteries. One day, the village's prized possession, the Giant Cheese Wheel, went missing.Whiskers, with his magnifying glass in paw and detective hat perched atop his head, embarked on a thrilling quest.His journey took him through meadows and over bridges until he stumbled upon a suspicious trail of cheesy paw prints leading to Farmer Brown's barn. Inside the barn, Whiskers discovered a group of mischievous mice having a cheese feast. Among them was a mouse named Munch, the mastermind behind the cheesy caper. However, instead of scolding them, Whiskers proposed a deal: they could have a cheese party every month as long as they promised not to pilfer the Giant Cheese Wheel.";
	makeBook(text, book, totalPages);

	char* clipboard;

	cut(book, totalPages, 2, 3, 2, 2, 0, 7, clipboard); // This will cut from line 2 of page 2 from start to line 1 of page 3 till word 7 (whole line). we will not include line 2 of page 3.

	char ans1[] = "---------- Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\njourney took him through meadows and\nas they promised not to pilfer the Giant\nCheese Wheel.";

	ASSERT_EQ(0, strcmp(ans1, toString(book, totalPages)));

	paste(book, totalPages, clipboard, 2, 3, 2);

	char ans2[] = "----------Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\njourney took him through meadows and as\nthey promised not to pilfer the Giant\nCheese Wheel. over bridges until he\nstumbled upon a suspicious trail of\ncheesy paw prints leading to Farmer\nBrown's barn. Inside the barn, Whiskers\ndiscovered a group of mischievous mice\nhaving a cheese feast. Among them was a\nmouse named Munch, the mastermind behind\nthe cheesy caper. However, instead of\n----------Page 3 ----------\nscolding them, Whiskers proposed a deal:\nthey could have a cheese party every\nmonth as long";

	ASSERT_EQ(0, strcmp(ans2, toString(book, totalPages)));
}

TEST(Question_2, CopyPasteOpreations)
{
	int totalPages;
	char*** book;
	char text[] = "In a tiny village nestled between rolling hills and babbling brooks, there lived a peculiar cat named Whiskers.Whiskers wasn't your ordinary feline; he had a knack for solving mysteries. One day, the village's prized possession, the Giant Cheese Wheel, went missing.Whiskers, with his magnifying glass in paw and detective hat perched atop his head, embarked on a thrilling quest.His journey took him through meadows and over bridges until he stumbled upon a suspicious trail of cheesy paw prints leading to Farmer Brown's barn. Inside the barn, Whiskers discovered a group of mischievous mice having a cheese feast. Among them was a mouse named Munch, the mastermind behind the cheesy caper. However, instead of scolding them, Whiskers proposed a deal: they could have a cheese party every month as long as they promised not to pilfer the Giant Cheese Wheel.";
	makeBook(text, book, totalPages);

	char* clipboard;

	copy(book, totalPages, 2, 3, 2, 2, 0, 7, clipboard); // This will copy from line 2 of page 2 from start to line 1 of page 3 till word 7 (whole line). we will not include line 2 of page 3.

	char ans1[] = "over bridges until he stumbled upon a\nsuspicious trail of cheesy paw prints\nleading to Farmer Brown's barn. Inside\nthe barn, Whiskers discovered a group of\nmischievous mice having a cheese feast.\nAmong them was a mouse named Munch, the\nmastermind behind the cheesy caper.\nHowever, instead of scolding them,\nWhiskers proposed a deal: they could\nhave a cheese party every month as long";

	ASSERT_EQ(0, strcmp(clipboard, ans1));

	paste(book, totalPages, clipboard, 2, 3, 2);

	char ans2[] = "---------- Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\njourney took him through meadows and\nover bridges until he stumbled upon a\nsuspicious trail of cheesy paw prints\nleading to Farmer Brown's barn. Inside\nthe barn, Whiskers discovered a group of\nmischievous mice having a cheese feast.\nAmong them was a mouse named Munch, the\nmastermind behind the cheesy caper.\nHowever, instead of scolding them,\nWhiskers proposed a deal: they could\n----------Page 3 ----------\nhave a cheese party every month as long\nas they promised not to pilfer the Giant\nCheese Wheel. over bridges until he\nstumbled upon a suspicious trail of\ncheesy paw prints leading to Farmer\nBrown's barn. Inside the barn, Whiskers\ndiscovered a group of mischievous mice\nhaving a cheese feast. Among them was a\nmouse named Munch, the mastermind behind\nthe cheesy caper. However, instead of\n----------Page 4 ----------\nscolding them, Whiskers proposed a deal:\nthey could have a cheese party every\nmonth as long";

	ASSERT_EQ(0, strcmp(ans2, toString(book, totalPages)));
}

TEST(Question_2, ConcatenateBooks)
{
	int totalPages1 = 0;
	char*** book1;

	char text[] = "In a tiny village nestled between rolling hills and  babbling brooks, there lived a peculiar cat named Whiskers. Whiskers wasn't your ordinary feline; he had a knack for solving mysteries. One day, the village's prized possession, the Giant Cheese Wheel, went missing.Whiskers, with his magnifying glass in paw and detective hat perched atop his head, embarked on a thrilling quest.His journey took him through meadows and over bridges until he stumbled upon a suspicious trail of cheesy paw prints leading to Farmer Brown's barn. Inside the barn, Whiskers discovered a group of mischievous mice having a cheese feast. Among them was a mouse named Munch, the mastermind behind the cheesy caper. However, instead of scolding them, Whiskers proposed a deal: they could have a cheese party every month as long as they promised not to pilfer the Giant Cheese Wheel.";
	makeBook(text, book1, totalPages1);

	removeDoubleSpaces(book1, totalPages1);

	int totalPages2 = 0;
	char*** book2;

	char text1[] = "From that day forward, the village enjoyed monthly cheese celebrations, and Whiskers became a hero. As for Munch and his mouse friends, they learned that sometimes, it's better to negotiate than to nibble. And so, peace reigned in the village, thanks to the clever detective work of Whiskers, the cheese-loving cat.";

	makeBook(text1, book2, totalPages2);

	int totalPages = 0;
	char*** book;
	concatenateBooks(book1, totalPages1, book2, totalPages2, book, totalPages);

	char ans[] = "---------- Page 1 ----------\nIn a tiny village nestled between\nrolling hills and babbling brooks, there\nlived a peculiar cat named Whiskers.\nWhiskers wasn't your ordinary feline; he\nhad a knack for solving mysteries. One\nday, the village's prized possession,\nthe Giant Cheese Wheel, went missing.\nWhiskers, with his magnifying glass in\npaw and detective hat perched atop his\nhead, embarked on a thrilling quest. His\n----------Page 2 ----------\njourney took him through meadows and\nover bridges until he stumbled upon a\nsuspicious trail of cheesy paw prints\nleading to Farmer Brown's barn. Inside\nthe barn, Whiskers discovered a group of\nmischievous mice having a cheese feast.\nAmong them was a mouse named Munch, the\nmastermind behind the cheesy caper.\nHowever, instead of scolding them,\nWhiskers proposed a deal: they could\n----------Page 3 ----------\nhave a cheese party every month as long\nas they promised not to pilfer the Giant\nCheese Wheel.\n----------Page 4 ----------\n\nFrom that day forward, the village\nenjoyed monthly cheese celebrations,\nand Whiskers became a hero. As for\nMunch and his mouse friends, they\nlearned that sometimes, it's better to\nnegotiate than to nibble.And so, peace\nreigned in the village, thanks to the\nclever detective work of Whiskers, the\ncheese-loving cat.";

	ASSERT_EQ(0, strcmp(ans, toString(book, totalPages)));
}

//-------------------Question No 3-----------------

bool isSafe(int** board, int row, int col, int queens)
{

	for (int i = 0; i < col; ++i)
		if (board[row][i] == 1)
			return false;

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
		if (board[i][j] == 1)
			return false;

	for (int i = row + 1, j = col - 1; i < queens && j >= 0; ++i, --j)
		if (board[i][j] == 1)
			return false;

	return true;
}

bool isvalid(int**& board, int queens)
{

	for (int i = 0; i < queens; ++i)
		for (int j = 0; j < queens; ++j)
		{
			if (board[i][j] == 1)
				if (!isSafe(board, i, j, queens))
				{
					return false;
				}
		}
	return true;
}

TEST(Question_3, 5queens)
{

	int queens = 5;

	int** board = new int* [queens];
	for (int i = 0; i < queens; ++i)
	{
		board[i] = new int[queens]();
	}

	royalHarmony(board, 0, 0, queens);

	ASSERT_EQ(true, isvalid(board, queens));
}

//-------------------Question No 5-----------------

TEST(Q5, first)
{

	char name[] = "George";

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;

	OpenCustomerAccount(saver, accountsOpen, name, 10, 100);

	ASSERT_EQ(0, strcmp(name, saver[accountsOpen - 1]->name));
	ASSERT_EQ(100, saver[accountsOpen - 1]->savingBalance);
}

TEST(Q5, second)
{

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;

	for (int i = 0; i < 100; i++)
	{
		OpenCustomerAccount(saver, accountsOpen, "Jhon", 10, i);
	}

	ASSERT_EQ(0, strcmp("Jhon", saver[accountsOpen - 1]->name));
	ASSERT_EQ(99, saver[accountsOpen - 1]->savingBalance);
}

TEST(Q5, third)
{
	SavingAccount saver;
	saver.name = "Tara";
	saver.annualInterestRate = 10;
	saver.savingBalance = 24;
	saver.accountNum = "SA00";

	ASSERT_EQ(20.0, calculateMonthlyInterest(&saver));
}

TEST(Q5, fourth)
{
	SavingAccount saver;
	saver.name = "Jhon";
	saver.annualInterestRate = 10;
	saver.savingBalance = 24;
	saver.accountNum = "SA00";

	modifyInterestRate(&saver, 5);

	ASSERT_EQ(5, saver.annualInterestRate);
	ASSERT_EQ(10.0, calculateMonthlyInterest(&saver));
}

TEST(Q5, fifth)
{

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;
	for (int i = 0; i < 100; i++)
	{
		OpenCustomerAccount(saver, accountsOpen, "jhon", 10, i);
	}

	ASSERT_EQ(-1, SearchCustomer(saver, accountsOpen - 1, "101"));
	ASSERT_EQ(0, SearchCustomer(saver, accountsOpen - 1, "90"));
}

TEST(Q5, sixth)
{

	SavingAccount s1, s2, s3, s4;
	s1.name = "Musa";
	s1.annualInterestRate = 10;
	s1.savingBalance = 24;
	s1.accountNum = "SA00";

	s2.name = "Ali";
	s2.annualInterestRate = 15;
	s2.savingBalance = 30;
	s2.accountNum = "SA01";

	s3.name = "Ahmed";
	s3.annualInterestRate = 20;
	s3.savingBalance = 50;
	s3.accountNum = "SA02";

	s4.name = "Eshal";
	s4.annualInterestRate = 10;
	s4.savingBalance = 70;
	s4.accountNum = "SA03";

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 4;

	saver[0] = &s1;
	saver[1] = &s2;
	saver[2] = &s3;
	saver[3] = &s4;

	ASSERT_EQ(70, s4.savingBalance);
	UpdateAccountBalance(saver, accountsOpen - 1, "03", 100);
	ASSERT_EQ(100, s4.savingBalance);
}

//-------------------Question No 4-----------------

TEST(Question4, Pattren)
{
	RecursivePattern1(1, 14);

	RecursivePattern2(7, 7);

	RecursivePattern3(7, 7);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}