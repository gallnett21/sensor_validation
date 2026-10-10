# Sensor Validation Project

This project implements a C module that validates sensor temperature readings and classifies them into different operating states: OFF, OK, WARNING, and ERROR.
It includes automated unit tests, code coverage analysis using gcov, static code analysis with Cppcheck, and a Jenkins CI pipeline that builds, tests, and validates the project through configurable quality gates.

## Prerequisites
Ensure you have the following tools installed and added to your system `PATH`:

- **C Compiler:** GCC (MinGW-w64 on Windows).
- **CMake:** Version 3.20 or higher.
- **Python:** Version 3.x.
- **Git:** For version control.
- **Cppcheck:** For static analysis.
- **Jenkins:** For the CI pipeline.
- **Ninja:** Used as the CMake build generator in this project

## Clone the Repository
```bash
git clone https://github.com/gallnett21/sensor_validation
cd sensor_validation
```

## Build and Test

### Configure the project using CMake:
```bash
cmake -S . -B build
```

### Build the test executable:
```bash
cmake --build build
```

### Run the automated tests using CTest:
```bash
ctest --test-dir build --output-on-failure
```

### Generate the JUnit XML report:
```bash
python tests/test_sensor.py
```

The test suite includes seven temperature boundary cases and five sensor status string cases.

## CI/CD Pipeline

The project uses Jenkins to automate the build and validation process. A GitHub webhook triggers the pipeline when changes are pushed to the repository.

The pipeline includes the following stages:

1. **Clean:** Removes the previous build files and generated report.
2. **Configure:** Configures the project using CMake.
3. **Static Analysis:** Runs Cppcheck to detect potential code issues.
4. **Build:** Compiles the C test executable.
5. **CTest:** Executes the automated C test suite.
6. **Test Report:** Generates a JUinit XML report using Python.
7. **Coverage:** Measures code coverage using gcov and verifies the minimum threshold.
8. **Archive:** Stores the generated executable as a Jenkins build artifact.

The Pipeline fails when a required validation step does not pass.

## Code Coverage and Quality Gates

Code coverage is measured using GCC and gcov.

Latest validated results:
- **JUnit test cases:** 12 passed. 0 failed.
- **Line coverage:** 82.14%
- **Branch coverage:** 100%
- **Coverage quality gate:** PASSED

## Technologies
C, GCC, CMake, CTest, Python, Jenkins, Git, GitHub, Cppcheck and gcov