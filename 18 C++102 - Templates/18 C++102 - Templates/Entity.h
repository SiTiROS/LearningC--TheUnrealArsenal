#pragma once

template<typename T>
class Entity
{
public:
	Entity(T memberP);

	void setMember(T memberP);

	T getMember() const;

private:
	T member;
};


template<typename T>
Entity<T>::Entity(T memberP) : member(memberP) {}

template<typename T>
void Entity<T>::setMember(T memberP) { member = memberP; }

template<typename T>
T Entity<T>::getMember() const { return member; }