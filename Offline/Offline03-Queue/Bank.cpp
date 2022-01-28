#include "AQueue.hpp"
#include "LQueue.hpp"
#include "Customer.hpp"

int main()
{
    Queue<Customer> *q1 = new LQueue<Customer>();
    Queue<Customer> *q2 = new LQueue<Customer>();
    int n;
    cin >> n;
    int q1Time = 0, q2Time = 0;
    while (n--)
    {
        int entry, service;
        // New entry
        cin >> entry >> service;
        Customer c(entry, service);
        // dequeue  < enqueue
        while (dequeueCustomerBeforeEnqueue(q1, q2, q1Time, q2Time, entry))
        {
            // Switch
            switchCustomer(q1, q2);
        }
        // Corner case : enqueue == dequeue
        dequeueCustomerBeforeEnqueue(q1, q2, q1Time, q2Time, entry + 1);
        // Enqueue
        enqueueCustomer(q1, q2, q1Time, q2Time, c);
    }

    // After new customer entry is stopped
    // Dequeue
    while (dequeueCustomer(q1, q2, q1Time, q2Time))
    {
        // Switch
        switchCustomer(q1, q2);
    }
    cout << q1Time << " " << q2Time << endl;
}
/*
5
0 2
3 4
7 2
8 6
9 3
*/
/*
7
0 4
1 6
2 6
3 7
4 6
5 7
17 2
*/
/*
10
0 8 -> 1
1 5 -> 2
2 8 -> 3
2 4 -> 4
3 8 -> 5
3 3 -> 6
4 8 -> 7
4 2 -> 8
5 8 -> 9 
6 2 -> 10
<1> <>  -> 0 0
<1> <2> -> 0 1
<1,3> <2> -> 2 1
<1,3> <2,4> ->
<1,3,5> <2,4>
<1,3,5> <2,4,6>
<1,3,5,7,9> <2,4,6,8> -> 5 4
<1,3,5,7,9> <4,6,8> -> 5 6
<1,3,5,7,9> <4,6,8,10> -> 5 6
<3,5,7,9> <4,6,8,10> -> 8 6
<3,5,7,9> <6,8,10> -> 8 10
<3,5,7,9> <6,8,10> ->
<3,5,7> <8,10,9> -> 8 13
<3,5,7> <10,9> -> 8 15
<3,5,7> <10,9> -> 8 15
<5,7> <9> -> 16 17
<7> <9> -> 24 17
<7> <> -> 24 25
<  > <> -> 32 25
q1 = 24
q2 = 22
*/
// 18 20

/*
4
0 7
1 5
2 7
6 5
*/
