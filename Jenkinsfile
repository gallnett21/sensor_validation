pipeline {
    agent any

    environment {
        PATH = "C:\\msys64\\ucrt64\\bin;C:\\Users\\gall2\\AppData\\Local\\Programs\\Python\\Python313;${env.PATH}"
    }

    stages {

        stage('Build') {
            steps {
                bat 'gcc -Wall -Wextra -g main.c sensor.c -o main.exe'
            }
        }

        stage('Test') {
            steps {
                bat 'python tests\\test_sensor.py'
            }
        }

        stage('Publish Test Report') {
            steps {
                junit 'test-results.xml'
            }
        }

        stage('Archive'){
            steps {
                archiveArtifacts artifacts: 'main.exe', fingerprint: true
            }
        }
    }
}