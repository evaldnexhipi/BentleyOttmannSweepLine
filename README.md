
# BentleyOttmannSweepLine

This repository contains an implementation of the Bentley-Ottmann sweep line algorithm, used for detecting intersections in a set of line segments.

## Description

### Short Description
The Bentley-OttmannSweepLine repository implements the Bentley-Ottmann sweep line algorithm for detecting intersections among a collection of line segments. This algorithm is efficient and widely used in computational geometry for solving intersection problems.

### Long Description
The Bentley-Ottmann algorithm is a fundamental algorithm in computational geometry, particularly for finding all intersections in a set of line segments. This repository provides a C++ implementation of the algorithm, along with example runs and performance evaluations. The implementation includes essential components such as event handling, segment comparison, and the sweep line mechanism.

## Repository Structure

```
BentleyOttmannSweepLine/
│
├── include/
│   ├── Point.h
│   ├── Segment.h
│   ├── Event.h
│   ├── CompareSegment.h
│   └── SweepLineAlgorithm.h
│
├── src/
│   ├── main.cpp
│   ├── Event.cpp
│   └── SweepLineAlgorithm.cpp
│
├── data
│   ├── output.png
│   ├── output(1).png
│   ├── output(2).png
│   ├── output3).png
├── CMakeLists.txt
├── README.md
```

## How to Execute and Run the Code

### Prerequisites
- C++ compiler (e.g., g++)
- CMake

### Build Instructions
1. Navigate to the root directory of the repository.
2. Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
3. Generate the build files using CMake:
    ```bash
    cmake ..
    ```
4. Compile the project:
    ```bash
    make
    ```

### Running the Code
After building the project, you can run the executable:
```bash
./BentleyOttmannSweepLine numberOfSegments
```

## How to Rerun the Code After Making Changes

1. Make the necessary changes to the source files.
2. Rebuild the project by repeating the steps in the **Build Instructions** section.
3. Do not forget to remove **build** folder in order to recompile the project. Additionally, you can hit **make clean** without removing the build folder.

## How to Cite

If you use this code in your research, please cite it as follows:

```
@misc{Nexhipi2024BentleyOttmannSweepLine,
  author = {Evald Nexhipi},
  title = {BentleyOttmannSweepLine},
  year = {2024},
  publisher = {GitHub},
  howpublished = {\url{https://github.com/evaldnexhipi/BentleyOttmannSweepLine}},
  note = {Research Associate at Technical University of Munich (TUM), Chair of Traffic Engineering and Control, Department of Mobility Systems.},
  email = {evald.nexhipi@tum.de}
}
```

## Contact

For any questions or issues, please contact:
- **Evald Nexhipi**
- Research Associate at Technical University of Munich (TUM), Chair of Traffic Engineering and Control, Department of Mobility Systems
- Email: evald.nexhipi@tum.de

## Performance Evaluation
The following plots summarize the computational efficiency of the implementation:

### Time Complexity of Bentley-Ottmann Algorithm

![Time Complexity](./data/output.png)
This plot shows the relationship between the number of segments and the time taken by the algorithm. Both axes are in logarithmic scale to handle the wide range of values. As the number of segments increases, the time complexity follows a predictable pattern. This is consistent with the expected time complexity of O((N+K)log(N)), where N is the number of segments and K is the number of intersections. The log-log scale plot demonstrates a linear relationship, indicating efficient handling of large datasets of segments.

### Number of Intersections Detected by Bentley-Ottmann Algorithm

![Number of Intersections](./data/output(1).png)
This plot illustrates how the number of intersections detected scales with the number of segments. Both axes are in logarithmic scale. The number of intersections increases rapidly with the number of segments but starts to plateau as the number of segments becomes very large.

### Time vs Number of Intersections in Bentley-Ottmann Algorithm

![Time vs Intersections](./data/output(2).png)
This plot shows the relationship between the number of intersections detected and the time taken by the algorithm. Both axes are in logarithmic scale. As expected, the execution time increases with the number of intersections, reflecting the algorithm's dependence on both the number of segments and the number of intersections.

### Efficiency of Bentley-Ottmann Algorithm

![Efficiency](./data/output(3).png)
The fourth plot presents the efficiency of the algorithm, measured as the number of intersections detected per second, plotted against the number of segments. Initially, the efficiency remains high but begins to decrease as the number of segments increases beyond a certain point. This drop in efficiency at higher segment counts is likely due to the increased computational overhead required to manage a larger number of events and status changes.

In summary, our C++ implementation of the Bentley-Ottmann algorithm performs efficiently across a wide range of input sizes, demonstrating its suitability for large-scale intersection detection problems in computational geometry. The observed performance metrics align well with the theoretical expectations, validating the implementation's correctness and efficiency.
