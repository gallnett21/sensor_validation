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
                    if exist test-results.xml del /Q test-results.xml
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