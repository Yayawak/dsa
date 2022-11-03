//https://www.bogotobogo.com/Algorithms/path_finding_algorithm.php
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <string>
#include <queue>
//#include "location.cpp"
#include "node.cpp"
//#include "const.cpp"

using namespace std;


int         square[IDIM][JDIM];
int         closedNodes[IDIM][JDIM];
int         openNodes[IDIM][JDIM];

// map of directions (0: East, 1: North, 2: West, 3: South)
int         dirMap[IDIM][JDIM];


string      a_star_path_find(const Location &locStart
        , const Location &locFinish)
{
    // list of open (not yet checked out) nodes
    static priority_queue<Node> q[2];
    static int      qi; // q index
    static Node*    pInitNode;
    static Node*    pCheckerNode;
    static int      i, j, row, col, iNext, jNext;
    static char     c;

    qi = 0;
    // reset the Node list (0 = ".")
    for (j = 0; j < JDIM; j++)
    {
        for (i = 0; i < IDIM; i++)
        {
            closedNodes[i][j] = 0;
            openNodes[i][j] = 0;
        }
    }

    pInitNode = new Node(locStart, 0, 0);
    pInitNode->calculate_fval(locFinish);
    q[qi].push(*pInitNode);

    // A* SEARCH
    while (!q[qi].empty())
    {
        // get the current node # the lowest f value form list of open nodes
        pInitNode = new Node(q[qi].top().get_location(),
                q[qi].top().get_gval(),
                q[qi].top().get_fval()
                );
        row = pInitNode->get_location().row;
        col = pInitNode->get_location().col;
        cout << "row, col = " << row << "," << col << endl;

        // revome the node from open list
        q[qi].pop();
        openNodes[row][col] = 0;
        // mark it on the closed noeds list
        closedNodes[row][col] = 1;
        // stop search when reach goal
        if (row == locFinish.row && col == locFinish.col)
        {
            // draw direction map
            for (j = JDIM - 1; j >= 0; j--)
            {
                for (i = 0; i < IDIM; i++)
                    cout << dirMap[i][j];
                cout << endl;
            }
        }
        cout << endl;

        string path = "";
        while (!(row == locStart.row && col == locStart.col))
        {
            j = dirMap[row][col];
            c = '0' + (j + NDIR / 2) % NDIR;
            path = c + path;
            row += iDir[j];
            col += jDir[j];
        }
        delete pInitNode;

        while (!q[qi].empty()) q[qi].pop();

        return (path);

        // Generate moves in all possible directions
        for (i = 0; i < NDIR; i++)
        {
            iNext = row + iDir[i];
            jNext = col + jDir[i];

            //if not wall nor in the cloesed list
            if (!(iNext < 0 || iNext > IDIM - 1
                || jNext < 0 || jNext > JDIM - 1
                || square[iNext][jNext] == 1
                || closedNodes[iNext][jNext] == 1
                    ))
            {
                // genereate a child node
                pCheckerNode = new Node(Location(iNext, jNext),
                        pInitNode->get_gval(),
                        pCheckerNode->get_fval());
                pCheckerNode->update_gval(i);
                pCheckerNode->calculate_fval(locFinish);

                // if it is not in the open list then add to
                if (openNodes[iNext][jNext] == 0)
                {
                    openNodes[iNext][jNext] = pCheckerNode->get_fval();
                    q[qi].push(*pCheckerNode);
                    // mark its parent node direction
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;
                }
                else if (openNodes[iNext][jNext] > pCheckerNode->get_fval())
                {
                    openNodes[iNext][jNext] = pCheckerNode->get_fval();
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;
                    while (!(q[qi].top().get_location().row == iNext
                            && q[qi].top().get_location().col == jNext))
                    {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }
                    q[qi].pop();

                    if (q[qi].size() > q[1 - qi].size()) qi = 1 - qi;
                    while (q[qi].empty())
                    {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }
                    qi = 1 - qi;

                    q[qi].push(*pCheckerNode);
                }
                else
                    delete pCheckerNode;
            }
        }
        delete pInitNode;
    }
    return ("");
}

