#include "Canvas.h"


//Creates this canvas's grid filled with blank characters
Canvas::Canvas(int rows, int columns, char fillChar) {
    for (int i = 0; i < rows; ++i) {
        vector<char> gridCol;
        
        for (int j = 0; j < columns; j++) {
            gridCol.push_back(fillChar);
        }
        grid.push_back(gridCol);
    }
}


//validates row and col (0-based)
bool Canvas::check(int row, int col) const {
    return (0 <= row && row < getRows() && 0 <= col && col < getColumns());
}


//resizes the dimensions
void Canvas::resize(size_t rows, size_t cols) {
    grid.resize(rows);
    
    for (auto& vec : grid) {
        vec.resize(cols);
    }
}

// returns height of this Canvas object
int Canvas::getRows() const {
    return (int)grid.size();
}

// returns width of this Canvas object
int Canvas::getColumns() const {
    int col = 0;
    for (auto& vec : grid) {
        col = vec.size() > col ? (int)vec.size() : (int)col;
    }
    return col;
}

// returns char at row r and column c, 0-based;
char Canvas::get(int r, int c) const {
    if (!check(r, c)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }
    else return grid[r][c];
}

// puts ch at row r and column c, 0-based;
void Canvas::put(int row, int col, char ch) {
    if (!check(row, col)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }
    else grid[row][col] = ch;
}


// draws text starting at row r and col c on this canvas
void Canvas::drawString(int r, int c, const std::string text) {
    std::string str{ text };
    for (char& ch : str) {
        put(r, c, ch);
        ++c; // move to next char in string
    }
}


//horizontally flip the canvas
Canvas Canvas::flip_horizontal() const {
    Canvas newCan{ getRows(), getColumns() };

    for (int row = 0; row < getRows(); ++row) {
        int last = getColumns() - 1; // fetch last column
        for (int col = 0; col < getColumns(); ++col) {
            newCan.put(row, last, grid[row][col]);
            --last; // decrement last column element
        }
    }
    return newCan;
}


//vertically flip the canvas
Canvas Canvas::flip_vertical() const {
    Canvas newCan{ getRows(), getColumns() };

    int last = getRows() - 1; // fetch last row
    for (int row = 0; row < getRows(); ++row) {
        for (int col = 0; col < getColumns(); ++col) {
            newCan.put(last, col, grid[row][col]);
        }
        --last; // decrement last row element
    }
    return newCan;
}

// copies the non-blank characters of "can" onto the invoking Canvas object;
// maps can’s origin to row r and column c on the invoking Canvas object
void Canvas::overlap(const Canvas& can, size_t r, size_t c) {

    // checks if the total size of canvas after overlap > current canvas size
    if (can.getRows() + r > getRows() || can.getColumns() + c > getColumns()) {
        // if true, resize the current canvas to new size
        this->resize(getRows() + can.getRows(), getColumns() + can.getColumns());
    }

    // overlapping loop
    for (int row = 0; row < can.getRows(); ++row) {
        for (int col = 0; col < can.getColumns(); ++col) {
            if (can.get(row, col) != ' ') {
                put((int)(r + row), (int)(c + col), can.get(row, col));
            }
        }
    }
}


//Prints this Canvas to ostream
void Canvas::print(ostream& sout) const {
    for (auto& row : grid) {
        for (char ch : row) {
            sout << ch;
        }
        sout << std::endl;
    }
}


ostream& operator<< (ostream& sout, const Canvas& can) {
    can.print(sout);
    return sout;
}
