#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    Init();
    
    // Act:
    result1 = Pop(&testInt);
      
    // Assert:
    assert(-1 == result1);
    assert(100 == testInt);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    Init();
    
    // Act:
    result1 = Push(50);
    result2 = Pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(50 == testInt);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 100;
    Init();
    
    // Act:
    Push(1);
    Push(2);
    Push(3);                                    
    
    // Assert:
    assert(0 == Pop(&testInt));
    assert(3 == testInt);

    assert(0 == Pop(&testInt));
    assert(2 == testInt);

    assert(0 == Pop(&testInt));
    assert(1 == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 100;
    Init();
    
    // Act:
    Push(1);
    Push(2);
    Push(3);
    
    // Assert:
    assert(-1 == Push(50));

    assert(0 == Pop(&testInt));
    assert(3 == testInt);

    assert(0 == Pop(&testInt));
    assert(2 == testInt);

    assert(0 == Pop(&testInt));
    assert(1 == testInt);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    Init();
    
    // Act:
    Push(1);
    Push(2);
    Push(3);
    
    // Assert:
    assert(0 == Pop(&testInt));
    assert(3 == testInt);

    assert(0 == Push(50));

    assert(0 == Pop(&testInt));
    assert(50 == testInt);

    assert(0 == Pop(&testInt));
    assert(2 == testInt);

    assert(0 == Pop(&testInt));
    assert(1 == testInt);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    Init();
    
    // Act:
    Push(1);
    Push(2);
    Push(3);
    
    // Assert:
    assert(0 == Pop(&testInt));
    assert(3 == testInt);

    assert(0 == Pop(&testInt));
    assert(2 == testInt);

    assert(0 == Pop(&testInt));
    assert(1 == testInt);

    assert(0 == Push(4));
    assert(0 == Push(5));
    assert(0 == Push(6));
    
    assert(-1 == Push(7));

    assert(0 == Pop(&testInt));
    assert(6 == testInt);
   
    assert(0 == Pop(&testInt));
    assert(5 == testInt);

    assert(0 == Pop(&testInt));
    assert(4 == testInt);

    return 0;
}
