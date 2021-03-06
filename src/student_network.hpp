#ifndef STUDENT_NETWORK_H
#define STUDENT_NETWORK_H

#include "course.hpp"
#include "network.hpp"
#include "student.hpp"


class StudentNetwork : public Network<Student::Id, double> {
 public:
	StudentNetwork() {}
	StudentNetwork(std::istream& student_archive) : Network{student_archive} {}
	StudentNetwork(const graph_t& graph) : Network{graph} {}
};


#endif  // STUDENT_NETWORK_H
