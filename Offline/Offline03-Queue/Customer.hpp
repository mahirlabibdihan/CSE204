#include <iostream>
#include "Queue.hpp"
using namespace std;
class Customer
{
public:
    int entryTime, serviceTime;
    Customer()
    {
        entryTime = 0;
        serviceTime = 0;
    }
    Customer(int entry, int service)
    {
        entryTime = entry;
        serviceTime = service;
    }
};
void switchCustomer(Queue<Customer> *q1, Queue<Customer> *q2)
{
    if (q1->length() < q2->length() - 1)
    {
        q1->enqueue(q2->leaveQueue());
        // cout << q1->rearValue().id << " switched from q2 to q1 " << endl;
    }
    else if (q2->length() < q1->length() - 1)
    {
        q2->enqueue(q1->leaveQueue());
        // cout << q2->rearValue().id << " switched from q1 to q2 " << endl;
    }
}
bool dequeueCustomerBeforeEnqueue(Queue<Customer> *q1, Queue<Customer> *q2, int &q1Time, int &q2Time, int entry)
{
    if (q1->length() > 0 && q2->length() > 0)
    {
        if (q1Time + q1->frontValue().serviceTime < entry && q2Time + q2->frontValue().serviceTime < entry)
        {
            if (q1Time + q1->frontValue().serviceTime < q2Time + q2->frontValue().serviceTime)
            {
                q1Time += q1->frontValue().serviceTime;
                // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
                q1->dequeue();
            }
            else if (q1Time + q1->frontValue().serviceTime > q2Time + q2->frontValue().serviceTime)
            {
                q2Time += q2->frontValue().serviceTime;
                // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
                q2->dequeue();
            }
            else
            {
                q1Time += q1->frontValue().serviceTime;
                // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
                q1->dequeue();
                q2Time += q2->frontValue().serviceTime;
                // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
                q2->dequeue();
            }
            return true;
        }
        else if (q1Time + q1->frontValue().serviceTime < entry)
        {
            q1Time += q1->frontValue().serviceTime;
            // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
            q1->dequeue();
            return true;
        }
        else if (q2Time + q2->frontValue().serviceTime < entry)
        {
            q2Time += q2->frontValue().serviceTime;
            // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
            q2->dequeue();
            return true;
        }
    }
    else if (q1->length() > 0)
    {
        if (q1Time + q1->frontValue().serviceTime < entry)
        {
            q1Time += q1->frontValue().serviceTime;
            // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
            q1->dequeue();
            return true;
        }
    }
    else if (q2->length() > 0)
    {
        if (q2Time + q2->frontValue().serviceTime < entry)
        {
            q2Time += q2->frontValue().serviceTime;
            // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
            q2->dequeue();
            return true;
        }
    }
    return false;
}
bool dequeueCustomer(Queue<Customer> *q1, Queue<Customer> *q2, int &q1Time, int &q2Time)
{
    if (q1->length() > 0 && q2->length() > 0)
    {
        if (q1Time + q1->frontValue().serviceTime < q2Time + q2->frontValue().serviceTime)
        {
            q1Time += q1->frontValue().serviceTime;
            // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
            q1->dequeue();
        }
        else if (q1Time + q1->frontValue().serviceTime > q2Time + q2->frontValue().serviceTime)
        {
            q2Time += q2->frontValue().serviceTime;
            // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
            q2->dequeue();
        }
        else
        {
            q1Time += q1->frontValue().serviceTime;
            // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
            q1->dequeue();

            q2Time += q2->frontValue().serviceTime;
            // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
            q2->dequeue();
        }
    }
    else if (q1->length() > 0)
    {
        q1Time += q1->frontValue().serviceTime;
        // cout << q1->frontValue().id << " left from q1 at " << q1Time << endl;
        q1->dequeue();
    }
    else if (q2->length() > 0)
    {
        q2Time += q2->frontValue().serviceTime;
        // cout << q2->frontValue().id << " left from q2 at " << q2Time << endl;
        q2->dequeue();
    }
    else
    {
        return false;
    }
    return true;
}
// Enqueue customer in any of the queue
// c: The customer being enqueued
void enqueueCustomer(Queue<Customer> *q1, Queue<Customer> *q2, int &q1Time, int &q2Time, Customer &c)
{
    if (q2->length() < q1->length())
    {
        if (q2->length() == 0)
        {
            q2Time = c.entryTime;
            // cout << c.id << " entered in q2 at " << q2Time << endl;
        }
        q2->enqueue(c);
    }
    else
    {
        if (q1->length() == 0)
        {
            q1Time = c.entryTime;
            // cout << c.id << " entered in q1 at " << q1Time << endl;
        }
        q1->enqueue(c);
    }
}