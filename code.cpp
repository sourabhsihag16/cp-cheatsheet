#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    double grade;
};

// Custom comparator to sort by grade, then by age
bool compareStudents(const Student &a, const Student &b) {
    if (a.grade == b.grade) {
        return a.age < b.age;  // If grades are equal, compare by age
    }
    return a.grade > b.grade;  // Primary sort by grade (descending)
}

int main() {
    std::vector<Student> students = {{"Alice", 20, 90.5}, {"Bob", 22, 90.5}, {"Eve", 21, 85.0}};

    std::sort(students.begin(), students.end(), compareStudents);

    for (const auto &student : students) {
        std::cout << student.name << " " << student.age << " " << student.grade << "\n";
        // Output:
        // Alice 20 90.5
        // Bob 22 90.5
        // Eve 21 85
    }

    return 0;
}
