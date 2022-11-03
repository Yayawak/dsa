#include "location.cpp"
#include <math.h>
#include "const.cpp"


class Node
{
    // current pos
    int rPos;
    int cPos;
    int GValue;
    // F = G + H
    int FValue; // smaller FValue gets priority

    public:
        Node(const Location &loc, int g, int f)
        {
            rPos = loc.row;
            cPos = loc.col;
            GValue = g;
            FValue = f;
        }

        Location    get_location() const
        {
            return Location(rPos, cPos);
        }

        int         get_gval() const { return (GValue); }

        int         get_fval() const { return (FValue); }

        void        calculate_fval(const Location& locDest)
        {
            FValue = GValue + get_hval(locDest) * 10;
        }

        void        update_gval(const int &i)
        {
            GValue += (NDIR == 8 ? (
                        i % 2 == 0 ? 10 : 14
                        ) : 10);
        }

        const int   &get_hval(const Location& locDest)
        {
            static int  rd, cd, d;
            rd = locDest.row - rPos;
            cd = locDest.col - cPos;
            // Euclidean distance
            d = static_cast<int>(sqrt((double)((rd * rd) + (cd * cd))));

            // Manhattan distance
            //d = abs(rd) + abs(cd);

            // Chebyshev distance
            // d = max(abs(rd), abs(cd));
            //
            return (d);
        }

        friend bool operator<(const Node &a, const Node &b)
        /* friend bool operator(const Node &a, const Node &b) */
        {
            return a.get_fval() > b.get_fval();
        }
};
