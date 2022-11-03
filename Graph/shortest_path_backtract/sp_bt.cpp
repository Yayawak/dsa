//check order : north -> south -> east -> west
//
#include <iostream>
#include <limits.h>

/* int matrix[7][7] = */
/*   { */
/*     { 1, 1, 0, 0, 0, 1, 1}, */
/*     { 0, 1, 1, 1, 1, 1, 1}, */
/*     { 1, 0, 0, 1, 0, 1, 1}, */
/*     { 0, 1, 1, 1, 0, 0, 1}, */
/*     { 0, 1, 0, 1, 1, 1, 1}, */
/*     { 0, 1, 0, 0, 1, 0, 0}, */
/*     { 1, 0, 1, 1, 1, 1, 1} */
/* 	}; */
int matrix[7][7] =
  {
    { 1, 1, 0, 0, 0, 1, 1},
    { 0, 0, 0, 1, 1, 1, 1},
    { 1, 0, 0, 1, 0, 1, 1},
    { 0, 1, 1, 1, 0, 0, 1},
    { 0, 1, 0, 1, 1, 1, 1},
    { 0, 1, 0, 0, 1, 0, 0},
    { 1, 0, 1, 1, 1, 1, 1}
	};

class Maze
{
    private :
        int m; // cols
        int n; // rows
        int     length;

    public :
        int     *start;
        int     *end;
        //int     visited[7][7] = {0};
        /* int     shortLength = INT_MAX; */
        /* int     length = 0; */
        /* bool    hasPath = false;; */
        int     visited[7][7];
        int     shortLength;
        bool    hasPath;

        Maze(int start[], int end[])
        {
            this->start = start;
            this->end = end;
            /* this->visited = {0}; */
            /* this->visited = {0}; */
            this->shortLength = INT_MAX;
            this->length = 0;
            this->hasPath = false;
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 7; j++)
                    visited[i][j] = 0;
            this->m = sizeof(matrix[0]) / sizeof(matrix[0][0]);
            this->n = sizeof(matrix) /sizeof(matrix[0]);
        }

        // initially search process
        void    findPath()
        {
            visit(start[0], start[1]);
        }

        void    visit(int x, int y)
        {
            std::cout << "(x,y) = " << "(" << x << "," << y << ")\n";
            // Base condition - reach destination
            if (x == end[0] && y == end[1])
            {
                // really has path and have solution
                hasPath = true;
                if (length < shortLength)
                    shortLength = length;
                // Backtract to explore more possible paths
                return ;
            }
            // Mark the current cell as visited
            visited[x][y] = 1;
            // Increment the current path length by 1
            length++;

            // Check for next move

            // right
            if (canVisit(x + 1, y))
                visit(x + 1, y);
            // down
            if (canVisit(x, y + 1))
                visit(x, y + 1);
            // left
            if (canVisit(x - 1, y))
                visit(x - 1, y);
            // up
            if (canVisit(x, y - 1))
                visit(x, y - 1);

            // Backtract by unvisiting the current cell
            // and decrementing the value of current path length
            visited[x][y] = 0;
            length--;

        }

        bool    canVisit(int x, int y)
        {
            // check for boundary
            if (x < 0 || y < 0 || x >= m || y >= n)
                return (false);
            // check 0 or already visited
            if (matrix[x][y] == 0 || visited[x][y] == 1)
                return (false);
//            std::cout << "(x,y) = " << "(" << x << "," << y << ")\n";
            return (true);
        }
};


int     main(void)
{
    int     start[] = {0, 0};
    int     end[] = {6, 6};

    Maze maze(start, end);
    maze.findPath();

    // output if the maze has a solution
    //
    if (maze.hasPath)
        std::cout << "Shortest Path Length : " << maze.shortLength;
    else
        std::cout << "No Path Possible";
    return (0);
}
