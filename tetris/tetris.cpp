#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <map>

#define width 22
#define height 20

using namespace std;

struct Position {
	int pos_x;
	int pos_y;
	char body;

	Position(int x, int y, char body) {
		this->pos_x = x;
		this->pos_y = y;
		this->body = body;
	}
};

//max 4x4
struct ShapePosition {
	vector<Position> position;
	vector<Position> pivot;
	int shapeCode;

	ShapePosition() {
		srand(time(NULL));
		int currentShapeCode = rand() % 7 + 1;
		this->shapeCode = currentShapeCode;

		if (currentShapeCode == 1) {
			Position* leftTop1 = new Position(width / 2 - 1, -2, '[');
			Position* leftTop2 = new Position(width / 2, -2, ']');
			Position* rightTop1 = new Position(width / 2 + 1, -2, '[');
			Position* rightTop2 = new Position(width / 2 + 2, -2, ']');
			Position* leftBot1 = new Position(width / 2 - 1, -1, '[');
			Position* leftBot2 = new Position(width / 2, -1, ']');
			Position* rightBot1 = new Position(width / 2 + 1, -1, '[');
			Position* rightBot2 = new Position(width / 2 + 2, -1, ']');

			this->position.push_back(*leftTop1);
			this->position.push_back(*leftTop2);
			this->position.push_back(*rightTop1);
			this->position.push_back(*rightTop2);
			this->position.push_back(*leftBot1);
			this->position.push_back(*leftBot2);
			this->position.push_back(*rightBot1);
			this->position.push_back(*rightBot2);

			//no pivot
		}
		else if (currentShapeCode == 2) {
			Position* bodyTop1 = new Position(width / 2 - 1, -4, '[');
			Position* bodyTop2 = new Position(width / 2, -4, ']');
			Position* bodySecond1 = new Position(width / 2 - 1, -3, '[');
			Position* bodySecond2 = new Position(width / 2, -3, ']');
			Position* bodyThird1 = new Position(width / 2 - 1, -2, '[');
			Position* bodyThird2 = new Position(width / 2, -2, ']');
			Position* bodyLast1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyLast2 = new Position(width / 2, -1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodySecond1);
			this->position.push_back(*bodySecond2);
			this->position.push_back(*bodyThird1);
			this->position.push_back(*bodyThird2);
			this->position.push_back(*bodyLast1);
			this->position.push_back(*bodyLast2);

			//  []
			//  []	
			//  []	<- pivot
			//  []
			this->pivot.push_back(*bodyThird1);
			this->pivot.push_back(*bodyThird2);
		}
		else if (currentShapeCode == 3) {
			Position* bodyTop1 = new Position(width / 2 - 1, -2, '[');
			Position* bodyTop2 = new Position(width / 2, -2, ']');
			Position* bodyBottomLeft1 = new Position(width / 2 - 3, -1, '[');
			Position* bodyBottomLeft2 = new Position(width / 2 - 2, -1, ']');
			Position* bodyBottomMid1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyBottomMid2 = new Position(width / 2, -1, ']');
			Position* bodyBottomRight1 = new Position(width / 2 + 1, -1, '[');
			Position* bodyBottomRight2 = new Position(width / 2 + 2, -1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomMid1);
			this->position.push_back(*bodyBottomMid2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//    []
			//  [][][]
			//    ^
			//  pivot
			this->pivot.push_back(*bodyBottomMid1);
			this->pivot.push_back(*bodyBottomMid2);
		}
		else if (currentShapeCode == 4) {
			Position* bodyTopLeft1 = new Position(width / 2 - 1, -2, '[');
			Position* bodyTopLeft2 = new Position(width / 2, -2, ']');
			Position* bodyTopRight1 = new Position(width / 2 + 1, -2, '[');
			Position* bodyTopRight2 = new Position(width / 2 + 2, -2, ']');
			Position* bodyBottomLeft1 = new Position(width / 2 - 3, -1, '[');
			Position* bodyBottomLeft2 = new Position(width / 2 - 2, -1, ']');
			Position* bodyBottomRight1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyBottomRight2 = new Position(width / 2, -1, ']');

			this->position.push_back(*bodyTopLeft1);
			this->position.push_back(*bodyTopLeft2);
			this->position.push_back(*bodyTopRight1);
			this->position.push_back(*bodyTopRight2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//    [][]
			//  [][]
			//    ^
			//   pivot
			this->pivot.push_back(*bodyBottomRight1);
			this->pivot.push_back(*bodyBottomRight2);
		}
		else if (currentShapeCode == 5) {
			Position* bodyTopLeft1 = new Position(width / 2 - 3, -2, '[');
			Position* bodyTopLeft2 = new Position(width / 2 - 2, -2, ']');
			Position* bodyTopRight1 = new Position(width / 2 - 1, -2, '[');
			Position* bodyTopRight2 = new Position(width / 2, -2, ']');
			Position* bodyBottomLeft1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyBottomLeft2 = new Position(width / 2, -1, ']');
			Position* bodyBottomRight1 = new Position(width / 2 + 1, -1, '[');
			Position* bodyBottomRight2 = new Position(width / 2 + 2, -1, ']');

			this->position.push_back(*bodyTopLeft1);
			this->position.push_back(*bodyTopLeft2);
			this->position.push_back(*bodyTopRight1);
			this->position.push_back(*bodyTopRight2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//  [][]
			//    [][]
			//    ^
			//  pivot
			this->pivot.push_back(*bodyBottomLeft1);
			this->pivot.push_back(*bodyBottomLeft2);
		}
		else if (currentShapeCode == 6) {
			Position* bodyTop1 = new Position(width / 2 - 3, -2, '[');
			Position* bodyTop2 = new Position(width / 2 - 2, -2, ']');
			Position* bodyBottomLeft1 = new Position(width / 2 - 3, -1, '[');
			Position* bodyBottomLeft2 = new Position(width / 2 - 2, -1, ']');
			Position* bodyBottomMid1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyBottomMid2 = new Position(width / 2, -1, ']');
			Position* bodyBottomRight1 = new Position(width / 2 + 1, -1, '[');
			Position* bodyBottomRight2 = new Position(width / 2 + 2, -1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomMid1);
			this->position.push_back(*bodyBottomMid2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//  []
			//  [][][]
			//    ^
			//  pivot
			this->pivot.push_back(*bodyBottomMid1);
			this->pivot.push_back(*bodyBottomMid2);
		}
		else if (currentShapeCode == 7) {
			Position* bodyTop1 = new Position(width / 2 + 1, -2, '[');
			Position* bodyTop2 = new Position(width / 2 + 2, -2, ']');
			Position* bodyBottomLeft1 = new Position(width / 2 - 3, -1, '[');
			Position* bodyBottomLeft2 = new Position(width / 2 - 2, -1, ']');
			Position* bodyBottomMid1 = new Position(width / 2 - 1, -1, '[');
			Position* bodyBottomMid2 = new Position(width / 2, -1, ']');
			Position* bodyBottomRight1 = new Position(width / 2 + 1, -1, '[');
			Position* bodyBottomRight2 = new Position(width / 2 + 2, -1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomMid1);
			this->position.push_back(*bodyBottomMid2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//      []
			//  [][][]
			//    ^
			//  pivot
			this->pivot.push_back(*bodyBottomMid1);
			this->pivot.push_back(*bodyBottomMid2);
		}
	}
};

struct Rotate {
	vector<Position> position;
	vector<Position> pivot;
	int shapeCode;

	Rotate(ShapePosition* sp) {

		if (sp->shapeCode == 1) {
			//remain
			this->shapeCode = sp->shapeCode;
			this->position = sp->position;
		}
		else if (sp->shapeCode == 2) {
			this->shapeCode = 8;

			Position* bodyFirst1 = new Position(sp->pivot[0].pos_x - 4, sp->pivot[0].pos_y, '[');
			Position* bodyFirst2 = new Position(sp->pivot[0].pos_x - 3, sp->pivot[0].pos_y, ']');
			Position* bodySecond1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodySecond2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyThird1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyThird2 = new Position(sp->pivot[0].pos_x + 1, sp->pivot[0].pos_y, ']');
			Position* bodyLast1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyLast2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');

			this->position.push_back(*bodyFirst1);
			this->position.push_back(*bodyFirst2);
			this->position.push_back(*bodySecond1);
			this->position.push_back(*bodySecond2);
			this->position.push_back(*bodyThird1);
			this->position.push_back(*bodyThird2);
			this->position.push_back(*bodyLast1);
			this->position.push_back(*bodyLast2);

			//  [][][][]
			//      ^
			//     pivot
			this->pivot.push_back(*bodyThird1);
			this->pivot.push_back(*bodyThird2);
		}
		else if (sp->shapeCode == 8) {
			this->shapeCode = 2;

			Position* bodyFirst1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 2, '[');
			Position* bodyFirst2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 2, ']');
			Position* bodySecond1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodySecond2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 1, ']');
			Position* bodyThird1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyThird2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyLast1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyLast2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y + 1, ']');

			this->position.push_back(*bodyFirst1);
			this->position.push_back(*bodyFirst2);
			this->position.push_back(*bodySecond1);
			this->position.push_back(*bodySecond2);
			this->position.push_back(*bodyThird1);
			this->position.push_back(*bodyThird2);
			this->position.push_back(*bodyLast1);
			this->position.push_back(*bodyLast2);

			//  []
			//  []
			//  []	<- pivot
			//  []
			this->pivot.push_back(*bodyThird1);
			this->pivot.push_back(*bodyThird2);
		}
		else if (sp->shapeCode == 3) {
			this->shapeCode = 9;

			Position* bodyTop1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTop2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 1, ']');
			Position* bodyMidLeft1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyMidLeft2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyMidRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyMidRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');
			Position* bodyBottom1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyBottom2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y + 1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyMidLeft1);
			this->position.push_back(*bodyMidLeft2);
			this->position.push_back(*bodyMidRight1);
			this->position.push_back(*bodyMidRight2);
			this->position.push_back(*bodyBottom1);
			this->position.push_back(*bodyBottom2);

			//           []
			//  pivot -> [][]
			//           []
			this->pivot.push_back(*bodyMidLeft1);
			this->pivot.push_back(*bodyMidLeft2);
		}
		else if (sp->shapeCode == 9) {
			this->shapeCode = 10;

			Position* bodyTopLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodyTopLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyTopMid1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyTopMid2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyTopRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyTopRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');
			Position* bodyBottom1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyBottom2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y + 1, ']');

			this->position.push_back(*bodyTopLeft1);
			this->position.push_back(*bodyTopLeft2);
			this->position.push_back(*bodyTopMid1);
			this->position.push_back(*bodyTopMid2);
			this->position.push_back(*bodyTopRight1);
			this->position.push_back(*bodyTopRight2);
			this->position.push_back(*bodyBottom1);
			this->position.push_back(*bodyBottom2);

			//    p
			//  [][][]
			//    []
			this->pivot.push_back(*bodyTopMid1);
			this->pivot.push_back(*bodyTopMid2);
		}
		else if (sp->shapeCode == 10) {
			this->shapeCode = 11;

			Position* bodyTop1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTop2 = new Position(sp->pivot[0].pos_x + 1, sp->pivot[0].pos_y - 1, ']');
			Position* bodyMidLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodyMidLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyMidRight1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyMidRight2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyBottom1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyBottom2 = new Position(sp->pivot[0].pos_x + 1, sp->pivot[0].pos_y + 1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyMidLeft1);
			this->position.push_back(*bodyMidLeft2);
			this->position.push_back(*bodyMidRight1);
			this->position.push_back(*bodyMidRight2);
			this->position.push_back(*bodyBottom1);
			this->position.push_back(*bodyBottom2);

			//    []
			//  [][] <- pivot
			//    []
			this->pivot.push_back(*bodyMidRight1);
			this->pivot.push_back(*bodyMidRight2);
		}
		else if (sp->shapeCode == 11) {
			this->shapeCode = 3;

			Position* bodyTop1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTop2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 1, ']');
			Position* bodyBottomLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodyBottomLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyBottomMid1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyBottomMid2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyBottomRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyBottomRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomMid1);
			this->position.push_back(*bodyBottomMid2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//    []
			//  [][][]
			//    ^
			//  pivot
			this->pivot.push_back(*bodyBottomMid1);
			this->pivot.push_back(*bodyBottomMid2);
		}
		else if (sp->shapeCode == 4) {
			this->shapeCode = 12;

			Position* bodyTop1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTop2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y - 1, ']');
			Position* bodyMidLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodyMidLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyMidRight1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyMidRight2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyBottom1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyBottom2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y + 1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyMidLeft1);
			this->position.push_back(*bodyMidLeft2);
			this->position.push_back(*bodyMidRight1);
			this->position.push_back(*bodyMidRight2);
			this->position.push_back(*bodyBottom1);
			this->position.push_back(*bodyBottom2);

			//  []
			//  [][] <- pivot
			//    []
			this->pivot.push_back(*bodyMidRight1);
			this->pivot.push_back(*bodyMidRight2);
		}
		else if (sp->shapeCode == 12) {
			this->shapeCode = 4;

			Position* bodyTopLeft1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTopLeft2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 1, ']');
			Position* bodyTopRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTopRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y - 1, ']');
			Position* bodyBottomLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y, '[');
			Position* bodyBottomLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y, ']');
			Position* bodyBottomRight1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyBottomRight2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');

			this->position.push_back(*bodyTopLeft1);
			this->position.push_back(*bodyTopLeft2);
			this->position.push_back(*bodyTopRight1);
			this->position.push_back(*bodyTopRight2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//    [][]
			//  [][]
			//    ^
			//   pivot
			this->pivot.push_back(*bodyBottomRight1);
			this->pivot.push_back(*bodyBottomRight2);
		}
		else if (sp->shapeCode == 5) {
			this->shapeCode = 13;

			Position* bodyTop1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTop2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y - 1, ']');
			Position* bodyMidLeft1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyMidLeft2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyMidRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyMidRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');
			Position* bodyBottom1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y + 1, '[');
			Position* bodyBottom2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y + 1, ']');

			this->position.push_back(*bodyTop1);
			this->position.push_back(*bodyTop2);
			this->position.push_back(*bodyMidLeft1);
			this->position.push_back(*bodyMidLeft2);
			this->position.push_back(*bodyMidRight1);
			this->position.push_back(*bodyMidRight2);
			this->position.push_back(*bodyBottom1);
			this->position.push_back(*bodyBottom2);

			//               []
			//   pivot ->  [][]
			//             []
			this->pivot.push_back(*bodyMidLeft1);
			this->pivot.push_back(*bodyMidLeft2);
		}
		else if (sp->shapeCode == 13) {
			this->shapeCode = 5;

			Position* bodyTopLeft1 = new Position(sp->pivot[0].pos_x - 2, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTopLeft2 = new Position(sp->pivot[0].pos_x - 1, sp->pivot[0].pos_y - 1, ']');
			Position* bodyTopRight1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y - 1, '[');
			Position* bodyTopRight2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y - 1, ']');
			Position* bodyBottomLeft1 = new Position(sp->pivot[0].pos_x, sp->pivot[0].pos_y, '[');
			Position* bodyBottomLeft2 = new Position(sp->pivot[1].pos_x, sp->pivot[1].pos_y, ']');
			Position* bodyBottomRight1 = new Position(sp->pivot[0].pos_x + 2, sp->pivot[0].pos_y, '[');
			Position* bodyBottomRight2 = new Position(sp->pivot[0].pos_x + 3, sp->pivot[0].pos_y, ']');

			this->position.push_back(*bodyTopLeft1);
			this->position.push_back(*bodyTopLeft2);
			this->position.push_back(*bodyTopRight1);
			this->position.push_back(*bodyTopRight2);
			this->position.push_back(*bodyBottomLeft1);
			this->position.push_back(*bodyBottomLeft2);
			this->position.push_back(*bodyBottomRight1);
			this->position.push_back(*bodyBottomRight2);

			//            [][]
			//   pivot ->   [][]
			this->pivot.push_back(*bodyBottomLeft1);
			this->pivot.push_back(*bodyBottomLeft2);
		}
	}
};

struct Shape {
	//	  [][]
	//	  [][]
	int square = 1;

	//   []
	//   []					//  [][][][]
	//   []					
	//   []
	int vertical = 2;		int horizontal = 8;

	//    []				//    []				//  [][][]					//    []
	//  [][][]				//    [][]				//    []					//  [][]
							//    []											//    []
	int t1 = 3;				int t2 = 9;				int t3 = 10;				int t4 = 11;

	//    [][]				//  []
	//  [][]				//  [][]
							//    []
	int s1 = 4;				int s2 = 12;

	//  [][]				//    []
	//    [][]				//  [][]
							//  []
	int z1 = 5;				int z2 = 13;

	//  []					//  [][]											//    []
	//  [][][]				//  []					//  [][][]					//    []
							//  []					//      []					//  [][]
	int L1 = 6;				int L3 = 14;			int L4 = 15;				int L5 = 16;

	//      []				//  []												//  [][]
	//  [][][]				//  []					//  [][][]					//    []
							//  [][]				//  []						//    []
	int L2 = 7;				int L6 = 17;			int L7 = 18;				int L8 = 19;
};

//deprecated
struct Result {
	bool isPosition;
	char body;

	Result(bool isPosition, char body) {
		this->isPosition = isPosition;
		this->body = body;
	}
};

pair<bool, char> isShapePosition(ShapePosition* current, int pos_x, int pos_y) {
	for (unsigned int i = 0; i < current->position.size(); i++) {
		if (current->position[i].pos_x == pos_x && current->position[i].pos_y == pos_y) {
			return { true, current->position[i].body };
		}
	}

	return { false, 0 };
}

bool dropHitBlock(ShapePosition* current, map<int, map<int, char>> bottomAccumulate) {
	for (unsigned int i = 0; i < current->position.size(); i++) {
		int dropTouchBlock = bottomAccumulate[current->position[i].pos_y + 1].count(current->position[i].pos_x);

		if (dropTouchBlock > 0) {
			return true;
		}
	}

	return false;
}

bool hitLeftBlock(ShapePosition* current, map<int, map<int, char>> bottomAccumulate) {
	for (unsigned int i = 0; i < current->position.size(); i++) {
		int touchLeftBlock = bottomAccumulate[current->position[i].pos_y].count(current->position[i].pos_x - 1);
		if (touchLeftBlock > 0) {
			return true;
		}

		//hit wall
		if (current->position[i].pos_x - 1 == 1) {
			return true;
		}
	}

	return false;
}

bool hitRightBlock(ShapePosition* current, map<int, map<int, char>> bottomAccumulate) {
	for (unsigned int i = 0; i < current->position.size(); i++) {
		int touchRightBlock = bottomAccumulate[current->position[i].pos_y].count(current->position[i].pos_x + 1);
		if (touchRightBlock > 0) {
			return true;
		}

		//hit wall
		if (current->position[i].pos_x + 1 == width) {
			return true;
		}
	}

	return false;
}

void g_frame(ShapePosition* current, map<int, map<int, char>> bottomAccumulate, int score) {
	cout << "Score: " << score << "\n\n\n\n";

	for (int h = 1; h <= height; h++) {
		cout << "\t\t\t";

		for (int w = 1; w <= width; w++) {
			pair<bool, char> overlapped = isShapePosition(current, w, h);
			int isAccumulate = bottomAccumulate[h].count(w);

			if (w == 1 || w == width || h == height) {
				cout << "#";
			}
			else if (overlapped.first) {
				cout << overlapped.second;
			}
			else if (isAccumulate > 0) {
				cout << bottomAccumulate[h][w];
			}
			else {
				cout << " ";
			}
		}

		cout << "\n";
	}
}

int main()
{
	ShapePosition* current = new ShapePosition();
	map<int, map<int, char>> bottomAccumulate;
	bool gameOver = false;
	int score = 0;

	while (!gameOver) {

		Sleep(100);

		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				if (!hitLeftBlock(current, bottomAccumulate)) {
					for (int i = 0; i < current->position.size(); i++) {
						current->position[i].pos_x -= 2;
					}

					for (unsigned int i = 0; i < current->pivot.size(); i++) {
						current->pivot[i].pos_x -= 2;
					}
				}

				break;
			case 'd':
				if (!hitRightBlock(current, bottomAccumulate)) {
					for (int i = 0; i < current->position.size(); i++) {
						current->position[i].pos_x += 2;
					}

					for (unsigned int i = 0; i < current->pivot.size(); i++) {
						current->pivot[i].pos_x += 2;
					}
				}

				break;
			case 'w':
				Rotate * shapeChange = new Rotate(current);
				current->shapeCode = shapeChange->shapeCode;
				current->position = shapeChange->position;
				current->pivot = shapeChange->pivot;

				break;
			}
		}

		g_frame(current, bottomAccumulate, score);

		//end drop
		if (current->position[current->position.size() - 1].pos_y == height - 1 || dropHitBlock(current, bottomAccumulate)) {
			for (unsigned int i = 0; i < current->position.size(); i++) {
				bottomAccumulate[current->position[i].pos_y][current->position[i].pos_x] = current->position[i].body;
			}

			//break only full iteration checking is done(no more row clear)
			int row = 0;
			while (row <= height) {
				bool isRowFull = bottomAccumulate[row].size() >= width - 2;
				if (isRowFull) {
					score += 10;
					for (int i = row; i >= 0; i--) {
						if (row == 0) {
							bottomAccumulate[i] = map<int, char>();		//empty 
						}
						else {
							bottomAccumulate[i] = bottomAccumulate[i - 1];
						}
					}
					row = 0; //back to top-to-bottom validate
				}
				else {
					row++;
				}
			}

			current = new ShapePosition();
		}
		else {
			for (unsigned int i = 0; i < current->position.size(); i++) {
				current->position[i].pos_y++;
			}

			for (unsigned int i = 0; i < current->pivot.size(); i++) {
				current->pivot[i].pos_y++;
			}
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
}