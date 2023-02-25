//
//  class_struct.cpp
//  CPlusPlus
//
//  Created by Michael Pan on 2023/2/21.
//

#include <iostream>
#include <string>
#include "class_struct.hpp"

#define print(message) std::cout << message << "\n";

void test_const();



struct Vector2
{
    int x, y;
    
    Vector2() {
        x = 0;
        y = 0;
    }
    
    ~Vector2() {
        print("deconstruct");
    }
};


class Entity
{
private:
    Vector2* position;

public:
    Entity() {
        print("Entity constructor");
        position = new Vector2;
    }
    
    ~Entity() {
        delete position;
    }

    int x() const {
        return position->x;
    }
    
    int y() const {
        return position->y;
    }
    
    Vector2* GetPosition() const {
        return position;
    }
    const Vector2* GetConstPosition() const {
        return position;
    }
};

class Human : public Entity
{
private:
    std::string firstName;
    std::string lastName;
public:
    Human(std::string firstName, std::string lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }
    
    std::string Name() const {
        return this->firstName + " " + this->lastName;
    }
};



void test() {
    test_const();

    Human* human = new Human("Michael", "Pan");
    print(human->x());
    print(human->y());
    print(human->Name());
    delete human;
}

void test_const() {
    Entity entity;
    print(entity.x());
    print(entity.y());
    
    Vector2* const position = entity.GetPosition();
    
    // const Vector2* const position = person.GetPosition();
    // Error: because const pointer's value, can't be changed

    position->x = 10;
    position->y = 5;
    
    print(entity.x());
    print(entity.y());
    
    const Vector2* position2 = entity.GetConstPosition();
    print(position2->x);
    print(position2->y);
    
    // position2->x = 3;
    // Error: The value of pointer can't be changed
    
    // Because pointer isn't constrain as const, pointer can be changed
    position2 = entity.GetPosition();
}
