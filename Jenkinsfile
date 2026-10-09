pipeline {
    agent any

    environment {
            PATH = "C:\\msys64\\ucrt64\\bin;C:\\Users\\gall2\\AppData\\Local\\Programs\\Python\\Python313;C:\\Program Files\\Cppcheck;${env.PATH}"
        }


    stages {

        stage('Clean') {
            steps {
                bat '''
                    if exist build rmdir /S /Q build
                    if exist build-coverage rmdir /S /Q build-coverage
                    if exist test-results.xml del /Q test-results.xml
                    if exist sensor.c.gcov del /Q sensor.c.gcov
                    if exist coverage-summary.txt del /Q coverage-summary.txt
                '''
            }
        }

        stage('Configure') {
            steps {
                bat 'cmake -S . -B build'
            }
        }

        stage('Static Analysis') {
            steps {
                bat 'where cppcheck'
                bat 'cppcheck --version'
                bat 'cppcheck --enable=warning,style,performance,portability --std=c11 -Iinclude src tests --error-exitcode=1'
             }
        }

        stage('Build') {
            steps {
                bat 'cmake --build build'
            }
        }

        stage('CTest') {
            steps {
                bat 'ctest --test-dir build --output-on-failure'
            }
        }

        stage('Test Report') {
            steps {
                bat 'python tests\\test_sensor.py'
            }
        }

        stage('Coverage') {
            steps {
                bat 'cmake -S . -B build-coverage -DENABLE_COVERAGE=ON'
                bat 'CMAKE --build build-coverage'
                bat 'ctest --test-dir build-coverage --output-on-failure'
                
                bat 'gcov -b -c build-coverage/CMakeFiles/sensor_tests.dir/src/sensor.c.obj > coverage-summary.txt'
                bat 'type coverage-summary.txt'
                bat 'python tests\\check_coverage.py'
            }
        }

        stage('Archive'){
            steps {
                archiveArtifacts artifacts: 'build/sensor_tests.exe', fingerprint: true
            }
        }
    }
    post {
        always {
            junit testResults: 'test-results.xml',
                allowEmptyResults: true
        }
    }
}