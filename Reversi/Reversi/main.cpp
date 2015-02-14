#include "Board.h"

int main(){
	Board<char> board(5, 5, 'X');
	draw<char>(board);

	board.clear(' ');
	draw<char>(board);



	system("pause");
	return 0;
}