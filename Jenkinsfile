pipeline {
    agent any

    environment {
        PATH = "C:\\msys64\\ucrt64\\bin;C:\\Users\\gall2\\AppData\\Local\\Programs\\Python\\Python313;${env.PATH}"
    }

    stages {

        stage('Configure') {
            steps {
                bat 'cmake -S . -B build'
            }
        }

        stage('Static Analysis') {
            steps {
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

        stage('Archive'){
            steps {
                archiveArtifacts artifacts: 'build/sensor_tests.exe', fingerprint: true
            }
        }
    }
    post {
        always {
            junit 'test-results.xml'
        }
    }
}