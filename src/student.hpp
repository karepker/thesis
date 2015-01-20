#ifndef STUDENT_H
#define STUDENT_H

#include <functional>
#include <iosfwd>

#include <boost/serialization/utility.hpp>


using StudentId = int;
using StudentIdHasher = std::hash<int>;


class Student {
 public:
	Student() : id_{-1} {}
	Student(int id) : id_{id} {}

	int id() const { return id_; }

	bool operator==(const Student& other) const { return id() == other.id(); }
	bool operator!=(const Student& other) const { return !(operator==(other)); }

	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & id_;
	}

 private:
	friend class boost::serialization::access;

	int id_;
};


std::ostream& operator<<(std::ostream& os, const Student& student);


#endif  // STUDENT_H
