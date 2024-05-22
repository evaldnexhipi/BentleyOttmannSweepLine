#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "SweepLineAlgorithm.h"

/**
 * @brief Generates a random segment with endpoints having random coordinates.
 *
 * This function generates a random segment by creating two points with random coordinates
 * within the range [0, 100) and then forming a segment with these points.
 *
 * @return A randomly generated segment.
 */
Segment generateRandomSegment() {
    Point p1 = {static_cast<double>(rand() % 100), static_cast<double>(rand() % 100)};
    Point p2 = {static_cast<double>(rand() % 100), static_cast<double>(rand() % 100)};
    return {p1, p2};
}

/**
 * @brief Main function to test the Bentley-Ottmann sweep line algorithm.
 *
 * This program generates a specified number of random line segments, finds all intersection
 * points among them using the Bentley-Ottmann sweep line algorithm, and measures the time
 * taken to perform the intersection detection.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments. The second argument should be the number of segments.
 * @return 0 if the program completes successfully, 1 otherwise.
 */
int main(int argc, char* argv[]) {
    // Ensure correct number of command-line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " number_of_segments" << std::endl;
        return 1;
    }

    // Parse the number of segments from command-line arguments
    int numberOfSegments = std::atoi(argv[1]);
    if (numberOfSegments <= 0) {
        std::cerr << "Number of segments must be a positive integer." << std::endl;
        return 1;
    }

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Generate random segments
    std::vector<Segment> segments;
    for (int i = 0; i < numberOfSegments; ++i) {
        segments.push_back(generateRandomSegment());
    }

    // Measure the time taken to find intersections
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> intersections = findIntersections(segments);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Output the results
    std::cout << "Number of segments: " << numberOfSegments << std::endl;
    std::cout << "Number of intersections: " << intersections.size() << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    // Uncomment the following lines to print intersection points
    /*
    for (auto &pt : intersections) {
        std::cout << "Intersection at: (" << pt.m_x << ", " << pt.m_y << ")\n";
    }
    */
    return 0;
}
