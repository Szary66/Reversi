#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
template<typename T>
class Board{
public:
	Board(size_t w, size_t h, T empty)
		:w(w), h(h){
		/*for(size_t i = 0; i < h; ++i)
			for(size_t j = 0; j < w; ++j)
				_board.push_back(empty);*/
		std::for_each(_board.begin(), _board.end(), [](auto &foo){foo = empty; });
	}
	/*komentarz :D*/
	const size_t w;
	const size_t h;
	
	const T& at(size_t x, size_t y)const{ return _board.at(y*w + x); }
	const T& at(size_t n)const{	return _board.at(n);}

	void set(size_t x, size_t y, const T& field){ _board[y*w + x] = field; }

	void clear(const T& empty){
		//std::for_each(_board.begin(), _board.end(), [&](int& n, const T& empty){ n = empty; }(&, empty));
		for(size_t i = 0; i < _board.size();++i)
			_board[i] =empty;
	}

	bool inline inside(size_t x, size_t y)const{ return (x < w && y < h)?true:false; }

	size_t inline white()const{ return _white; }
	size_t inline black()const{ return _black; }

private:
	std::vector<T> _board;
	size_t _white;
	size_t _black;
};


template<typename T>
void draw(const Board<T>& board){
	//columns number
	std::cout << "  ";
	for(size_t i = 0; i < board.w; ++i){
		if(i < 10)
			std::cout << " ";
		std::cout << i;
	}
	std::cout << std::endl;
	std::cout << "  " << std::setfill('-') << std::setw(board.w * 2 + 2);
	std::cout << "\n";
	//Board
	for(size_t i = 0; i < board.h; ++i){
		//chain number
		if(i < 10)
			std::cout << " ";
		std::cout << i << "|";

		//chain
		for(size_t j = 0; j < board.w; ++j)
			std::cout << board.at(j, i) << "|";
		std::cout << std::endl;

		//horizontal line
		std::cout << "  " << std::setfill('-') << std::setw(board.w * 2 + 2);
		std::cout << "\n";
	}
}




