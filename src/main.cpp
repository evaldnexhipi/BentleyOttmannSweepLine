#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "SweepLineAlgorithm.h"

Segment generateRandomSegment() {
    Point p1 = {static_cast<double>(rand() % 100), static_cast<double>(rand() % 100)};
    Point p2 = {static_cast<double>(rand() % 100), static_cast<double>(rand() % 100)};
    return {p1, p2};
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " number_of_segments" << std::endl;
        return 1;
    }

    int numberOfSegments = std::atoi(argv[1]);
    if (numberOfSegments <= 0) {
        std::cerr << "Number of segments must be a positive integer." << std::endl;
        return 1;
    }

    std::srand(std::time(nullptr)); // Seed for random number generation

    std::vector<Segment> segments;
    for (int i = 0; i < numberOfSegments; ++i) {
        segments.push_back(generateRandomSegment());
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> intersections = findIntersections(segments);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Number of segments: " << numberOfSegments << std::endl;
    std::cout << "Number of intersections: " << intersections.size() << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

/*
    for (auto &pt : intersections) {
        std::cout << "Intersection at: (" << pt.x << ", " << pt.y << ")\n";
    }
*/
    return 0;
}

