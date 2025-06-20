#include <iostream>

using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissor = 3 };

enum enWinner { Usir = 1, Computer = 2, Draw = 3 };

struct stRound {
	short round;
	enChoice usirChoice;
	enChoice computerChoice;
	enWinner winner;
	string winnerName;
};

struct stGame {
	short round;
	short usirWon;
	short computerWon;
	short draw;
	enWinner winner;
	string winnerName;
};


short RoundsNum() {
	short num;
	do {
		cout << "Please Enter How many round you want (1-10)? :";
		cin >> num;
	} while (num < 1 || num >10);
	return num;
}

string ChoiceName(short num) {
	string names[3] = { "Rock", "Papper", "Scissor" };
	return names[num - 1];
}

string WinnerName(enWinner winner) {
	string names[3] = { "Player", "Computer", "Draw" };
	return names[winner - 1];
}

int RandomNumber(short from, short to) {
	return rand() % (to - from + 1) + from;
}

enChoice UsirChoice() {
	short choice;
	do {
		cout << "\nYour choice: [1]Stone [2]Paper [3]Scissors ? ";
		cin >> choice;
	} while (choice < 1 || choice >3);

	return (enChoice)choice;
}

enChoice ComputerChoice() {
	return (enChoice)RandomNumber(1, 3);
}

enWinner WhoWonRound(stRound RS) {

	if (RS.computerChoice == RS.usirChoice) {
		return enWinner::Draw;
	}

	switch (RS.computerChoice) {
	case enChoice::Rock:
		if (RS.usirChoice == enChoice::Scissor) {
			return enWinner::Computer;
		}
		break;

	case enChoice::Paper:
		if (RS.usirChoice == enChoice::Rock) {
			return enWinner::Computer;
		}
		break;

	case enChoice::Scissor:
		if (RS.usirChoice == enChoice::Paper) {
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Usir;
}

void SetWinnerScreen(enWinner winner) {

	switch (winner) {
	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	case enWinner::Usir:
		system("color 2F");
		break;

	default:
		system("color 6F");
		break;
	}

}

void PrintRoundRes(stRound RS) {
	cout << "\n______________Round [" << RS.round << "]______________\n\n";
	cout << "Player1 Choice: " << ChoiceName(RS.usirChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RS.computerChoice) << endl;
	cout << "Round Winner: " << RS.winnerName << endl;
	cout << "_____________________________________\n" << endl;

	SetWinnerScreen(RS.winner);

}

enWinner WhoWonGame(short comp, short usir) {
	if (usir == comp) {
		return enWinner::Draw;
	}
	else if (usir > comp) {
		return enWinner::Usir;
	}
	else
		return enWinner::Computer;
}

stGame FillGameRes(short round, short usirW, short compW, short Draw) {
	stGame GR;

	GR.round = round;
	GR.computerWon = compW;
	GR.usirWon = usirW;
	GR.draw = Draw;
	GR.winner = WhoWonGame(GR.computerWon, GR.usirWon);
	GR.winnerName = WinnerName(GR.winner);

	return GR;
}

stGame PlayGame(short num) {

	stRound RoundInfo;
	int playerWin = 0, computerWin = 0, Draw = 0;
	cout << endl << endl;
	for (int i = 1; i <= num; i++) {
		cout << "Round [" << i << "] begins\n";
		RoundInfo.round = num;
		RoundInfo.usirChoice = UsirChoice();
		RoundInfo.computerChoice = ComputerChoice();
		RoundInfo.winner = WhoWonRound(RoundInfo);
		RoundInfo.winnerName = WinnerName(RoundInfo.winner);

		if (RoundInfo.winner == enWinner::Computer) {
			computerWin++;
		}
		else if (RoundInfo.winner == enWinner::Usir) {
			playerWin++;
		}
		else
			Draw++;

		PrintRoundRes(RoundInfo);

	}

	return FillGameRes(num, playerWin, computerWin, Draw);

}

void setDefaultScreen() {
	system("cls");
	system("color 0F");
}

string Taps(short num) {
	string t = "";
	for (int i = 1; i < num; i++) {
		t += '\t';
		cout << t;
	}
	return t;
}

void ShowGameOverScreen() {
	cout << Taps(2) << "________________________________________________________________________\n\n";
	cout << Taps(2) << "                      +++ G a m e  O v e r +++\n";
	cout << Taps(2) << "________________________________________________________________________\n\n";
}

void ShowFinalGameRes(stGame GameRes) {
	cout << Taps(2) << "__________________________ [Game Results] __________________________\n\n";
	cout << Taps(2) << "Game Rounds: " << GameRes.round << endl;
	cout << Taps(2) << "Player Won Times: " << GameRes.usirWon << endl;
	cout << Taps(2) << "Computer Won Times: " << GameRes.computerWon << endl;
	cout << Taps(2) << "Draw Times: " << GameRes.draw << endl;
	cout << Taps(2) << "Final Winner: " << GameRes.winnerName << endl;
	cout << Taps(2) << "_____________________________________________________________________\n\n";

	SetWinnerScreen(GameRes.winner);
}

void StartGame() {

	char play = 'Y';

	do {

		setDefaultScreen();
		stGame GameResults = PlayGame(RoundsNum());
		ShowGameOverScreen();
		ShowFinalGameRes(GameResults);

		cout << endl << Taps(3) << "Do you want to play again? Y/N? ";
		cin >> play;
		cout << endl;

	} while (play == 'Y' || play == 'y');

}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

}
