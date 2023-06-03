#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("MagicContainer functions")
{
    MagicalContainer cont;

    CHECK(cont.size() == 0);

    for (int i = 1; i <= 10; i++)
    {
        cont.addElement(i);
    }

    CHECK(cont.size() == 10);

    cont.addElement(11);

    CHECK(cont.size() != 10);

    cont.removeElement(8);

    CHECK(cont.size() == 10);

    for (int i = 1; i <= 11; i++)
    {
        if (i == 8)
        {
            CHECK_THROWS(cont.removeElement(i));
        }
        else
        {
            cont.removeElement(i);
            CHECK(cont.size() == (11 - i));
        }
    }
}

TEST_CASE("Prime Iterator")
{
    MagicalContainer cont;
    cont.addElement(11);
    cont.addElement(10);
    cont.addElement(14);
    cont.addElement(7);

    MagicalContainer::PrimeIterator pr(cont);

    CHECK(*pr == 11);

    ++pr;

    CHECK(*pr == 10);
    CHECK(*pr != 11);

    ++pr;
    ++pr;

    CHECK(pr == pr.end());
}

TEST_CASE("Ascending Iterator")
{
    MagicalContainer cont;
    cont.addElement(6);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(10);
    cont.addElement(5);

    MagicalContainer::AscendingIterator asc(cont);

    int expected[] = {1, 3, 5, 6, 10};

    for (int i = 0; asc != asc.end(); ++asc, ++i)
    {
        CHECK(*asc == expected[i]);
    }

    CHECK(asc == asc.end());
}

TEST_CASE("Side Cross Iterator")
{
    MagicalContainer cont;
    cont.addElement(8);
    cont.addElement(11);
    cont.addElement(6);

    MagicalContainer::SideCrossIterator cross(cont);

    int expected[] = {6, 11, 8};

    for (int i = 0; cross != cross.end(); ++cross, ++i)
    {
        CHECK(*cross == expected[i]);
    }

    CHECK(cross == cross.end());
}