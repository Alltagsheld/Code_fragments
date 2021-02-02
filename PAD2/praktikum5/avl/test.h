#ifndef TEST_H
#define TEST_H

#include<iostream>

#include "avltree.h"

void smallTestForBugFoundInLecture(AVLTree &avl)
{
    // I fixed my bug from the lecture:
    avl.checkInsert(17);
    avl.checkInsert(42);
    avl.checkInsert(1337);
    avl.checkInsert(21);
    avl.show();
    avl.writeDot("testbefore");
    avl.checkInsert(19);
    avl.writeDot("testafter");
}

void bigInsertionTest(AVLTree &avl)
{
    avl.checkInsert(23);
    avl.checkInsert(29);
    avl.checkInsert(84);
    avl.checkInsert(58);
    avl.checkInsert(19);
    avl.checkInsert(81);
    avl.checkInsert(17);
    avl.checkInsert(15);
    avl.checkInsert(36);
    avl.checkInsert(49);
    avl.checkInsert(91);
    avl.checkInsert(26);
    avl.checkInsert(22);
    avl.checkInsert(57);
    avl.checkInsert(33);
    avl.checkInsert(50);
    avl.checkInsert(56);
    avl.checkInsert(85);
    avl.checkInsert(4);
    avl.checkInsert(10);
    avl.checkInsert(63);
    avl.checkInsert(1);
    avl.checkInsert(72);
    avl.checkInsert(48);
    avl.checkInsert(25);
    avl.checkInsert(67);
    avl.checkInsert(75);
    avl.checkInsert(90);
    avl.checkInsert(92);
    avl.checkInsert(37);
    avl.checkInsert(89);
    avl.checkInsert(77);
    avl.writeDot("bigcheckInsertionTest1");
}

void removeTest(AVLTree &avl)
{
    // to be called after bigcheckInsertionTest
    avl.remove(33); // simple leaf node remove
    avl.writeDot("removeTest1"); // should have rebalanced
    avl.remove(26); // simple single child node remove
    avl.writeDot("removeTest2");
    avl.remove(23); // some more difficult removes
    avl.writeDot("removeTest3");
    avl.remove(81);
    avl.writeDot("removeTest4");
    avl.remove(29);
    avl.writeDot("removeTest5");
    avl.remove(80); //removal of non-existent key
    avl.writeDot("removeTest6"); // should be the same
}

void findTest(AVLTree &avl)
{
    //to be called after removeTest
    string s;

    if (avl.member(80)) cout << "fail: precondition of test";
    if (avl.member(42)) cout << "fail: precondition of test";

    if (!avl.member(17)) cout << "fail: precondition of test";

    avl.checkInsert(80,"something");
    if (avl.find(80,s)) cout << "good: found " << s << endl;
    if (s!="something") cout << "fail: test failed, something not found" << endl;

    if (!avl.find(42,s)) cout << "good: 42 not found" << endl;
    else cout << "fail: precondition of test failed" << endl;

    if (!avl.probe(42,"an answer")) cout << "good: 42 not found, and should be checkInserted now" << endl;
    else cout << "fail: 42 already there";

    if (avl.probe(42,"something stupid")) cout << "good: 42 already there, nothing should be changed" << endl;
    else cout << "fail: 42 not found, but should be there already" << endl;

    if (avl.find(42,s)) cout << "good: found " << s << endl;
    else cout << "fail: 42 not found" << endl;
    if (s!="an answer") cout << "fail: test failed, expected an answer, found" << s << endl;

    avl.set(42,"the answer to the ultimate question of life, the universe, and everything");
    if (avl.find(42,s)) cout << "42 is " << s << endl;

    avl.clear();
    avl.show();
}

#endif // TEST_H
