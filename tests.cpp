/// @file tests.cpp
/// @date March 17, 2023
/// @brief test methods in the priorityqueue class
/// @author Raymond Lo
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023



// Google Test Framework Testing
#include <gtest/gtest.h>
#include "priorityqueue.h"

//Tests default constructor with int value
TEST(priorityqueue, defaultConstructor){
    priorityqueue<int> pq;
    EXPECT_EQ(pq.peek(), 0); //peek should be 0 since root is nullptr
    EXPECT_EQ(pq.Size(), 0);
}

//Tests default constructor with string value
TEST(priorityqueue, defaultConstructor2){
    priorityqueue<string> pq;
    EXPECT_EQ(pq.peek(), ""); //peek should be "" since root is nullptr
    EXPECT_EQ(pq.Size(), 0);
}

//Tests default constructor with double value
TEST(priorityqueue, defaultConstructor3){
    priorityqueue<double> pq;
    EXPECT_EQ(pq.peek(), 0.0); //peek should be 0.0 since root is nullptr
    EXPECT_EQ(pq.Size(), 0);
}

//Tests size of default queue
TEST(priorityqueue, defaultQueueSize){
    priorityqueue<string> pq;
    EXPECT_EQ(pq.Size(), 0);
}

//Tests size of queue with int values
TEST(priorityqueue, queueSize){
    priorityqueue<int> pq;
    int size = 9;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {2, 3, 2, 2, 1, 2, 2, 3, 3};
    for(int i = 0; i < size; i++){
        pq.enqueue(vals[i], prs[i]);
    }
    EXPECT_EQ(pq.peek(), 7);
    EXPECT_EQ(pq.Size(), 9);
}

//Tests size of queue with string values
TEST(priorityqueue, queueSize2){
    priorityqueue<string> pq;
    int size = 9;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted"};
    int prs[] = {2, 3, 2, 2, 2, 2, 3, 1, 3};
    for(int i = 0; i < size; i++){
        pq.enqueue(vals[i], prs[i]);
    }
    EXPECT_EQ(pq.peek(), "Charlotte");
    EXPECT_EQ(pq.Size(), 9);
}

//Tests size of queue with double values
TEST(priorityqueue, queueSize3){
    priorityqueue<double> pq;
    int size = 15;
    double vals[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5};
    int prs[] = {2, 3, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 1};
    for(int i = 0; i < size; i++){
        pq.enqueue(vals[i], prs[i]);
    }
    EXPECT_EQ(pq.peek(), 1.5);
    EXPECT_EQ(pq.Size(), 15);
}

//Tests the enqueue function: Citation: Adam T Koehler, PhD at UIC
TEST(priorityqueue, enqueue1){
    map<int, vector<int> > map;
    int size = 9;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {1, 2, 3, 2, 2, 2, 2, 3, 3};
    priorityqueue<int> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 9);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str());
}

//Tests the enqueue function with string values
TEST(priorityqueue, enqueue2){
    map<int, vector<string> > map;
    int size = 7;
    string vals[] = {"Ford", "Arnold", "Dolores", "Charlotte", "Bernard", "William", "Zeta"};
    int prs[] = {6, 4, 5, 3, 5, 5, 4};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 7);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str());
}

//Tests the enqueue function with string values
TEST(priorityqueue, enqueue3){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 16);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str());
}

//Tests the enqueue function with double values
TEST(priorityqueue, enqueue4){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 15);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <double> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str());
}

//Tests the toString function with default queue
TEST(priorityqueue, toStringDefault){
    priorityqueue<int> pq;
    EXPECT_EQ(pq.toString(), "");
}

//Tests the toString function with queue with int values
TEST(priorityqueue, toString){
    map<int, vector<int> > map;
    priorityqueue<int> pq;
    int size = 9;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {2, 3, 2, 2, 1, 2, 2, 3, 3};
    for(int i = 0; i < size; i++){
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }

    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }

    string actualOutput = pq.toString();
    EXPECT_EQ(actualOutput, ss.str());

}

//Tests the toString function with queue with string values
TEST(priorityqueue, toString2){
    map<int, vector<string>> map;
    priorityqueue<string> pq;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    for(int i = 0; i < size; i++){
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }

    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }

    string actualOutput = pq.toString();
    EXPECT_EQ(actualOutput, ss.str());

}

//Tests the toString function with queue with double values
TEST(priorityqueue, toString3){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 15);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <double> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    
    string actualOutput = pq.toString();
    EXPECT_EQ(actualOutput, ss.str());
}

//Tests the clear function with default queue
TEST(priorityqueue, clearDefault){
    priorityqueue<int> pq;
    pq.clear();
    EXPECT_EQ(pq.peek(), 0);
    EXPECT_EQ(pq.Size(), 0);
}

//Tests the clear function with queue with string values
TEST(priorityqueue, clear){
    int size = 7;
    string vals[] = {"Ford", "Arnold", "Dolores", "Charlotte", "Bernard", "William", "Zeta"};
    int prs[] = {6, 4, 5, 3, 5, 5, 4};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    EXPECT_EQ(pq.Size(), 7);
    pq.clear();
    EXPECT_EQ(pq.peek(), "");
    EXPECT_EQ(pq.Size(), 0);

}

//Tests the clear function with queue with double values
TEST(priorityqueue, clear2){
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    EXPECT_EQ(pq.Size(), 15);
    pq.clear();
    EXPECT_EQ(pq.peek(), 0.0);
    EXPECT_EQ(pq.Size(), 0);

}

//Tests the equal operator overload with default queue
TEST(priorityqueue, equalOperatorDefault){
    priorityqueue<int> pq;
    priorityqueue<int> pq2;
    pq2 = pq;
    EXPECT_EQ(pq.peek(), 0);
    EXPECT_EQ(pq.Size(), 0);
    EXPECT_EQ(pq2.peek(), 0);
    EXPECT_EQ(pq2.Size(), 0);
}

//Tests the equal operator overload with queue with double values
TEST(priorityqueue, equalOperator){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <double> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    priorityqueue<double> pq2;
    pq2 = pq;
    EXPECT_EQ(pq.toString(), ss.str());
    EXPECT_EQ(pq.Size(), 15);
    EXPECT_EQ(pq2.toString(), ss.str());
    EXPECT_EQ(pq2.Size(), 15);
}

//Tests the equal operator overload with queue with int values
TEST(priorityqueue, equalOperator2){
    map<int, vector<int> > map;
    int size = 9;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {1, 2, 3, 2, 2, 2, 2, 3, 3};
    priorityqueue<int> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    priorityqueue<int> pq2;
    pq2 = pq;
    EXPECT_EQ(pq.toString(), ss.str());
    EXPECT_EQ(pq.Size(), 9);
    EXPECT_EQ(pq2.toString(), ss.str());
    EXPECT_EQ(pq2.Size(), 9);
}

//Tests the equal operator overload with queue with string values
TEST(priorityqueue, equalOperator3){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    priorityqueue<string> pq2;
    pq2 = pq;
    EXPECT_EQ(pq.toString(), ss.str());
    EXPECT_EQ(pq.Size(), 16);
    EXPECT_EQ(pq2.toString(), ss.str());
    EXPECT_EQ(pq2.Size(), 16);
}

//Tests the equal operator overload with queue with string values then check if modifying one queue affects the other
TEST(priorityqueue, equalOperator4){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    priorityqueue<string> pq2;
    pq2 = pq;
    pq2.dequeue();
    EXPECT_EQ(pq.toString(), ss.str());
    EXPECT_EQ(pq.Size(), 16);
    EXPECT_NE(pq2.toString(), ss.str());
    EXPECT_EQ(pq2.Size(), 15);
}

//Tests the equal operator overload with queue with int values then check if modifying one queue affects the other
TEST(priorityqueue, equalOperator5){
        map<int, vector<int> > map;
    int size = 9;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {1, 2, 3, 2, 2, 2, 2, 3, 3};
    priorityqueue<int> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    priorityqueue<int> pq2;
    pq2 = pq;
    pq2.dequeue();
    EXPECT_EQ(pq.toString(), ss.str());
    EXPECT_EQ(pq.Size(), 9);
    EXPECT_NE(pq2.toString(), ss.str());
    EXPECT_EQ(pq2.Size(), 8);
}

//Tests the begin function with a queue with int values
TEST(priorityqueue, beginDefault){
    priorityqueue<int> pq;
    int value = 0;
    int priority = 0;
    pq.begin();
    bool result =  pq.next(value, priority);
    EXPECT_EQ(value, 0);
    EXPECT_EQ(priority, 0);
    EXPECT_FALSE(result);
}

//Tests the begin function with a queue with string values
TEST(priorityqueue, beginDefault2){
    priorityqueue<string> pq;
    string value = "";
    int priority = 0;
    pq.begin();
    bool result =  pq.next(value, priority);
    EXPECT_EQ(value, "");
    EXPECT_EQ(priority, 0);
    EXPECT_FALSE(result);
}

//Tests the begin function with a queue with string values
TEST(priorityqueue, begin){
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    pq.begin();

    string value = "";
    int priority = 0;
    bool result =  pq.next(value, priority);
    EXPECT_EQ(value, "Charlotte");
    EXPECT_EQ(priority, 3);
    EXPECT_TRUE(result);
}

//Tests the begin function with a queue with double values
TEST(priorityqueue, begin2){
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    pq.begin();

    double value = 0.0;
    int priority = 0;
    bool result = pq.next(value, priority);
    EXPECT_EQ(value, 7.7);
    EXPECT_EQ(priority, 3);
    EXPECT_TRUE(result);
}

//Tests the next function with a queue with string values
TEST(priorityqueue, next){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    pq.begin();

    string value = "";
    int priority = 0;
    stringstream output;
    while(pq.next(value, priority)){
        output << priority << " value: " << value << "\n";
    }
    output <<  priority << " value: " << value << "\n";
    EXPECT_EQ(output.str(), ss.str());
}

//Tests the next function with a queue with double values
TEST(priorityqueue, next2){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 15);
    stringstream ss;
    for (auto e: map) {
        int priority = e.first;
        vector <double> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    pq.begin();

    double value = 0.0;
    int priority = 0;
    stringstream output;
    while(pq.next(value, priority)){
        output << priority << " value: " << value << "\n";
    }
    output <<  priority << " value: " << value << "\n";
    EXPECT_EQ(output.str(), ss.str());
}

//Tests the dequeue function with a default queue
TEST(priorityqueue, dequeueDefault){
    priorityqueue<int> pq;
    int value = pq.dequeue();
    EXPECT_EQ(value, 0);
}

//Tests the dequeue function once with a queue with string values
TEST(priorityqueue, dequeue){
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    string value = pq.dequeue();
    EXPECT_EQ(value, "Charlotte");
    EXPECT_EQ(pq.Size(), 15);
}

//Tests the dequeue function once with a queue with double values
TEST(priorityqueue, dequeue2){
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    double value = pq.dequeue();
    EXPECT_EQ(value, 7.7);
    EXPECT_EQ(pq.Size(), 14);
}

//Tests the dequeue function multiple times with a queue with string values
TEST(priorityqueue, dequeue3){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: map) {
        vector <string> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << "value: " << values[j] << endl;
        }
    }
    stringstream output;
    while(pq.Size() > 0){
        output << "value: " << pq.dequeue() << "\n";
    }
    EXPECT_EQ(output.str(), ss.str());
    EXPECT_EQ(pq.Size(), 0);
}

//Tests the dequeue function multiple times with a queue with double values
TEST(priorityqueue, dequeue4){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    EXPECT_EQ(pq.Size(), 15);
    stringstream ss;
    for (auto e: map) {
        vector <double> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << "value: " << values[j] << endl;
        }
    }
    stringstream output;
    while(pq.Size() > 0){
        output << "value: " << pq.dequeue() << "\n";
    }
    EXPECT_EQ(output.str(), ss.str());
    EXPECT_EQ(pq.Size(), 0);
}

//Tests the peek function with a default queue
TEST(priorityqueue, peekDefault){
    priorityqueue<int> pq;
    int value = pq.peek();
    EXPECT_EQ(value, 0);
}

//Tests the peek function with a queue with string values
TEST(priorityqueue, peek){
    map<int, vector<string> > map;
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }

    string value = pq.peek();
    EXPECT_EQ(value, "Charlotte");
}

//Tests the peek function with a queue with double values
TEST(priorityqueue, peek2){
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    double value = pq.peek();
    EXPECT_EQ(value, 7.7);
}

//Tests the equality operator overload with a default queue
TEST(priorityqueue, equalityOperatorDefault){
    priorityqueue<int> pq;
    priorityqueue<int> pq2;
    bool output = pq == pq2;
    EXPECT_TRUE(output);
}

//Tests the equality operator overload with default queue and using equals operator overload
TEST(priorityqueue, equalityOperatorDefault2){
    priorityqueue<int> pq;
    priorityqueue<int> pq2;
    pq2 = pq;
    bool output = pq == pq2;
    EXPECT_TRUE(output);
}

//Tests the equality operator overload with a queue with string values and using equals operator overload
TEST(priorityqueue, equalityOperatorDefault3){
    int size = 16;
    string vals[] = {"Ford", "Hope", "Gamma", "Arnold", "Dolores", "Bernard", "William", "Charlotte", "Ted", "Jasmine", "Zeta", "Michael", "Ray", "Xavier", "Sarah", "Teresa"};
    int prs[] = {6, 6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<string> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    priorityqueue<string> pq2;
    pq2 = pq;
    bool output = pq == pq2;
    EXPECT_TRUE(output);
}

//Tests the equality operator overload with a queue with double values and using equals operator overload
TEST(priorityqueue, equalityOperatorDefault4){
    map<int, vector<double> > map;
    int size = 15;
    double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15};
    int prs[] = {6, 6, 4, 5, 5, 5, 3, 3, 3, 4, 8, 8, 8, 7, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < size; i++) {
        pq.enqueue(vals[i], prs[i]);
    }
    priorityqueue<double> pq2;
    pq2 = pq;
    bool output = pq == pq2;
    EXPECT_TRUE(output);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

